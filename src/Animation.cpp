/*
 *
 *	Animation.cpp
 *
 *	April 13, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#include "Animation.h"

Animation::Animation() {
	duration = 1.0f;
}

void Animation::draw(sf::RenderTarget& target, sf::RenderStates states) {
	sf::Time deltaTime = clock.restart();
	elapsedTime += deltaTime;
	float timeAsSeconds = elapsedTime.asSeconds();
	int framesNum = frames.size();
	int frame = (int) ((timeAsSeconds / duration) * framesNum) % framesNum;

	auto rect = frames[frame];
	states.transform.scale(PLAYER_WIDTH / rect.width, PLAYER_HEIGHT / rect.height);
	sprite.setTextureRect(rect);
	target.draw(sprite, states);
}

void Animation::addFrame(float x, float y, float w, float h) {
	sf::IntRect rect(x, y, w, h);
	frames.push_back(rect);
}

void Animation::reset() {
	elapsedTime = sf::seconds(0);
}

void Animation::setTexture(sf::Texture& texture) {
	sprite.setTexture(texture);
}

void Animation::setDuration(float duration) {
	this->duration = duration;
}

float Animation::getDuration() {
	return duration;
}

Animation::~Animation() {
}
