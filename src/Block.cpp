/*
 *
 *	Block.cpp
 *
 *	April 15, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#include "Block.h"

Block::Block(Entity::Type type, float x, float y, sf::Texture& tex)
: Entity(type, x, y), sprite(tex) {
	auto size = tex.getSize();
	scale.x = BLOCK_WIDTH / size.x;
	scale.y = BLOCK_WIDTH / size.y;
}

void Block::draw(sf::RenderTarget& target, sf::RenderStates states) {
	states.transform.translate(position.x, position.y);
	states.transform.scale(scale.x, scale.y);
	target.draw(sprite, states);
}

Block::~Block() {
}
