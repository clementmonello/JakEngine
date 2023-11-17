#include "CameraComponent.h"
#include <SFML/Graphics.hpp>

JakEngine::CameraComponent::CameraComponent():JakEngine::AComponent::AComponent()
{
	window = nullptr;
}

JakEngine::CameraComponent::CameraComponent(std::string n,sf::RenderWindow* w):JakEngine::AComponent::AComponent(n)
{
	window = w;
}

JakEngine::CameraComponent::~CameraComponent()
{
}

void JakEngine::CameraComponent::Awake()
{
}

void JakEngine::CameraComponent::Start()
{
}

void JakEngine::CameraComponent::Update(sf::Time t)
{

}

void JakEngine::CameraComponent::LateUpdate(sf::Time t)
{
}

void JakEngine::CameraComponent::FixedUpdate(sf::Time t)
{
}

float* JakEngine::CameraComponent::OnCollisionEnter()
{
	return nullptr;
}

int JakEngine::CameraComponent::GetID()
{
	return ID;
}

void JakEngine::CameraComponent::SetWindow(sf::RenderWindow* w)
{
	window = w;
	view = window->getDefaultView();
}
