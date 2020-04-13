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

Entity::Entity(Type type, float x, float y, sf::Texture& texture) : sprite(texture) {
	this->type = type;
	position.x = x;
	position.y = y;

	auto size = texture.getSize();
	scale.x = 20.0f / size.x;
	scale.y = 20.0f / size.y;
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) {
	sprite.setScale(scale.x, scale.y);
	sprite.setPosition(position.x, position.y);
	target.draw(sprite, states);
}

sf::Vector2f Entity::getPosition() {
	return position;
}

Entity::Type Entity::getType() {
	return type;
}

Entity::~Entity() {
}
