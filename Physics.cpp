#include "Physics.h"
#include "RigidBody.h"
#include "Application.h"
#include "DebugDraw.h"
#include <box2d/box2d.h>

const float JakEngine::Physics::worldScale = 1.f;

JakEngine::Physics::Physics():gravity(0.f, 0.f), world(gravity)
{
	listBody = std::vector<RigidBody*>();
	debugdraw = nullptr;
}

JakEngine::Physics::Physics(b2Vec2 g):gravity(g), world(gravity)
{
	listBody = std::vector<RigidBody*>();
	debugdraw = nullptr;
}

void JakEngine::Physics::Update(sf::Time t)
{
	
}

b2Vec2& JakEngine::Physics::getGravity()
{
	return gravity;
}

void JakEngine::Physics::setGravity(float gRight, float gUp)
{
	gravity.x = gRight;
	gravity.y = gUp;
	world.SetGravity(gravity);
}

b2World& JakEngine::Physics::getWorld()
{
	return world;
}

void JakEngine::Physics::debugDraw(sf::RenderWindow& window)
{
	if (!debugdraw) {
		debugdraw = new DebugDraw(window);
		debugdraw->SetFlags(b2Draw::e_shapeBit);
		world.SetDebugDraw(debugdraw);
	}

	world.DebugDraw();
}

void JakEngine::Physics::createBody(RigidBody* rb, float posx, float posy, float sizex, float sizey, float angle, b2BodyType bodytype, float density, float friction, float restitution) {

	bool res=rb->createBody(world, posx, posy,sizex,sizey, angle, bodytype, density, friction, restitution);

	if (res==true){
		listBody.push_back(rb);
	}
}
void JakEngine::Physics::createBody(RigidBody* rb, float posx, float posy,float radius, float angle, b2BodyType bodytype, float density, float friction, float restitution) {

	bool res=rb->createBody(world, posx, posy,radius, angle, bodytype, density, friction, restitution);

	if (res == true) {
		listBody.push_back(rb);
	}
}