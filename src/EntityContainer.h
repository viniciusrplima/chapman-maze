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

	~EntityContainer();

private:

	void cleanEntities();

	std::vector<Entity*> entities;
};
