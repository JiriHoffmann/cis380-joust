#include <SDL2/SDL.h>
#include <Box2D/Box2D.h>
#include "World.hpp"
#include "Engine.hpp"
#include "HUD.hpp"
#include "Ostrich.hpp"
// #include "Surface.hpp"



int
main(int argc, char **argv)
{
	SDL_Log("Starting up, with following arguments:");
	for(int i=0; i<argc; ++i){
		SDL_Log("%d = %s", i, argv[i]);
	}

	// Create a scene
	Scene one;
	// Create an engine.  Must happen early, creates the renderer.
	Engine engine(1024, 768);
	// Create the physics engine
	World w(b2Vec2(0.0, 9.81));
	// // Make an ostrich and add to scene. Should update and draw.
	Ostrich* b = new Ostrich("./assets/ostrich.png", 10, 10);
	w.addRect(b, true);
	SpriteWithBody *s = new SpriteWithBody("./assets/surface.png", 10, 600);
	SpriteWithBody *s2 = new SpriteWithBody("./assets/surface.png", 110, 600);
	SpriteWithBody *s3 = new SpriteWithBody("./assets/surface.png", 210, 600);
	SpriteWithBody *s4 = new SpriteWithBody("./assets/surface.png", 310, 600);
	w.addRect(s, false);
	w.addRect(s2, false);
	w.addRect(s3, false);
	w.addRect(s4, false);
	one.addDrawable(s);
	one.addDrawable(s2);
	one.addDrawable(s3);
	one.addDrawable(s4);

	one.addUpdateable(b);
	one.addDrawable(b);
	one.addUpdateable(&w);
	auto b_up = [b](double delta) { b->up(delta); };
	auto b_left = [b](double delta) { b->left(delta); };
	auto b_right = [b](double delta) { b->right(delta); };
	one.addKeyEvent( SDLK_w, b_up );
	one.addKeyEvent( SDLK_a, b_left );
	one.addKeyEvent( SDLK_d, b_right );

	// Add the HUD
	HUD* h = new HUD();
	one.addUpdateable(h);
	one.addDrawable(h);

	// Set the scene in the engine
	engine.setScene(&one);
	
	// Get the engine running.
	engine.run();
}
