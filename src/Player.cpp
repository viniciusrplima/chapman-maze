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

Player::Player(Texture::ID tex, float x, float y, TextureHolder* textures) :
Entity(tex, x, y, textures) {
}

void Player::up(float offset) {
	position.y -= offset;
}

void Player::left(float offset) {
	position.x -= offset;
}

void Player::right(float offset) {
	position.x += offset;
}

void Player::down(float offset) {
	position.y += offset;
}

Player::~Player() {
}
