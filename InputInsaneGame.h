#pragma once
#include "Input.h"
#include <SFML/Graphics.hpp>
#include "Application.h"
#include "Fruit.h"

class Application;
class InputInsaneGame : public JakEngine::Input
{
public:
	sf::Keyboard::Key moveLeft;
	sf::Keyboard::Key moveRight;
	sf::Keyboard::Key drop;
	sf::Keyboard::Key pause;
	JakEngine::Application* application;
	Fruit* controlledEntity;

	InputInsaneGame();
	~InputInsaneGame();
	void setApp(JakEngine::Application* app);

	void Update(sf::Event e);
};


