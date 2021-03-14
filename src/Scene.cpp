#include <SDL2/SDL.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include "Scene.hpp"

Scene::Scene(){

}

Scene::~Scene(){

}

void Scene::addUpdateable(Updateable* obj){
	this->updateables.push_back(obj);
}

void Scene::addDrawable(Drawable* obj){
	this->drawables.push_back(obj);
}
