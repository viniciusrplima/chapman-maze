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

#ifndef __HAND_STATE_H_
#define __HAND_STATE_H_

class HandState {

public:
	HandState() {}

	Entity::Type blockType;
	bool removeForward;

	~HandState() {}
};

#endif
