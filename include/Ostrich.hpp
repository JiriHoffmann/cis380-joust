#ifndef __HPP__OSTRICH__
#define __HPP__OSTRICH__

#include "SpriteWithBody.hpp"
#include "Interfaces.hpp"
#include "Utility.hpp"
#include "World.hpp"
#include <string>

class Ostrich : public SpriteWithBody
{
public:
    Ostrich(std::string path, double x, double y, std::string type);
    ~Ostrich();
    void update(double delta);
    void draw();
    void left();
    void right();
    void up();
    void takeHit(bool isOnTop);
};

#endif
