
#include <string>
#include "Engine.hpp"
#include "SpriteWithBody.hpp"
#include "Sprite.hpp"
#include <Box2D/Box2D.h>


SpriteWithBody::SpriteWithBody(std::string Image, double x, double y, double w, double h, std::string ObjectType): Sprite(Image, x, y, w, h){
	type = ObjectType;
}

SpriteWithBody::SpriteWithBody(SDL_Surface* inputSurface): Sprite(inputSurface){
}


SpriteWithBody::~SpriteWithBody(){
    
}

void SpriteWithBody::update(double delta){
	position.setX( body->GetPosition().x* M2P - rect->w/2);
    position.setY( body->GetPosition().y* M2P - rect->h/2);
}


void SpriteWithBody::draw(){
	Sprite::draw();
}

void SpriteWithBody::setBody(b2Body* body){
	this->body = body;
}

std::string SpriteWithBody::getType(){
	return type;
}