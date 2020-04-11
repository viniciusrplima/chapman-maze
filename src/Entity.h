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

class Entity {

public:

	Entity(sf::Texture&, float x, float y);

	void draw(sf::RenderTarget& target, sf::RenderStates states);

	sf::Vector2f getPosition();

	~Entity();

protected:

	sf::Sprite sprite;

	sf::Vector2f position;
};

#endif
