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
	hand = Texture::ROCK;
}

void Maze::run() {

	TextureHolder textures;

	world.setTextureHolder(&textures);
	world.loadTextures();
	world.loadWorldMap("./maps/default.map");
	player = world.createPlayer(-20.0f, -20.0f);

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
	camera.setPosition(player->getPosition());
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
		case sf::Keyboard::Up: {
			player->up(PLAYER_SPEED);
			break;
		}
		case sf::Keyboard::Down: {
			player->down(PLAYER_SPEED);
			break;
		}
		case sf::Keyboard::Left: {
			player->left(PLAYER_SPEED);
			break;
		}
		case sf::Keyboard::Right: {
			player->right(PLAYER_SPEED);
			break;
		}
		case sf::Keyboard::Q: {
			hand = Texture::WATER;
			break;
		}
		case sf::Keyboard::W: {
			hand = Texture::ROCK;
			break;
		}
		case sf::Keyboard::E: {
			hand = Texture::GRASS;
			break;
		}
		case sf::Keyboard::R: {
			hand = Texture::WALL;
		}
		case sf::Keyboard::S: {
			world.saveWorldMap("./maps/default.map");
			break;
		}
		case sf::Keyboard::Space: {
			auto pos = player->getPosition();
			pos.x = 20.0f * (int) (pos.x / 20.0f);
			pos.y = 20.0f * (int) (pos.y / 20.0f);
			world.createEntity(hand, pos.x, pos.y);
			break;
		}
	}
}

Maze::~Maze() {
}
