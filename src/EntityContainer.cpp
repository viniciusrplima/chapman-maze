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

void EntityContainer::draw(sf::RenderTarget& target, sf::RenderStates states) {
	for(int i = 0; i < entities.size(); i++) {
		entities[i]->draw(target, states);
	}
}

void EntityContainer::setTextureHolder(TextureHolder* textures) {
	this->textures = textures;
}

void EntityContainer::loadTextures() {
	textures->load(Texture::SOLDIER, "./assets/soldier.png");
	textures->load(Texture::WATER, "./assets/water.png");
	textures->load(Texture::ROCK, "./assets/rock.png");
	textures->load(Texture::GRASS, "./assets/grass.png");
}

void EntityContainer::createEntity(Texture::ID id, float x, float y) {
	Entity* entity = new Entity(textures->get(id), x, y);
	entities.push_back(entity);
}

void EntityContainer::cleanEntities() {
	for(int i = 0; i < entities.size(); i++) {
		delete entities[i];
	}
}

EntityContainer::~EntityContainer() {
	cleanEntities();
}
