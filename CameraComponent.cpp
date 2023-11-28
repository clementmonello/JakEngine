#include "CameraComponent.h"
#include <SFML/Graphics.hpp>

JakEngine::CameraComponent::CameraComponent():JakEngine::AComponent::AComponent()
{
	isActive = false;
}

JakEngine::CameraComponent::CameraComponent(std::string n) : JakEngine::AComponent::AComponent(n)
{
	isActive = false;
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

void JakEngine::CameraComponent::SetView(sf::View v)
{
	view = v;
}
