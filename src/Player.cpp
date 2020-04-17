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
#include "Block.h"

Player::Player(float x, float y, AnimationSet* anim) :
Entity(Entity::PLAYER, x, y) {
	animation = anim;
}

void Player::up(float deltaTime) {
	position.y -= deltaTime * PLAYER_SPEED;
	animation->setAnimation("UP");
	move = Player::UP;
}

void Player::left(float deltaTime) {
	position.x -= deltaTime * PLAYER_SPEED;
	animation->setAnimation("LEFT");
	move = Player::LEFT;
}

void Player::right(float deltaTime) {
	position.x += deltaTime * PLAYER_SPEED;
	animation->setAnimation("RIGHT");
	move = Player::RIGHT;
}

void Player::down(float deltaTime) {
	position.y += deltaTime * PLAYER_SPEED;
	animation->setAnimation("DOWN");
	move = Player::DOWN;
}

void Player::stop() {
	if(move == Player::DOWN) animation->setAnimation("STOP_DOWN");
	else if(move == Player::UP) animation->setAnimation("STOP_UP");
	else if(move == Player::LEFT) animation->setAnimation("STOP_LEFT");
	else if(move == Player::RIGHT) animation->setAnimation("STOP_RIGHT");
}

sf::Vector2f Player::getForward() {
	auto pos = position;

	if(move == Player::UP) pos.y -= BLOCK_WIDTH;
	else if(move == Player::DOWN) pos.y += BLOCK_WIDTH;
	else if(move == Player::LEFT) pos.x -= BLOCK_WIDTH;
	else if(move == Player::RIGHT) pos.x += BLOCK_WIDTH;

	return pos;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) {
	states.transform.translate(position.x - 6, position.y - 8);
	animation->draw(target, states);
}

Player::~Player() {
}
