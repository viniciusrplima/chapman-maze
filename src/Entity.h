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
	enum Type {
		PLAYER, 
		WATER, 
		ROCK, 
		GRASS, 
		WALL
	};

	Entity(Type type, float x, float y);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) = 0;

	sf::Vector2f getPosition();
	Type getType();

	~Entity();

protected:

	Type type;

	sf::Vector2f position;
};

#endif
