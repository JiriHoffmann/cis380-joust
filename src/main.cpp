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
	Ostrich* b = new Ostrich("./assets/ostrich.png", 300, 300);
	w.addRect(b, true);
	// TOP Platform
	SpriteWithBody *s = new SpriteWithBody("./assets/surface.png", 375,200, 300,10);
	// MIDDLE Platforms
	SpriteWithBody *s2 = new SpriteWithBody("./assets/surface.png", -50, 400, 300,10); // left
	SpriteWithBody *s3 = new SpriteWithBody("./assets/surface.png", 800, 400, 300,10); // right
	// BOTTOM Platform
	SpriteWithBody *s4 = new SpriteWithBody("./assets/surface.png", -100, 600, 1250,10);
	w.addRect(s, false);
	w.addRect(s2, false);
	w.addRect(s3, false);
	w.addRect(s4, false);
	one.addDrawable(s);
	one.addDrawable(s2);
	one.addDrawable(s3);
	one.addDrawable(s4);

	Ostrich* b1 = new Ostrich("./assets/ostrich.png", 700, 100);
	Ostrich* b2 = new Ostrich("./assets/ostrich.png", 800, 500);
	Ostrich* b3 = new Ostrich("./assets/ostrich.png", 100, 100);
	w.addRect(b1, true);
	w.addRect(b2, true);
	w.addRect(b3, true);
	one.addUpdateable(b1);
	one.addDrawable(b1);
	one.addUpdateable(b2);
	one.addDrawable(b2);
	one.addUpdateable(b3);
	one.addDrawable(b3);

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
