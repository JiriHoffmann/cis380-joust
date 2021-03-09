#include "Interfaces.hpp"
#include "World.hpp"
#include "SpriteWithBody.hpp"
#include <SDL2/SDL.h>
#include <Box2D/Box2D.h>

// Meters to pixels 
const float M2P = 20;
const float P2M = 1 / M2P;

World::World(b2Vec2 gravity)
{
    SDL_Log("Creating world...");
    world = new b2World(gravity);
    SDL_Log("Created with requested gravity.");
}

World::~World()
{
    delete world;
}

void World::update(double delta)
{
    world->Step(1.0/30.0,8,3); 

}

void World::addRect(SpriteWithBody* object, bool dynamic){
    b2BodyDef bodydef;
    bodydef.position.Set(object->position.getX() * P2M, object->position.getY() * P2M);
    bodydef.allowSleep = !dynamic;
    bodydef.type = dynamic ? b2_dynamicBody : b2_staticBody;
    b2Body *body = world->CreateBody(&bodydef);

    b2PolygonShape shape;
    shape.SetAsBox(P2M * object->rect->h / 2, P2M * object->rect->w / 2);

    b2FixtureDef fixturedef;
    fixturedef.shape = &shape;
    fixturedef.density = 0.1;
    body->CreateFixture(&fixturedef);
    object->setBody(body);
}