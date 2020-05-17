/*
 *
 *	Chapman Maze
 *
 *
 *	April 09, 2020
 *	by Vinicius Rodrigues
 *
 *
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/Maze.h"
#include "src/Menu.h"
#include "src/Error.hpp"

int main() {

	try {
		sf::RenderWindow window(sf::VideoMode(600.0f, 480.0f), "Chapman Maze");
		Menu menu;
		menu.run(window);
		auto setup = menu.getSetup();
        
		Maze maze;
		maze.run(window, setup.sprite_file, setup.anim_file);
	}
	catch(Error error) {
		std::cout << "Error: " << error.getMessage() << std::endl;
	}
}
