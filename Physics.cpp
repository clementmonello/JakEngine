#include "Physics.h"
#include "RigidBody.h"
#include "Application.h"
#include <box2d/box2d.h>

const float JakEngine::Physics::worldScale = 1.f;

JakEngine::Physics::Physics():gravity(0.f, 0.f), world(gravity)
{
	listBody = std::vector<RigidBody*>();
}

JakEngine::Physics::Physics(b2Vec2 g):gravity(g), world(gravity)
{
	listBody = std::vector<RigidBody*>();
}

void JakEngine::Physics::Update(sf::Time t)
{
	
}

b2Vec2& JakEngine::Physics::getGravity()
{
	return gravity;
}

b2World& JakEngine::Physics::getWorld()
{
	return world;
}

void JakEngine::Physics::createBody(RigidBody* rb,float posx, float posy, float angle,b2BodyType bodytype, float density, float friction, float restitution) {

	rb->createBody(world, posx, posy, angle, bodytype, density, friction, restitution);

	listBody.push_back(rb);
}