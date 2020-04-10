/*
 *
 *	EntityContainer.cpp
 *
 *	April 09, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */


#include "EntityContainer.h"


EntityContainer::EntityContainer() {

}

void EntityContainer::add(Entity* entity) {
	entities.push_back(entity);
}

void EntityContainer::remove(int id) {
	for(int i = 0; i < entities.size(); i++) {
		if(entities[i] -> getID() == id) {
			delete entities[i];
			entities[i] = entities.back();
			entities.pop_back();
			return;
		}
	}
}

Entity* EntityContainer::find(int id) {
	for(int i = 0; i < entities.size(); i++) {
		if(entities[i] -> getID() == id) {
			return entities[i];
		}
	}
}

void EntityContainer::draw() {
	for(int i = 0; i < entities.size(); i++) {
		entities[i] -> draw();
	}
}

void EntityContainer::cleanEntities() {
	for(int i = 0; i < entities.size(); i++) {
		delete entities[i];
	}
}

EntityContainer::~EntityContainer() {
	cleanEntities();
}
