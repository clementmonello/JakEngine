#pragma once
#include "Application.h"
#include "Fruit.h"

class Fruit;

class IGApplication:public JakEngine::Application
{
public:
	std::vector<Fruit> orderFruit;
	bool isHoldingFruit;
	sf::Time countTimer;

	IGApplication();
	~IGApplication();

	void Run();
	void generateFruit();
	void FuseFruits(Fruit* f1, Fruit* f2);
};
