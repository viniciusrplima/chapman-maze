/*
 *
 *	Player.cpp
 *
 *	April 12, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */


#include "Player.h"

Player::Player(Entity::Type type, float x, float y, sf::Texture& texture, AnimationSet* anim) :
Entity(type, x, y, texture) {
	animation = anim;
}

void Player::up(float offset) {
	position.y -= offset;
	animation->setAnimation("UP");
}

void Player::left(float offset) {
	position.x -= offset;
	animation->setAnimation("LEFT");
}

void Player::right(float offset) {
	animation->setAnimation("RIGHT");
	position.x += offset;
}

void Player::down(float offset) {
	animation->setAnimation("DOWN");
	position.y += offset;
}

void Player::drawThis(sf::RenderTarget& target, sf::RenderStates states) {
	states.transform.translate(position.x, position.y);
	animation->draw(target, states);
}

Player::~Player() {
}
