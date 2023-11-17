#include "pch.h"
#include "Application.h"
#include "AEntity.h"
#include <iostream>
#include <sstream>
#include <string>

JakEngine::Application* JakEngine::Application::instance = nullptr;

JakEngine::Application::Application()
{
	listEntity = std::vector<AEntity*>();
	std::cout << "ello world";
}

JakEngine::Application::~Application()
{
	std::cout << "bye world";
}

void JakEngine::Application::Init(int windowSizeX, int windowSizeY, std::string windowName)
{
	window->create(sf::VideoMode(windowSizeX, windowSizeY), windowName);
}

void JakEngine::Application::Loop(sf::Time t)
{
	for (int i = 0;i < listEntity.size();i++) {
		listEntity[i]->FixedUpdate(t);
	}
	for (int i = 0;i < listEntity.size();i++) {
		listEntity[i]->Update(t);
	}
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

		window->clear();
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		Loop(dt);
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

JakEngine::Application* JakEngine::Application::GetInstance()
{
	if (instance == nullptr) {
		instance = new Application();
	}
	return instance;
}
