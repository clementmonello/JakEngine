#pragma once
#include "AEntity.h"
#include "Physics.h"


	class Fruit: public JakEngine::AEntity
	{
	public:
		int rank;
		bool isHeld;
		float size;
		sf::Color color;

		Fruit();
		Fruit(int rank,float size, sf::Color c, JakEngine::Physics* p);
		~Fruit();

		//static Fruit* fruitByFusion(Fruit* e1, Fruit* e2);
	};
