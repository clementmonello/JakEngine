#include "pch.h"
#include "AComponent.h"
#include <string>
#include "structure.h"

int JakEngine::AComponent::nbID = 0;

JakEngine::AComponent::AComponent()
{
	nbID++;
	ID = nbID;
	name = "DefaultName";
}

JakEngine::AComponent::AComponent(std::string n)
{
	nbID++;
	ID = nbID;
	name = n;
}


JakEngine::AComponent::~AComponent(){}

void JakEngine::AComponent::Awake()
{
}

void JakEngine::AComponent::Start()
{
}

void JakEngine::AComponent::Update(sf::Time t)
{
}

void JakEngine::AComponent::LateUpdate(sf::Time t)
{
}

void JakEngine::AComponent::FixedUpdate(sf::Time t)
{
}

float* JakEngine::AComponent::OnCollisionEnter()
{
	return nullptr;
}

int JakEngine::AComponent::GetID() 
{
	return ID;
}


