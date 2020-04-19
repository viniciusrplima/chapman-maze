/*
 *
 *	HUD.cpp
 *
 *	April 19, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#include "HUD.h"

HUD::HUD() {
}

void HUD::setHandState(HandState* hand) {
	this->hand = hand;	
}

void HUD::setTextureHolder(TextureHolder* textureHolder) {
	this->textureHolder = textureHolder;
}

void HUD::setAspect(sf::Vector2f aspect) {
	this->aspect = aspect;
}

void HUD::draw(sf::RenderTarget& target) {

	sf::Sprite block(textureHolder->get(hand->blockType));
	block.setScale(2.0f * aspect.x, 2.0f * aspect.y);
	
	sf::RenderStates states;
	states.transform.translate(20.0f, 380.0f);
	target.draw(block, states);
}

HUD::~HUD() {
}
