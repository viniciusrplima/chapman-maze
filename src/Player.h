/*
 *
 *	Player.h
 *
 *	April 12, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#include "AnimationSet.h"
#include "Entity.h"

#define PLAYER_SPEED 40.0f

#ifndef __PLAYER_H_
#define __PLAYER_H_

class Player : public Entity {

public:
	enum Move {
		UP, 
		LEFT, 
		RIGHT, 
		DOWN
	};

	Player(float x, float y, AnimationSet *anim);

	void up();
	void left();
	void right();
	void down();
	void stop();
	sf::Vector2f getForward();
	Move getMove();

	void draw(sf::RenderTarget& target, sf::RenderStates states);

	~Player();

private:

	Move move;
	AnimationSet* animation;
};

#endif
