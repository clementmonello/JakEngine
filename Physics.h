#pragma once
#include "RigidBody.h"
#include <box2d/box2d.h>
#include "DebugDraw.h"
#include <vector>

namespace JakEngine {
	class Physics
	{
	protected:
		b2Vec2 gravity;
		b2World world;
		std::vector<JakEngine::RigidBody*> listBody;
		const static float worldScale;
		DebugDraw* debugdraw;

	public:
		Physics();
		Physics(b2Vec2 g);
		virtual b2Vec2& getGravity();
		virtual void setGravity(float gRight, float gUp);
		virtual b2World& getWorld();
		virtual void Update(sf::Time t);
		virtual void createBody(RigidBody* rb, float posx, float posy, float sizex, float sizey, float angle, b2BodyType bodytype, float density, float friction, float restitution);
		virtual void createBody(RigidBody* rb, float posx, float posy,float radius, float angle, b2BodyType bodytype, float density, float friction, float restitution);
		virtual void debugDraw(sf::RenderWindow& window);
	};
}