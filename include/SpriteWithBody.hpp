#ifndef			__HPP__SPRITEWITHBODY__
#define			__HPP__SPRITEWITHBODY__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Box2D/Box2D.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include "Sprite.hpp"


// Meters to pixels 
const float M2P = 50.0;

class SpriteWithBody : public Sprite {
	public:
		SpriteWithBody(std::string Image, double x, double y, double w, double h, std::string ObjectType);
		SpriteWithBody(SDL_Surface *inputSurface);

		~SpriteWithBody();
    	void update(double delta);
		void draw();
        void setBody(b2Body *body);
		std::string getType();

	protected:
        b2Body *body;
		std::string type;

	friend class World;
	};

#endif
