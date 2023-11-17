#pragma once
#include "AEntity.h"
namespace JakEngine {
	class Application
	{
	public:
		std::vector<AEntity*> listEntity;
		sf::RenderWindow* window;
		static JakEngine::Application* instance;

		Application();
		~Application();

		void Init(int windowSizeX, int windowSizeY, std::string windowName);
		void Loop(sf::Time t);
		void Run();
		void CreateEntity(std::string name);
		AEntity* GetEntity(std::string name);

		static Application* GetInstance();
	};
}