#include "Engine.hpp"
#include "Ostrich.hpp"
#include "PlayerOstrich.hpp"
#include "SpriteWithBody.hpp"
#include "World.hpp"
#include <string>

PlayerOstrich::PlayerOstrich(std::string Image, double x, double y) : Ostrich(Image, x, y, "player")
{

}

PlayerOstrich::~PlayerOstrich()
{
   
}

void PlayerOstrich::update(double delta)
{
    Ostrich::update(delta);
    const Uint8 *keyboardstate = SDL_GetKeyboardState(NULL);
	if(keyboardstate[SDL_SCANCODE_W]){
		up();
	}
	if(keyboardstate[SDL_SCANCODE_A]){
		left();
	}
	if(keyboardstate[SDL_SCANCODE_D]){
		right();
	}
}

void PlayerOstrich::draw()
{
    Ostrich::draw();
}

void PlayerOstrich::takeHit(bool isOnTop){
    SDL_Log("player took hit, is on top: %d", isOnTop? 1 : 0 );
}
