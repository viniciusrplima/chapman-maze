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

#define PLAYER_SPEED 30.0f

class Player : public Entity {

public:
	enum Move {
		UP, 
		LEFT, 
		RIGHT, 
		DOWN
	};

	Player(float x, float y, AnimationSet *anim);

	void up(float offset);
	void left(float offset);
	void right(float offset);
	void down(float offset);
	void stop();
	sf::Vector2f getForward();

	void draw(sf::RenderTarget& target, sf::RenderStates states);

	~Player();

private:

	Move move;
	AnimationSet* animation;
};
