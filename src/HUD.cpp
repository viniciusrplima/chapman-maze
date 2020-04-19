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
	if(!font.loadFromFile("./fonts/PressStart2P-Regular.ttf")) {
		std::cout << "Error loading font" << std::endl;
	}
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
	sf::RenderStates states;

	sf::RectangleShape background;
	background.setOutlineColor(sf::Color::White);
	background.setOutlineThickness(1.0f);
	background.setSize(sf::Vector2f(600.0f, 300.0f));
	background.setFillColor(sf::Color(10, 10, 40, 255));
	states.transform.translate(0.0f, 350.0f);
	target.draw(background, states);
	states.transform.translate(20.0f, 10.0f);
	
	sf::Text text("Block", font);
	text.setScale(0.5f * aspect.x, 0.5f * aspect.y);
	states.transform.translate(0.0f, 20.0f);
	target.draw(text, states);

	sf::Sprite block(textureHolder->get(hand->blockType));
	block.setScale(2.0f * aspect.x, 2.0f * aspect.y);
	
	states.transform.translate(0.0f, 20.0f);
	target.draw(block, states);
}

HUD::~HUD() {
}
