/*
 *
 *	Block.h
 *
 *	April 09, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#include <SFML/Graphics.hpp>

#include "Entity.h"

class Block : public Entity {

public:

	Block(sf::RenderWindow*, int, float, float);

	void draw();

	~Block();

private:

	sf::Texture texture;
	sf::Sprite sprite;
	sf::RenderWindow* window;
};
