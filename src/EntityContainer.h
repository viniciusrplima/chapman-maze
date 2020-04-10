/*
 *
 *	EntityContainer.h
 *
 *	April 09, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#include <vector>

#include "Entity.h"

class EntityContainer {

public:

	EntityContainer();

	void add(Entity*);
	void remove(int);
	Entity* find(int);
	void update();
	void draw();

	~EntityContainer();

private:

	void cleanEntities();

	std::vector<Entity*> entities;
};
