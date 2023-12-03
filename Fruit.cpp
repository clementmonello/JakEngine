#include "Fruit.h"
#include <iostream>
#include "VisualComponent.h"
#include "RigidBody.h"

Fruit::Fruit() :JakEngine::AEntity()
{
	name = "defaultFruit";
	rank = 1;
	isHeld = false;
	size = 100.0f;
	color = sf::Color::White;
}

Fruit::Fruit(int r, float s, sf::Color c, JakEngine::Physics* p) : JakEngine::AEntity()
{
	if (r < 1) {
		rank = 1;
		std::cout << "rang du fruit < 1" << std::endl;
	}
	else {
		rank = r;
	}

	size = s;
	isHeld = false;
	name = "FruitRank"+ std::to_string(rank);

	CreateAComponent<JakEngine::VisualComponent>("circlecomponent");
	JakEngine::VisualComponent* circlecomp = dynamic_cast<JakEngine::VisualComponent*>(listComponent[0]);
	sf::CircleShape* shape = new sf::CircleShape(size / 2);
	shape->setFillColor(c);
	shape->setOrigin(sf::Vector2f(size / 2, size / 2));
	circlecomp->setShape(shape);
	CreateAComponent<JakEngine::RigidBody>("rigidbody");
}

Fruit::~Fruit()
{
}

//Fruit* Fruit::fruitByFusion(Fruit* f1, Fruit* f2) {
//	//je suppose que les fruits ont le meme rang
//	Fruit* f = new Fruit();
//	f->rank = f1->rank + 1;
//	f1->isHeld = false;
//	f1->MoveTo((f1->getPosition().x + f2->getPosition().x) / 2, (f1->getPosition().y + f2->getPosition().y) / 2);f1.
//	return f;
//}