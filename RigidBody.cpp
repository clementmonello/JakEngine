#include "RigidBody.h"

JakEngine::RigidBody::RigidBody()
{
	/*b2BodyDef bodyDef = b2BodyDef();
	bodyDef.position.Set(0, 0);
	bodyDef.angle = 0;
	bodyDef.type = b2BodyType::b2_staticBody;

	body = physic.getWorld().CreateBody(&bodyDef);
	body->ResetMassData();*/
}

JakEngine::RigidBody::RigidBody(std::string n) : JakEngine::AComponent::AComponent(n)
{
}

JakEngine::RigidBody::~RigidBody()
{
}


void JakEngine::RigidBody::createBody(b2World& world, float posx, float posy, float angle, b2BodyType bodytype, float density, float friction, float restitution)
{
	bodyDef = b2BodyDef();
	bodyDef.position.Set(posx, posy);
	bodyDef.angle = angle;
	bodyDef.type = b2BodyType::b2_staticBody;

	body = world.CreateBody(&bodyDef);

	b2PolygonShape polygonShape;
	polygonShape.SetAsBox(posx, posy);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &polygonShape;
	fixtureDef.density = density;
	fixtureDef.friction = friction;
	fixtureDef.restitution = restitution;

	body->CreateFixture(&fixtureDef);
	body->ResetMassData();
}
