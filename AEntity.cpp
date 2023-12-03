#include "pch.h"
#include "AEntity.h"
#include <vector>
#include "VisualComponent.h"
#include "AComponent.h"
#include <iostream>
#include <sstream>
#include "CameraComponent.h"
#include "RigidBody.h"

int JakEngine::AEntity::nbID = 0;

JakEngine::AEntity::AEntity()
{
	nbID++;
	ID = nbID;
	name = "DefaultName";
	listComponent = std::vector<AComponent*>();
	isColliding = false;
}

JakEngine::AEntity::AEntity(std::string n)
{
	nbID++;
	ID = nbID;
	name = n;
	isColliding = false;
	listComponent = std::vector<AComponent*>();
}

JakEngine::AEntity::~AEntity()
{
}

void JakEngine::AEntity::Awake()
{
}

void JakEngine::AEntity::Start()
{
	
}

void JakEngine::AEntity::Update(sf::Time t)
{
	for (int i = 0;i < listComponent.size();i++) {
		listComponent[i]->Update(t);
	}
}

void JakEngine::AEntity::LateUpdate(sf::Time t)
{
	for (int i = 0;i < listComponent.size();i++) {
		listComponent[i]->LateUpdate(t);
	}
}

void JakEngine::AEntity::FixedUpdate(sf::Time t)
{
	for (int i = 0;i < listComponent.size();i++) {
		listComponent[i]->LateUpdate(t);
	}
}

int JakEngine::AEntity::GetID()
{
	return ID;
}

void JakEngine::AEntity::AttachComponent(AComponent *c)
{
	listComponent.push_back(c);
}

void JakEngine::AEntity::RemoveComponent(int id)
{
	for (int i = 0;i < listComponent.size();i++) {
		if (listComponent[i]->ID == id) {
			listComponent.erase(listComponent.begin()+i);
		}
	}
}

void JakEngine::AEntity::MoveTo(float x, float y) 
{
	this->setPosition(x, y);
}

void JakEngine::AEntity::Push(float x, float y)
{
	this->move(x, y);
}

void JakEngine::AEntity::OnCollisionEnter()
{
	std::cout << name << " colliding !" << std::endl;
}

void JakEngine::AEntity::OnCollisionExit()
{
	std::cout << name << " stopped colliding !" << std::endl;
}

void JakEngine::AEntity::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	states.transform = getTransform();
	for (int i = 0;i < listComponent.size();i++) {

		AComponent* CompPointer = listComponent[i];
		VisualComponent* vcomp = dynamic_cast<VisualComponent*>(CompPointer);
		if (vcomp != nullptr) {

			//std::cout <<"drawing visual";

			vcomp->forme.shape->setPosition(vcomp->forme.position.x, vcomp->forme.position.y);
			sf::Shape* currentShape = vcomp->forme.shape;
			target.draw(*currentShape, states);
			break;
		}
	}
}
