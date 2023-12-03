#include "CollisionListener.h"
#include "AEntity.h"

void BeginContact(b2Contact* contact) {

    //check if fixture A was a ball
    b2BodyUserData bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
    JakEngine::AEntity* myEntity = reinterpret_cast<JakEngine::AEntity*>(bodyUserData.pointer);
    if (myEntity!=nullptr) {
        myEntity->OnCollisionEnter();
    }

    //check if fixture B was a ball
    bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
    myEntity = reinterpret_cast<JakEngine::AEntity*>(bodyUserData.pointer);
    if (myEntity != nullptr) {
        myEntity->OnCollisionEnter();
    }

}

void EndContact(b2Contact* contact) {

    //check if fixture A was a ball
    b2BodyUserData bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
    JakEngine::AEntity* myEntity = reinterpret_cast<JakEngine::AEntity*>(bodyUserData.pointer);
    if (myEntity != nullptr) {
        myEntity->OnCollisionExit();
    }

    //check if fixture B was a ball
    bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
    myEntity = reinterpret_cast<JakEngine::AEntity*>(bodyUserData.pointer);
    if (myEntity != nullptr) {
        myEntity->OnCollisionExit();
    }
}

JakEngine::CollisionListener::~CollisionListener()
{
}

JakEngine::CollisionListener::CollisionListener(): b2ContactListener()
{
}
