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

Maze::Maze() {
	handState.blockType = Entity::ROCK;
	handState.removeForward = false;
}

void Maze::run(sf::RenderWindow& window, Texture::ID playerTex, const std::string& animFile) {

	TextureHolder textures;

	world.setTextureHolder(&textures);
	world.loadTextures();
	world.loadWorldMap("./maps/default.map");

	player = world.createPlayer(-20.0f, -20.0f, playerTex, animFile);
	player->setPosition(10.0f, 0.0f);

	auto windowSize = window.getSize();

	gameHUD.setHandState(&handState);
	gameHUD.setTextureHolder(&textures);
	gameHUD.setAspect(sf::Vector2f(600.0f / windowSize.x, 480.0f / windowSize.y));

	window.setFramerateLimit(60);
	camera.setWindowSize(windowSize.x, windowSize.y);

	while( window.isOpen() ) {
	
		
		sf::Event event;
		while(window.pollEvent(event)) {
			eventHandle(window, event);
		}

		update();
		render(window);
	}
}

void Maze::update() {
	deltaTime = clock.restart();
	camera.setPosition(player->getPosition());
	updateInput();
	world.update();
}

void Maze::render(sf::RenderWindow& window) {

	sf::RenderStates state = camera.getRenderState();

	window.clear();

	if(!handState.removeForward) world.drawAddMark(player->getForward(), window, state);
	world.draw(window, state);
	if(handState.removeForward) world.drawDelMark(player->getForward(), window, state);
	player->draw(window, state);
	gameHUD.draw(window);

	window.display();
}

void Maze::eventHandle(sf::RenderWindow& window, sf::Event event) {
	if(event.type == sf::Event::Closed) {
		window.close();
	}

	if(event.type == sf::Event::KeyPressed ||
	   event.type == sf::Event::KeyReleased ) {
		keyboardHandle(event);
	}

	if(event.type == sf::Event::Resized) {
		camera.setWindowSize(event.size.width, event.size.height);
		gameHUD.setAspect(sf::Vector2f(600.0f / event.size.width, 480.0f / event.size.height));
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

	if(keyboardState[ sf::Keyboard::Up ]) world.movePlayer(Player::UP, deltaTime.asSeconds());
	else if(keyboardState[ sf::Keyboard::Down ]) world.movePlayer(Player::DOWN, deltaTime.asSeconds());
	else if(keyboardState[ sf::Keyboard::Left ]) world.movePlayer(Player::LEFT, deltaTime.asSeconds());
	else if(keyboardState[ sf::Keyboard::Right ]) world.movePlayer(Player::RIGHT, deltaTime.asSeconds());
	else player->stop();

	if(keyboardState[ sf::Keyboard::Q ]) handState.blockType = Entity::WATER;
	if(keyboardState[ sf::Keyboard::W ]) handState.blockType = Entity::ROCK;
	if(keyboardState[ sf::Keyboard::E ]) handState.blockType = Entity::GRASS;
	if(keyboardState[ sf::Keyboard::R ]) handState.blockType = Entity::WALL;
	if(keyboardState[ sf::Keyboard::T ]) handState.blockType = Entity::VERTICAL_WALL;
	if(keyboardState[ sf::Keyboard::Y ]) handState.blockType = Entity::FLOOR;


	if(keyboardState[ sf::Keyboard::A ]) handState.removeForward = false;
	if(keyboardState[ sf::Keyboard::Z ]) handState.removeForward = true;

	if(keyboardState[ sf::Keyboard::S ]) world.saveWorldMap("./maps/default.map");

	if(keyboardState[ sf::Keyboard::Space ]) {
		auto pos = player->getForward();

		if(!handState.removeForward)
			world.createBlock(handState.blockType, pos.x, pos.y);
		else
			world.removeBlock(pos.x, pos.y);
	}

}

Maze::~Maze() {
}
