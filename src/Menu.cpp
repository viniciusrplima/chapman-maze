/*
 *
 *	Menu.cpp 
 *
 *	April 22, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#include "Menu.h"

Menu::Menu() {
	currentCharacter = 1;
}

void Menu::run(sf::RenderWindow& window) {

	EntityContainer container;
	container.setTextureHolder(&textures);
	container.loadTextures();

	setupCharacter();

	while(window.isOpen() && !closeMenu) {

		sf::Event event;
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				window.close();
			}
			if(event.type == sf::Event::KeyPressed) {
				switch(event.key.code) {
					case sf::Keyboard::Return: 
						closeMenu = true;
						break;
					case sf::Keyboard::Left:
						currentCharacter++;
						currentCharacter %= playerCharacters.size();
						setupCharacter();
						break;
					case sf::Keyboard::Right:
						currentCharacter--;
						currentCharacter %= playerCharacters.size();
						setupCharacter();
						break;
				}
			}
		}

		render(window);
	}
}

void Menu::render(sf::RenderWindow& window) {

	sf::RenderStates states;
	states.transform.scale(3.0f, 3.0f);

	window.clear();

	animation -> draw(window, states);

	window.display();
}

SETUP Menu::getSetup() {
	SETUP setup;

	Texture::ID texID = std::get<0>(playerCharacters[currentCharacter]);
	std::string animFile = std::get<1>(playerCharacters[currentCharacter]);

	setup.tex = texID;
	setup.animFile = animFile;

	return setup;
}

void Menu::setupCharacter() {
	Texture::ID texID = std::get<0>(playerCharacters[currentCharacter]);
	std::string animFile = std::get<1>(playerCharacters[currentCharacter]);

	animation = new AnimationSet();
	animation -> setAnimation("DOWN");
	animation -> setTexture(texID);
	animation -> setTextureHolder(&textures);
	animation -> loadAnimationFromFile(animFile);
}

Menu::~Menu() {
}
