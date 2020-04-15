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

Player::Player(float x, float y, AnimationSet* anim) :
Entity(Entity::PLAYER, x, y) {
	animation = anim;
}

void Player::up(float deltaTime) {
	position.y -= deltaTime * PLAYER_SPEED;
	animation->setAnimation("UP");
}

void Player::left(float deltaTime) {
	position.x -= deltaTime * PLAYER_SPEED;
	animation->setAnimation("LEFT");
}

void Player::right(float deltaTime) {
	position.x += deltaTime * PLAYER_SPEED;
	animation->setAnimation("RIGHT");
}

void Player::down(float deltaTime) {
	position.y += deltaTime * PLAYER_SPEED;
	animation->setAnimation("DOWN");
}

void Player::stop() {
	auto anim = animation->getAnimation();

	if(anim == "DOWN") animation->setAnimation("STOP_DOWN");
	if(anim == "UP") animation->setAnimation("STOP_UP");
	if(anim == "LEFT") animation->setAnimation("STOP_LEFT");
	if(anim == "RIGHT") animation -> setAnimation("STOP_RIGHT");
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) {
	states.transform.translate(position.x - 6, position.y - 8);
	animation->draw(target, states);
}

Player::~Player() {
}
