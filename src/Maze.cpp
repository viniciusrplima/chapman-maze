/*
 *
 *	Maze.cpp
 *
 *	April 09, 2020
 *	by Vincius Rodrigues
 *
 *
 *
 */

#include <iostream>
#include <GL/gl.h>

#include "Maze.h"
#include "Block.h"

Maze::Maze() {
	world = new EntityContainer();

	Entity* b1 = new Block(window, 54642, 1.0f, 1.0f);
	Entity* b2 = new Block(window, 132323, -1.0f, -1.0f);

	world -> add(b1);
	world -> add(b2);

	zoom = 0.1f;
}


void Maze::run() {
	sf::ContextSettings settings;
	settings.depthBits = 24;

	window = new sf::RenderWindow(sf::VideoMode(600, 480), 
			"Chapman Maze", 
			sf::Style::Default, 
			settings);

	window -> setFramerateLimit(60);

	while( window -> isOpen() ) {
		
		sf::Event event;
		while(window -> pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				window -> close();
			}

			if(event.type == sf::Event::KeyPressed ||
			   event.type == sf::Event::KeyReleased ) {
				keyboardHandle(event);
			}
		}

		update();
		render();
	}
}

void Maze::update() {
}

void Maze::render() {

	glClearColor(0.5f, 0.5f, 0.8f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();


	glPopMatrix();

	window -> display();
}

void Maze::keyboardHandle(sf::Event event) {
	switch(event.key.code) {
		case sf::Keyboard::Add: {
			zoom *= 1.1f;
			break;
		}

		case sf::Keyboard::Subtract: {
			zoom *= 0.9f;
			break;
		}
	}
}

Maze::~Maze() {
	delete world;
}
