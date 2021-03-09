#ifndef __HPP_WORLD__
#define __HPP_WORLD__

#include "Engine.hpp"
#include "Interfaces.hpp"
#include "World.hpp"
#include "SpriteWithBody.hpp"
#include <SDL2/SDL.h>
#include <Box2D/Box2D.h>

class World : public UGameObject
{

public:
    World(b2Vec2 gravity);
    ~World();
    void update(double delta);
    void addRect(SpriteWithBody* object, bool dynamic);

private:
    b2World *world;

    friend class Engine;
};

#endif
