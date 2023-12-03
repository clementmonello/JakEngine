#include "IGApplication.h"
#include "AEntity.h"
#include <iostream>

IGApplication::IGApplication():JakEngine::Application()
{
	orderFruit = std::vector<Fruit>();
	isHoldingFruit = false;
	countTimer = sf::Time().Zero;
}

IGApplication::~IGApplication()
{      
}

void IGApplication::generateFruit()
{
	if (orderFruit.size() > 0) {
		Fruit fr = orderFruit[0]; //duplication d'un fruit existant, marche peut etre pas
		Fruit* f = &fr;
		f->MoveTo(500, 100);
		for (int i = 0;i < f->listComponent.size();i++) {
			JakEngine::RigidBody* rb = dynamic_cast<JakEngine::RigidBody*>(f->listComponent[i]);
			if (rb != nullptr) {
				rb->createBody(physic->getWorld(), 500, 100, f->size, 0, b2BodyType::b2_staticBody,1,1,1);
				rb->body->GetUserData().pointer = (uintptr_t)this;
			}
		}
		listEntity.push_back(f);
		
		std::cout << "new fruit generated" << std::endl;
	}
	else {
		std::cout << "no fruits to spawn" << std::endl;
	}

}

void IGApplication::Run() {
	sf::Clock deltaClock;
	// Boucle de jeu
	generateFruit();
	while (window->isOpen() and pause == false)
	{
		//temps entre deux frames
		sf::Time dt = deltaClock.restart();

		sf::Event event;
		while (window->pollEvent(event))
		{
			if (input != nullptr) {
				input->Update(event);
			}
			if (event.type == sf::Event::Closed)
				window->close();
		}

		Loop(dt);

		if (countTimer > sf::Time::Zero) {
			countTimer = countTimer - dt;
		}
		if (countTimer <= sf::Time::Zero and isHoldingFruit == false) {
			generateFruit();
		}

		window->clear();
		for (int i = 0;i < listEntity.size();i++) {
			JakEngine::AEntity* currentEntity = listEntity[i];
			window->draw(*currentEntity);
		}

		if (debugdrawing == true) {
			physic->debugDraw(*window);
		}

		window->display();
	}
}

void IGApplication::FuseFruits(Fruit* f1, Fruit* f2)
{
	//je suppose que les fruits ont le meme rang
	
	if (f1->rank >= orderFruit.size()) {
		return;
	}

	//création du nouveau fruit
	Fruit fr = orderFruit[f1->rank]; //duplication d'un fruit existant, marche peut etre pas
	Fruit* f = &fr;
	f1->isHeld = false;
	f1->MoveTo((f1->getPosition().x + f2->getPosition().x) / 2, (f1->getPosition().y + f2->getPosition().y) / 2);

	listEntity.push_back(f);

	//suppression des deux fruits parents dans le moteur physique
	for (int i = 0;i < f1->listComponent.size();i++) {
		JakEngine::RigidBody* rb = dynamic_cast<JakEngine::RigidBody*>(f1->listComponent[i]);
		if (rb != nullptr) {
			physic->getWorld().DestroyBody(rb->body);
		}
	}
	for (int i = 0;i < f2->listComponent.size();i++) {
		JakEngine::RigidBody* rb = dynamic_cast<JakEngine::RigidBody*>(f2->listComponent[i]);
		if (rb != nullptr) {
			physic->getWorld().DestroyBody(rb->body);
		}
	}

	//suppression des deux fruits parents dans le moteur graphique
	int posf1 = 0;
	int posf2 = 0;
	for (int i = 0;i < listEntity.size();i++) {
		if (listEntity[i] == f1) {
			posf1 = i;
		}
		else if (listEntity[i] == f2) {
			posf2 = i;
		}
	}

	if (posf1 > posf2) {
		listEntity.erase(listEntity.begin() + posf1);
		listEntity.erase(listEntity.begin() + posf2);
	}
	else {
		listEntity.erase(listEntity.begin() + posf2);
		listEntity.erase(listEntity.begin() + posf1);
	}
	
}
