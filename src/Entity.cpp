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
	physic = Entity::NONE;
}

void Entity::setPosition(float x, float y) {
	position.x = x;
	position.y = y;
}

sf::Vector2f Entity::getPosition() {
	return position;
}

Entity::Type Entity::getType() {
	return type;
}

void Entity::setPhysic(Entity::Physics physic) {
	this->physic = physic;
}

Entity::Physics Entity::getPhysic() {
	return physic;
}

Entity::~Entity() {
}
