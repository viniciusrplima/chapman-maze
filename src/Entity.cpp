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

Entity::Entity(Texture::ID tex, float x, float y, TextureHolder* textures) : sprite() {
	sprite.setTexture(textures->get(tex));
	texture = tex;
	position.x = x;
	position.y = y;

	auto size = textures->get(tex).getSize();
	scale.x = 20.0f / size.x;
	scale.y = 20.0f / size.y;
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) {
	sprite.setScale(scale.x, scale.y);
	sprite.setPosition(position.x, position.y);
	target.draw(sprite, states);
}

Texture::ID Entity::getTexture() {
	return texture;
}

sf::Vector2f Entity::getPosition() {
	return position;
}

Entity::~Entity() {
}
