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
#include "Vector.h"

class Entity {

public:

	virtual void draw() = 0;

	Vector* getPosition();
	int getID();

protected:

	Vector* position;
	int id;
};

#endif
