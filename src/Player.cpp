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

void Player::drawThis(sf::RenderTarget& target, sf::RenderStates states) {
	states.transform.translate(position.x, position.y);
	animation->draw(target, states);
}

Player::~Player() {
}
