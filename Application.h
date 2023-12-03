#pragma once
#include "AEntity.h"
#include "Physics.h"
#include <box2d/box2d.h>
#include "DebugDraw.h"
#include "Input.h"

namespace JakEngine {
	//class Input;

	class Application
	{
	public:
		std::vector<AEntity*> listEntity;
		sf::RenderWindow* window;
		static JakEngine::Application* instance;
		JakEngine::Physics* physic;
		float time;
		bool debugdrawing;
		bool pause;
		Input* input;

		Application();
		~Application();

		virtual void Init(int windowSizeX, int windowSizeY, std::string windowName);
		virtual void Loop(sf::Time t);
		virtual void Run();
		virtual void CreateEntity(std::string name);
		virtual AEntity* GetEntity(std::string name);
		virtual void updatePhysic(sf::Time t);
		virtual void debugDrawOn();
		virtual void debugDrawOff();
		virtual void Pause();

		static Application* GetInstance();
	};
}