/*
 *
 *	Vector.h
 *
 *	April 09, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#ifndef __VECTOR_H_
#define __VECTOR_H_

class Vector {

public:

	Vector(float, float);

	float getX();
	float getY();
	float getModule();

	~Vector();

private:

	float x, y;
};

#endif
