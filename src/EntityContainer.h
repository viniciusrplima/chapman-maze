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

#include <SFML/Graphics.hpp>
#include <vector>

#include "Entity.h"

class EntityContainer {

public:

	EntityContainer();

	void draw(sf::RenderTarget&, sf::RenderStates);

	~EntityContainer();

private:

	void cleanEntities();


	std::vector<Entity*> entities;
};
