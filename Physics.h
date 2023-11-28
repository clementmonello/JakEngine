#pragma once
#include "RigidBody.h"
#include <box2d/box2d.h>
#include <vector>

namespace JakEngine {
	class Physics
	{
	protected:
		b2Vec2 gravity;
		b2World world;
		std::vector<JakEngine::RigidBody*> listBody;
		const static float worldScale;
	public:
		Physics();
		Physics(b2Vec2 g);
		virtual b2Vec2& getGravity();
		virtual b2World& getWorld();
		virtual void Update(sf::Time t);
		virtual void createBody(RigidBody* rb, float posx, float posy, float angle, b2BodyType bodytype, float density, float friction, float restitution);
	};
}