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
}

void Maze::run() {

	TextureHolder textures;

	world.setTextureHolder(&textures);
	world.loadTextures();

	world.createEntity(Texture::SOLDIER, 0.0f, 0.0f);
	world.createEntity(Texture::SOLDIER, 120.0f, 130.0f);
	world.createEntity(Texture::WATER, 20.0f, 20.0f);
	world.createEntity(Texture::WATER, 0.0f, 20.0f);
	world.createEntity(Texture::WATER, 40.0f, 20.0f);
	world.createEntity(Texture::WATER, -20.0f, 0.0f);
	world.createEntity(Texture::ROCK, 350.0f, 190.0f);
	world.createEntity(Texture::ROCK, 330.0f, 190.0f);
	world.createEntity(Texture::ROCK, 310.0f, 190.0f);
	world.createEntity(Texture::GRASS, 120.0f, 180.0f);
	world.createEntity(Texture::SOLDIER, 300.0f, 130.0f);

	world.saveWorldMap("./maps/default.map");

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

	sf::RenderStates state = camera.getRenderState();

	window.clear();

	world.draw(window, state);

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

	if(event.type == sf::Event::Resized) {
		camera.setWindowSize(event.size.width, event.size.height);
	}
}

void Maze::keyboardHandle(sf::Event event) {
	switch(event.key.code) {
		case sf::Keyboard::Add: {
			camera.zoomIn();
			break;
		}
		case sf::Keyboard::Subtract: {
			camera.zoomOut();
			break;
		}
	}
}

Maze::~Maze() {
}
