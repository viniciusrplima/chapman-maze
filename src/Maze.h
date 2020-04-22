/*
 *
 *	Maze.h
 *
 *	April 09, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#include <SFML/Graphics.hpp>
#include <map>

#include "Animation.h"
#include "AnimationSet.h"
#include "EntityContainer.h"
#include "Camera.h"
#include "HandState.h"
#include "HUD.h"

#ifndef __MAZE_H_
#define __MAZE_H_

class Maze {

public: 
	
	Maze();

	void run(sf::RenderWindow&, Texture::ID playerTex, const std::string& animFile);
	void update();
	void render(sf::RenderWindow&);
	void eventHandle(sf::RenderWindow&, sf::Event);
	void keyboardHandle(sf::Event);

	~Maze();

private:
	void updateInput();
	
	sf::RenderWindow window;

	// Game objects
	EntityContainer world;
	Camera camera;
	Player* player;

	// Time Objects
	sf::Clock clock;
	sf::Time deltaTime;

	// Store the keyboard state
	std::map<sf::Keyboard::Key, int> keyboardState;

	// Store the current player block in hand
	HandState handState;

	// Store HUD of the game
	HUD gameHUD;
};


#endif
