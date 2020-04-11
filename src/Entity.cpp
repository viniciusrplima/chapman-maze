/*
 *
 *	Entity.cpp
 *
 *	April 09, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#include "Entity.h"

Entity::Entity(sf::Texture& texture) : sprite(texture) {
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) {
	target.draw(sprite, states);
}

sf::Vector2f Entity::getPosition() {
	return position;
}

Entity::~Entity() {
}
