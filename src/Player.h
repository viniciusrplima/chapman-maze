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

#include "Entity.h"

class Player : public Entity {

public:
	Player(Texture::ID, float x, float y, TextureHolder*);

	void up(float offset);
	void left(float offset);
	void right(float offset);
	void down(float offset);

	~Player();

private:

};
