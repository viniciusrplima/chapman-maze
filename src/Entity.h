/*
 *
 *	Entity.h
 *
 *	April 09, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#ifndef __ENTITY_H_
#define __ENTITY_H_

#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>

#include "TextureHolder.h"

class Entity {

public:

	Entity(Texture::ID, float x, float y, TextureHolder*);

	void draw(sf::RenderTarget& target, sf::RenderStates states);

	sf::Vector2f getPosition();
	Texture::ID getTexture();

	~Entity();

protected:

	sf::Sprite sprite;
	Texture::ID texture;

	sf::Vector2f position;
	sf::Vector2f scale;
};

#endif
