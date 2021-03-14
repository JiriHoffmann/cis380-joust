#include "Interfaces.hpp"
#include "World.hpp"
#include "SpriteWithBody.hpp"
#include <SDL2/SDL.h>
#include <Box2D/Box2D.h>
#include "ContactListener.hpp"


World::World(b2Vec2 gravity)
{
    SDL_Log("Creating world...");
    world = new b2World(gravity);
    world->SetContactListener(new ContactListener());
    SDL_Log("Created with requested gravity.");
}

World::~World()
{
    delete world;
}

void World::update(double delta)
{
    world->Step(1.0/60.0,8,3); 
}

void World::addRect(SpriteWithBody* object, bool dynamic){
    b2BodyDef bodydef;
    bodydef.position.Set((object->position.getX() + object->rect->w/2)/ M2P , (object->position.getY()+object->rect->h/2)/ M2P);
    bodydef.allowSleep = !dynamic;
    bodydef.type = dynamic ? b2_dynamicBody : b2_staticBody;
    bodydef.fixedRotation = true;
	bodydef.angle = 0;
    b2Body *body = world->CreateBody(&bodydef);

    b2PolygonShape shape;
    shape.SetAsBox( (object->rect->w / 2) / M2P, (object->rect->h / 2) / M2P);

    b2FixtureDef fixturedef;
    fixturedef.shape = &shape;
    fixturedef.density = 1;
    body->CreateFixture(&fixturedef);
    object->setBody(body);
}