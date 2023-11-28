#pragma once
#include "AEntity.h"
#include "Physics.h"
#include <box2d/box2d.h>

namespace JakEngine {
	class Application
	{
	public:
		std::vector<AEntity*> listEntity;
		sf::RenderWindow* window;
		static JakEngine::Application* instance;
		JakEngine::Physics* physic;
		float time;

		Application();
		~Application();

		void Init(int windowSizeX, int windowSizeY, std::string windowName);
		void Loop(sf::Time t);
		void Run();
		void CreateEntity(std::string name);
		AEntity* GetEntity(std::string name);
		void updatePhysic(float t);


		static Application* GetInstance();
	};
}