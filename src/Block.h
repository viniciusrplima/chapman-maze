/*
 *
 *	Block.h
 *
 *	April 15, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#include "Entity.h"

#define BLOCK_WIDTH 20.0f

class Block : public Entity {

public:
	Block(Entity::Type type, float x, float y, sf::Texture&);

	void draw(sf::RenderTarget& target, sf::RenderStates states);

	~Block();

private:

	sf::Sprite sprite;
	sf::Vector2f scale;
};
