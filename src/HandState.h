/*
 *
 *	HandState.h
 *
 *	April 19, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#include "Entity.h"
#include "TextureHolder.h"

#ifndef __HAND_STATE_H_
#define __HAND_STATE_H_

// Handle the player hand state
class HandState {

public:
	HandState() {}

	Entity::Type blockType;
	Texture::ID blockTex;

	// if true : remove mode
	// if false : add mode
	bool removeForward;

	~HandState() {}
};

#endif
