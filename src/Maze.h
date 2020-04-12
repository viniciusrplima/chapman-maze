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

#include "EntityContainer.h"
#include "Camera.h"

#define PLAYER_SPEED 10.0f

class Maze {

public: 
	
	Maze();

	void run();
	void update();
	void render();
	void eventHandle(sf::Event);
	void keyboardHandle(sf::Event);

	~Maze();

private:

	EntityContainer world;
	sf::RenderWindow window;
	Camera camera;
	Player* player;
	Texture::ID hand;
};
