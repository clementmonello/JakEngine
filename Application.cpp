#include "pch.h"
#include "Application.h"
#include "CameraComponent.h"
#include "AEntity.h"
#include <iostream>
#include <sstream>
#include <string>

JakEngine::Application* JakEngine::Application::instance = nullptr;

JakEngine::Application::Application()
{
	time = 0;
	listEntity = std::vector<AEntity*>();
	std::cout << "hello world";
	instance = this;
	physic = new Physics();
}

JakEngine::Application::~Application()
{
	time = 0;
	std::cout << "bye world";
	delete physic;
}

void JakEngine::Application::Init(int windowSizeX, int windowSizeY, std::string windowName)
{
	window=new sf::RenderWindow(sf::VideoMode(windowSizeX, windowSizeY), windowName);
}

void JakEngine::Application::Loop(sf::Time t)
{
	/*tests de cameras -- concluants
	time = time + t.asSeconds();
	if (time >= 1) {
		time = 0;
		JakEngine::CameraComponent* cameracomp1 = dynamic_cast<JakEngine::CameraComponent*>(listEntity[5]->listComponent[0]);
		JakEngine::CameraComponent* cameracomp2 = dynamic_cast<JakEngine::CameraComponent*>(listEntity[6]->listComponent[0]);
		if (cameracomp1->isActive == true) {
			window->setView(cameracomp2->view);
			cameracomp1->isActive = false;
			cameracomp2->isActive = true;
		}
		else {
			window->setView(cameracomp1->view);
			cameracomp1->isActive = true;
			cameracomp2->isActive = false;
		}
	}*/

	for (int i = 0;i < listEntity.size();i++) {
		listEntity[i]->FixedUpdate(t);
	}
	for (int i = 0;i < listEntity.size();i++) {
		listEntity[i]->Update(t);
	}
	physic->Update(t);
	for (int i = 0;i < listEntity.size();i++) {
		listEntity[i]->LateUpdate(t);
	}
}

void JakEngine::Application::Run() {
	sf::Clock deltaClock;

	// Boucle de jeu
	while (window->isOpen())
	{
		//temps entre deux frames
		sf::Time dt = deltaClock.restart();

		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		Loop(dt);

		//window->clear();
		for (int i = 0;i < listEntity.size();i++) {
			AEntity* currentEntity = listEntity[i];
			window->draw(*currentEntity);
		}
		window->display();
	}
}

void JakEngine::Application::CreateEntity(std::string name)
{
	AEntity* entity = new AEntity(name);
	listEntity.push_back(entity);
}

JakEngine::AEntity* JakEngine::Application::GetEntity(std::string n)
{
	for (int i = 0;i < listEntity.size();i++) {
		if (listEntity[i]->name.compare(n)) {
			return listEntity[i];
		}
	}
	return nullptr;
}

void JakEngine::Application::updatePhysic(float t)
{
	int velocityinteration = 6;
	int positioninteration = 2;
	physic->getWorld().Step(t, velocityinteration, positioninteration);

	for (int i = 0;i < listEntity.size();i++) {
		for (int j = 0;j < listEntity[i]->listComponent.size();j++) {
			RigidBody* rb = dynamic_cast<RigidBody*>(listEntity[i]->listComponent[j]);
			if (rb != nullptr) {
				rb->body->SetTransform(b2Vec2(listEntity[i]->getPosition().x, listEntity[i]->getPosition().y), listEntity[i]->getRotation());
				listEntity[i]->setPosition(rb->body->GetPosition().x, rb->body->GetPosition().y);
			}
		}
	}
}

JakEngine::Application* JakEngine::Application::GetInstance()
{
	if (instance == nullptr) {
		instance = new Application();
	}
	return instance;
}
