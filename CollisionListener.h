#pragma once
#include <box2d/box2d.h>
namespace JakEngine {
	class CollisionListener:public b2ContactListener
	{
	public:
		CollisionListener();
		~CollisionListener();

		// Called when two fixtures begin to touch
		virtual void BeginContact(b2Contact* contact);

		// Called when two fixtures cease to touch
		virtual void EndContact(b2Contact* contact);
	};
}


