#include "Engine.hpp"
#include "Ostrich.hpp"
#include "SpriteWithBody.hpp"
#include "World.hpp"
#include <string>


Ostrich::Ostrich(std::string Image, double x, double y): SpriteWithBody(Image, x, y){
}

Ostrich::~Ostrich()
{
    
}

void Ostrich::update(double delta)
{
    SpriteWithBody::update(delta);
}

void Ostrich::draw()
{
    Sprite::draw();
}


void Ostrich::left(double delta)
{
    b2Vec2 force(-5.0, 1.0);
    body->ApplyLinearImpulse(force, body->GetWorldCenter(), true);
}

void Ostrich::right(double delta)
{
    b2Vec2 force(5.0, 1.0);
    body->ApplyLinearImpulse(force, body->GetWorldCenter(), true);
}

void Ostrich::up(double delta)
{
    b2Vec2 force(0.0, -20.0);
    body->ApplyLinearImpulse(force, body->GetWorldCenter(), true);
}

