/*
 *
 *	Menu.h
 *
 *	April 22, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#include <iostream>
#include <vector>
#include <tuple>

#include "Maze.h"

struct SETUP {
	Texture::ID tex;
	std::string animFile;
};


class Menu {

public:
	Menu();

	void run(sf::RenderWindow& window);
	void render(sf::RenderWindow& window);
	SETUP getSetup();

	~Menu();

private: 

	void setupCharacter();

	const std::vector<

		std::tuple<Texture::ID, std::string>

		> playerCharacters = {

		// List of characters
		std::make_tuple( Texture::DINO_GREEN, "./animations/dino_green.anim" ), 
		std::make_tuple( Texture::PRINCESS, "./animations/princess.anim" ), 

	};

	bool closeMenu;	
	int currentCharacter;
	TextureHolder textures;
	sf::Sprite sprite;
	AnimationSet *animation;
};

