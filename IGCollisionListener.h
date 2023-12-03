#pragma once
#include "CollisionListener.h"
#include "IGApplication.h"

class IGApplication;

class IGCollisionListener:public JakEngine::CollisionListener
{
public:
	IGCollisionListener();
	~IGCollisionListener();

	// Called when two fixtures begin to touch
	void BeginContact(b2Contact* contact);

	// Called when two fixtures cease to touch
	void EndContact(b2Contact* contact);
};

