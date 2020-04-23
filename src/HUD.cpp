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

	const float fs = 0.4f; // font scale

	// HUD Background
	sf::RenderStates states;

	sf::RectangleShape background;
	background.setOutlineColor(sf::Color::White);
	background.setOutlineThickness(1.0f);
	background.setSize(sf::Vector2f(600.0f, 300.0f));
	background.setFillColor(sf::Color(10, 10, 40, 255));
	states.transform.translate(0.0f, 380.0f);
	target.draw(background, states);

	
	// Block HUD
	sf::RenderStates bhState(states);
	bhState.transform.translate(20.0f, 0.0f); // margin left

	sf::Text bhText("Block", font);
	bhText.setScale(fs * aspect.x, fs * aspect.y);
	bhState.transform.translate(0.0f, 20.0f);
	target.draw(bhText, bhState);

	sf::Sprite block(textureHolder->get(hand->blockType));
	block.setScale(2.0f * aspect.x, 2.0f * aspect.y);
	
	bhState.transform.translate(0.0f, 20.0f);
	target.draw(block, bhState);
	


	// Mode HUD
	sf::RenderStates mdState(states);
	mdState.transform.translate(120.0f, 0.0f);

	sf::Text mdText("Mode", font);
	mdText.setScale(fs * aspect.x, fs * aspect.y);
	mdState.transform.translate(0.0f, 20.0f);
	target.draw(mdText, mdState);

	std::string mode = hand->removeForward ? "remove" : "add";
	sf::Text mdModeText(mode, font);
	mdModeText.setScale(fs * aspect.x, fs * aspect.y);
	mdState.transform.translate(0.0f, 50.0f);
	target.draw(mdModeText, mdState);


	// HUD choose block commands
	sf::RenderStates cbcState(states);
	cbcState.transform.translate(220.0f, 0.0f);
	
	sf::Text cbcText("Choose Block", font);
	cbcText.setScale(fs * aspect.x, fs * aspect.y);
	cbcState.transform.translate(0.0f, 20.0f);
	target.draw(cbcText, cbcState);

	sf::Text cbcCommandsText("Q W E R T Y", font);
	cbcCommandsText.setScale(fs * aspect.x, fs * aspect.y);
	cbcState.transform.translate(0.0f, 50.0f);
	target.draw(cbcCommandsText, cbcState);

	// HUD Commands
	sf::RenderStates cmdState(states);
	cmdState.transform.translate(380.0f, 0.0f);
	
	sf::Text cmdText("Commands", font);
	cmdText.setScale(fs * aspect.x, fs * aspect.y);
	cmdState.transform.translate(0.0f, 20.0f);
	target.draw(cmdText, cmdState);

	sf::Text cmdListText("+/- - zoom \nA - add mode \nZ - remove mode\nS - save map", font);
	cmdListText.setScale(fs * aspect.x, fs * aspect.y);
	cmdState.transform.translate(0.0f, 20.0f);
	target.draw(cmdListText, cmdState);
}

HUD::~HUD() {
}
