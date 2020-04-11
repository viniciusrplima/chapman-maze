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

Entity::Entity(sf::Texture& texture, float x, float y) : sprite(texture) {
	position.x = x;
	position.y = y;
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) {
	states.transform.translate(position.x, position.y);
	target.draw(sprite, states);
}

sf::Vector2f Entity::getPosition() {
	return position;
}

Entity::~Entity() {
}
