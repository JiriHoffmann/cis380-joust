#ifndef			__HPP__SPRITE__
#define			__HPP__SPRITE__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"

class Sprite : public DUGameObject {
	public:
		Sprite(std::string Image, double x, double y) ;
		Sprite(SDL_Surface *inputSurface);

		~Sprite();
		void draw();

	};

#endif
