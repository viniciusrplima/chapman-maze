/*
 *
 *	Vector.cpp
 *
 *	April 09, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#include "Vector.h"
#include <cmath>

Vector::Vector(float x, float y) {
	this -> x = x;
	this -> y = y;
}

float Vector::getX() {
	return x;
}

float Vector::getY() {
	return y;
}

float Vector::getModule() {
	return sqrt(x * x + y * y);
}

