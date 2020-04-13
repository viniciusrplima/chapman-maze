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

class Player : public Entity {

public:
	Player(Entity::Type, float x, float y, sf::Texture&, AnimationSet *anim);

	void up(float offset);
	void left(float offset);
	void right(float offset);
	void down(float offset);

	void drawThis(sf::RenderTarget& target, sf::RenderStates states);

	~Player();

private:

	AnimationSet* animation;
};
