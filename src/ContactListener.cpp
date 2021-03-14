#include "ContactListener.hpp"
#include <SDL2/SDL.h>

ContactListener::ContactListener() {
}

void ContactListener::BeginContact(b2Contact* contact){
	SDL_Log("collision");
}

