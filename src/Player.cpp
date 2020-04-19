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

void Player::up() {
	animation->setAnimation("UP");
	move = Player::UP;
}

void Player::left() {
	animation->setAnimation("LEFT");
	move = Player::LEFT;
}

void Player::right() {
	animation->setAnimation("RIGHT");
	move = Player::RIGHT;
}

void Player::down() {
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

	float quadRadius = BLOCK_WIDTH / 2;

	if(move == Player::UP) pos.y -= BLOCK_WIDTH + quadRadius;
	else if(move == Player::DOWN) pos.y += BLOCK_WIDTH + quadRadius;
	else if(move == Player::LEFT) pos.x -= BLOCK_WIDTH + quadRadius;
	else if(move == Player::RIGHT) pos.x += BLOCK_WIDTH + quadRadius;

	return pos;
}

Player::Move Player::getMove() {
	return move;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) {
	states.transform.translate(position.x - 6, position.y - 8);
	animation->draw(target, states);
}

Player::~Player() {
}
