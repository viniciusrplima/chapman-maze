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

int main() {
	sf::RenderWindow window(sf::VideoMode(600.0f, 480.0f), "Chapman Maze");
	Menu menu;
	menu.run(window);
	auto setup = menu.getSetup();

	Maze maze;
	maze.run(window, setup.tex, setup.animFile);
}
