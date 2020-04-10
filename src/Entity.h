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

#include <SFML/System.hpp>

class Entity {

public:

	virtual void draw() = 0;

	sf::Vector2f getPosition();
	int getID();

protected:

	sf::Vector2f position;
	int id;
};

#endif
