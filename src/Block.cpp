/*
 *
 *	Block.cpp
 *
 *	April 09, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#include <GL/gl.h>

#include "Block.h"


Block::Block(sf::RenderWindow* window, int id, float x, float y) {

	this -> id = id;
	position.x = x;
	position.y = y;
}

void Block::draw() {

	glBegin(GL_TRIANGLES);

	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 2.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glEnd();
}

Block::~Block() {
	
}
