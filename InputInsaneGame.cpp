#include "InputInsaneGame.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "IGApplication.h"

InputInsaneGame::InputInsaneGame() : JakEngine::Input::Input()
{
	moveLeft = sf::Keyboard::Key::Q;
	moveRight = sf::Keyboard::Key::D;
	drop = sf::Keyboard::Key::Space;
	pause = sf::Keyboard::Key::Escape;
	application = JakEngine::Application::GetInstance();
	controlledEntity = nullptr;
}

InputInsaneGame::~InputInsaneGame()
{
}

void InputInsaneGame::setApp(JakEngine::Application* app)
{
	application = app;
}

void InputInsaneGame::Update(sf::Event e)
{
	if (e.type == sf::Event::KeyPressed and e.key.code == pause)
	{
		std::cout << "pause" << std::endl;
		application->Pause();
	}
	else if (e.type == sf::Event::KeyPressed and e.key.code == moveLeft and controlledEntity!=nullptr) 
	{
		std::cout<<"left" << std::endl;
		controlledEntity->move(sf::Vector2f(-0.1f, 0.0f));
	}
	else if (e.type == sf::Event::KeyPressed and e.key.code == moveRight and controlledEntity != nullptr)
	{
		std::cout << "right" << std::endl;
		controlledEntity->move(sf::Vector2f(0.1f, 0.0f));
	}
	else if (e.type == sf::Event::KeyPressed and e.key.code == drop and controlledEntity != nullptr)
	{
		std::cout << "drop" << std::endl;
		for (int i = 0;i < controlledEntity->listComponent.size();i++) {
			JakEngine::RigidBody* rb = dynamic_cast<JakEngine::RigidBody*>(controlledEntity->listComponent[i]);
			if (rb != nullptr) {
				rb->body->SetType(b2BodyType::b2_dynamicBody);
			}
		}
		controlledEntity = nullptr;
		IGApplication* igapp = dynamic_cast<IGApplication*>(application);
		if (igapp != nullptr) {
			igapp->isHoldingFruit = false;
			igapp->countTimer = sf::seconds(10.0f);
		}
	}
}
