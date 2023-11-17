#include "structure.h"
#include "AComponent.h"
#include "VisualComponent.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

JakEngine::VisualComponent::VisualComponent() :JakEngine::AComponent::AComponent()
{
	std::cout << "Visual Component 1";
	forme.position;
}

JakEngine::VisualComponent::VisualComponent(std::string n) :JakEngine::AComponent::AComponent(n)
{
	std::cout << "Visual Component 2";
	forme.shape=new sf::CircleShape();
	forme.shape->setFillColor(sf::Color(255,255,255));
	forme.shape->setScale(1, 1);
	forme.position = sf::Vector2f(0, 0);
}

JakEngine::VisualComponent::~VisualComponent()
{
}

void JakEngine::VisualComponent::setDefaultParameters(sf::Shape* s, sf::Color c, float i, float j)
{
	forme.shape = s;
	forme.shape->setFillColor(c);
	forme.position = sf::Vector2f(i, j);
}

void JakEngine::VisualComponent::Awake()
{
}

void JakEngine::VisualComponent::Start()
{
}

void JakEngine::VisualComponent::Update(sf::Time t)
{
}

void JakEngine::VisualComponent::LateUpdate(sf::Time t)
{
}

void JakEngine::VisualComponent::FixedUpdate(sf::Time t)
{
}

float* JakEngine::VisualComponent::OnCollisionEnter()
{
	return nullptr;
}

int JakEngine::VisualComponent::GetID()
{
	return ID;
}
