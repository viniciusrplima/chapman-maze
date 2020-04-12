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

Maze::Maze() : window(sf::VideoMode(600.0f, 480.0f), "Chapman Maze") {
	position.x = 300.0f;
	position.y = 240.0f;
	zoom = 2.0f;
}

void Maze::run() {

	TextureHolder textures;

	world.setTextureHolder(&textures);
	world.loadTextures();

	world.createEntity(Texture::SOLDIER, 120.0f, 130.0f);
	world.createEntity(Texture::WATER, 20.0f, 130.0f);
	world.createEntity(Texture::WATER, 0.0f, 130.0f);
	world.createEntity(Texture::WATER, -20.0f, 130.0f);
	world.createEntity(Texture::ROCK, 350.0f, 190.0f);
	world.createEntity(Texture::ROCK, 330.0f, 190.0f);
	world.createEntity(Texture::ROCK, 310.0f, 190.0f);
	world.createEntity(Texture::GRASS, 120.0f, 180.0f);
	world.createEntity(Texture::SOLDIER, 300.0f, 130.0f);

	window.setFramerateLimit(60);

	while( window.isOpen() ) {
	
		
		sf::Event event;
		while(window.pollEvent(event)) {
			eventHandle(event);
		}

		update();
		render();
	}
}

void Maze::update() {
}

void Maze::render() {

	sf::Transform transform;
	transform.translate(-position.x, position.y);
	transform.scale(zoom, zoom);

	window.clear();

	world.draw(window, transform);

	window.display();
}

void Maze::eventHandle(sf::Event event) {
	if(event.type == sf::Event::Closed) {
		window.close();
	}

	if(event.type == sf::Event::KeyPressed ||
	   event.type == sf::Event::KeyReleased ) {
		keyboardHandle(event);
	}
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

		case sf::Keyboard::Up: {
			position.y += 10.0f;
			break;
		}
		case sf::Keyboard::Down: {
			position.y -= 10.0f;
			break;
		}
		case sf::Keyboard::Left: {
			position.x -= 10.0f;
			break;
		}
		case sf::Keyboard::Right: {
			position.x += 10.0f;
			break;
		}

	}
}

Maze::~Maze() {
}
