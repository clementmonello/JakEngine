#include "RigidBody.h"
#include <iostream>

JakEngine::RigidBody::RigidBody() : JakEngine::AComponent::AComponent()
{
	/*b2BodyDef bodyDef = b2BodyDef();
	bodyDef.position.Set(0, 0);
	bodyDef.angle = 0;
	bodyDef.type = b2BodyType::b2_staticBody;

	body = physic.getWorld().CreateBody(&bodyDef);
	body->ResetMassData();*/
	bodyDef = b2BodyDef();
}

JakEngine::RigidBody::RigidBody(std::string n) : JakEngine::AComponent::AComponent(n)
{
	bodyDef= b2BodyDef();
}

JakEngine::RigidBody::~RigidBody()
{
}


bool JakEngine::RigidBody::createBody(b2World& world, float posx, float posy, float sizex, float sizey, float angle, b2BodyType bodytype, float density, float friction, float restitution)
{
	if (body != nullptr) {
		std::cout << "a body already exists";
		return false;
	}

	bodyDef.position.Set(posx / 30, posy / 30);//does not matter for now
	bodyDef.angle = angle;
	bodyDef.type = bodytype;
	bodyDef.gravityScale = 1.0f;

	body = world.CreateBody(&bodyDef);

	b2PolygonShape polygonShape;
	polygonShape.SetAsBox(sizex/2, sizey/2);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &polygonShape;
	fixtureDef.density = density;
	fixtureDef.friction = friction;
	fixtureDef.restitution = restitution;

	body->CreateFixture(&fixtureDef);
	return true;
}

bool JakEngine::RigidBody::createBody(b2World& world, float posx, float posy, float size, float angle, b2BodyType bodytype, float density, float friction, float restitution)
{
	if (body!=nullptr){
		std::cout << "a body already exists";
		return false;
	}

	bodyDef.position.Set(posx / 30, posy / 30);//does not matter for now
	bodyDef.angle = angle;
	bodyDef.type = bodytype;
	bodyDef.gravityScale = 1.0f;

	body = world.CreateBody(&bodyDef);

	b2CircleShape circleShape;
	circleShape.m_radius = size/2;

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &circleShape;
	fixtureDef.density = density;
	fixtureDef.friction = friction;
	fixtureDef.restitution = restitution;

	body->CreateFixture(&fixtureDef);
	return true;
}
