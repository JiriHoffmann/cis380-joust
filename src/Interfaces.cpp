#include "Interfaces.hpp"
#include <SDL2/SDL.h>

Drawable::Drawable(){
	rect = new SDL_Rect();
}


Vector3 GameObject::getPosition(){
	return position;
}