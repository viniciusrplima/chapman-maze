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
	hand = Entity::ROCK;
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
	deltaTime = clock.restart();
	camera.setPosition(player->getPosition());
	updateInput();
	world.update();
}

void Maze::render() {

	sf::RenderStates state = camera.getRenderState();

	window.clear();

	world.drawMark(player->getPosition(), window, state);
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

	if(event.type == sf::Event::KeyPressed) {
		keyboardState[event.key.code] = 1;
	}
	if(event.type == sf::Event::KeyReleased) {
		keyboardState[event.key.code] = 0;
	}
}

void Maze::updateInput() {

	if(keyboardState[ sf::Keyboard::Add ]) camera.zoomIn();
	if(keyboardState[ sf::Keyboard::Subtract ]) camera.zoomOut();

	if(keyboardState[ sf::Keyboard::Up ]) player->up(deltaTime.asSeconds());
	else if(keyboardState[ sf::Keyboard::Down ]) player->down(deltaTime.asSeconds());
	else if(keyboardState[ sf::Keyboard::Left ]) player->left(deltaTime.asSeconds());
	else if(keyboardState[ sf::Keyboard::Right ]) player->right(deltaTime.asSeconds());
	else player->stop();

	if(keyboardState[ sf::Keyboard::Q ]) hand = Entity::WATER;
	if(keyboardState[ sf::Keyboard::W ]) hand = Entity::ROCK;
	if(keyboardState[ sf::Keyboard::E ]) hand = Entity::GRASS;
	if(keyboardState[ sf::Keyboard::R ]) hand = Entity::WALL;

	if(keyboardState[ sf::Keyboard::S ]) world.saveWorldMap("./maps/default.map");

	if(keyboardState[ sf::Keyboard::Space ]) {
		auto pos = player->getPosition();
		world.createBlock(hand, pos.x, pos.y);
	}

}

Maze::~Maze() {
}
