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
	float zoom;
	sf::Vector2f position;
};
