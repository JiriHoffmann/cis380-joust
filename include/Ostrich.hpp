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
    Ostrich(std::string path, double x, double y);
    ~Ostrich();
    void update(double delta);
    void draw();
    void left(double delta);
    void right(double delta);
    void up(double delta);

};

#endif
