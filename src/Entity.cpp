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

Entity::Entity(Type type, float x, float y) {
	this->type = type;
	position.x = x;
	position.y = y;
}

sf::Vector2f Entity::getPosition() {
	return position;
}

Entity::Type Entity::getType() {
	return type;
}

Entity::~Entity() {
}
