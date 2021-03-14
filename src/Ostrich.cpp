#include "Engine.hpp"
#include "Ostrich.hpp"
#include "SpriteWithBody.hpp"
#include "World.hpp"
#include <string>

const double WIDTH = 50;
const double HEIGHT = 50;

Ostrich::Ostrich(std::string Image, double x, double y) : SpriteWithBody(Image, x, y, WIDTH, HEIGHT)
{
}

Ostrich::~Ostrich()
{
    body->SetGravityScale(5000);
}

void Ostrich::update(double delta)
{
    SpriteWithBody::update(delta);
    if (position.getX() > 1024 + WIDTH)
    {
        body->SetTransform(b2Vec2((-WIDTH)/M2P,body->GetPosition().y),body->GetAngle());

    } else if(position.getX() < -WIDTH){
        body->SetTransform(b2Vec2((1024+WIDTH)/M2P,body->GetPosition().y),body->GetAngle());
    }

    if(position.getY()< 5){
        body->SetLinearVelocity(b2Vec2(body->GetLinearVelocity().x, 0));
        b2Vec2 force(0, 1.0);
        body->ApplyLinearImpulse(force, body->GetWorldCenter(), true);
    }
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
    b2Vec2 force(0.0, -5.0);
    body->ApplyLinearImpulse(force, body->GetWorldCenter(), true);
}
