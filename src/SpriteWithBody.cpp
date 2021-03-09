
#include <string>
#include "Engine.hpp"
#include "SpriteWithBody.hpp"
#include "Sprite.hpp"
#include <Box2D/Box2D.h>

const float M2P = 20;
const float P2M = 1 / M2P;

SpriteWithBody::SpriteWithBody(std::string Image, double x, double y): Sprite(Image, x, y){
}

SpriteWithBody::SpriteWithBody(SDL_Surface* inputSurface): Sprite(inputSurface){
}


SpriteWithBody::~SpriteWithBody(){
    
}

void SpriteWithBody::update(double delta){
	position.setX( body->GetPosition().x * M2P);
    position.setY( body->GetPosition().y * M2P);
}


void SpriteWithBody::draw(){
	Sprite::draw();
}

void SpriteWithBody::setBody(b2Body* body){
	this->body = body;
}