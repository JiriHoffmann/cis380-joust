#ifndef			__HPP__SPRITEWITHBODY__
#define			__HPP__SPRITEWITHBODY__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Box2D/Box2D.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include "Sprite.hpp"

class SpriteWithBody : public Sprite {
	public:
		SpriteWithBody(std::string Image, double x, double y, double w, double h);
		SpriteWithBody(SDL_Surface *inputSurface);

		~SpriteWithBody();
    	void update(double delta);
		void draw();
        void setBody(b2Body *body);

	protected:
        b2Body *body;

	friend class World;
	};

#endif
