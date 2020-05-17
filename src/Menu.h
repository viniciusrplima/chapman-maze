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

#include "AnimationSet.h"
#include "EntityContainer.h"
#include "TextureHolder.h"

struct SETUP {
	std::string anim_file;
	std::string sprite_file;
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

	// Codes for textures
	const Texture::ID DINO_GREEN = 300;
	const Texture::ID PRINCESS = 301;
	const Texture::ID CHICKEN = 302;
	const Texture::ID MAGE = 303;

	// List of characters animations and textures
	const std::vector<

		std::tuple<Texture::ID, std::string, std::string>

		> playerCharacters = {

		std::make_tuple( 
			DINO_GREEN, 
			"./animations/dino_green.anim", 
			"./assets/dino_green.png" ), 

		std::make_tuple( 
			PRINCESS, 
			"./animations/princess.anim", 
			"./assets/princess.png"), 

		std::make_tuple( 
			CHICKEN, 
			"./animations/chicken.anim", 
			"./assets/chicken_walk.png"),

		std::make_tuple( 
			MAGE, 
			"./animations/mage.anim", 
			"./assets/mage.png"),
	};

	bool closeMenu;	
	int currentCharacter;
	sf::Sprite sprite;
	AnimationSet *animation;
	sf::Font font;
	sf::Sprite title;
};

