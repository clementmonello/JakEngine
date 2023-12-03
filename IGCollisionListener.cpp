#include "IGCollisionListener.h"
#include "Fruit.h"

IGCollisionListener::IGCollisionListener(): JakEngine::CollisionListener()
{
}

IGCollisionListener::~IGCollisionListener()
{
}

void IGCollisionListener::BeginContact(b2Contact* contact)
{
	b2BodyUserData bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
	Fruit* myEntity1 = reinterpret_cast<Fruit*>(bodyUserData.pointer);

	b2BodyUserData bodyUserData2 = contact->GetFixtureB()->GetBody()->GetUserData();
	Fruit* myEntity2 = reinterpret_cast<Fruit*>(bodyUserData2.pointer);

	if (myEntity1 != nullptr and myEntity2 != nullptr) {
		if (myEntity1->rank == myEntity2->rank) {
			JakEngine::Application* app=JakEngine::Application::GetInstance();
			IGApplication* currApp = dynamic_cast<IGApplication*>(app);
			if (currApp != nullptr) {
				currApp->FuseFruits(myEntity1, myEntity2);
			}
		}
	}
}

void IGCollisionListener::EndContact(b2Contact* contact)
{
}
