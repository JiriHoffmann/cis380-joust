#ifndef			__HPP__BANANA__
#define			__HPP__BANANA__

#include "Sprite.hpp"
#include "Ostrich.hpp"
#include "Interfaces.hpp"
#include "Utility.hpp"
#include <Box2D/Box2D.h>
#include <string>

class PlayerOstrich : public Ostrich
{
public:
    PlayerOstrich(std::string path, double x, double y);
    ~PlayerOstrich();
    void update(double delta);
    void draw();
    void takeHit(bool isOnTop);
};

#endif
