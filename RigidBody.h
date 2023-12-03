#pragma once
#include <string>
#include "AComponent.h"
#include <box2d/box2d.h>

namespace JakEngine {
	class RigidBody : public JakEngine::AComponent{
		public:
			b2BodyDef bodyDef;
			b2Body* body;

			RigidBody();
			RigidBody(std::string n);
			~RigidBody();
			
			bool createBody(b2World& world, float posx, float posy, float sizex, float sizey, float angle, b2BodyType bodytype, float density, float friction, float restitution);
			bool createBody(b2World& world, float posx, float posy,float size, float angle, b2BodyType bodytype, float density, float friction, float restitution);
	};
}