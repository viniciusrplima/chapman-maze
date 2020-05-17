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
	currentCharacter = playerCharacters.size() - 1;
}

void Menu::run(sf::RenderWindow& window) {


	for(auto character = playerCharacters.begin(); 
	    character != playerCharacters.end(); character++) {
		
		Texture::ID id = std::get<0>(*character);
		std::string filename = std::get<2>(*character);

		g_pTextureHolder->load(id, filename);
	}

	setupCharacter();

	sf::Texture titleTex;
	titleTex.loadFromFile("./assets/title.png");
	title.setTexture(titleTex);


	if(!font.loadFromFile("./fonts/PressStart2P-Regular.ttf")) {
		std::cout << "Error loading font" << std::endl;
	}

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

	auto wndSize = window.getSize();

	sf::RenderStates states;
	states.transform.scale(600.0f / wndSize.x, 480.0f / wndSize.y);

	window.clear(sf::Color(10, 10, 40, 255));

	// Title
	sf::Transform titleTransform;
	titleTransform.translate(300.0f, 80.0f);
	titleTransform *= states.transform;
	auto titleRect = title.getLocalBounds();
	titleTransform.translate(-titleRect.width / 2, 0.0f);

	window.draw(title, titleTransform);

	// Character
	sf::Transform playerTransform;
	playerTransform.translate(300.0f, 240.0f);
	playerTransform.scale(4.0f, 4.0f);
	playerTransform *= states.transform;
	playerTransform.translate(-PLAYER_WIDTH / 2, -PLAYER_HEIGHT / 2);
	animation -> draw(window, playerTransform);

	// Controllers
	sf::Transform controlTransform;
	sf::ConvexShape triangle;
	triangle.setPointCount(3);
	triangle.setPoint(0, sf::Vector2f(-5.0f, 0.0f));
	triangle.setPoint(1, sf::Vector2f(0.0f, 5.0f));
	triangle.setPoint(2, sf::Vector2f(0.0f, -5.0f));	
	triangle.setFillColor(sf::Color(120, 220, 120, 200));
	triangle.setPosition(-30.0f, 0.0f);

	controlTransform.translate(300.0f, 240.0f);
	controlTransform.scale(5.0f, 5.0f);

	window.draw(triangle, controlTransform * states.transform);
	controlTransform.rotate(180.0f);
	window.draw(triangle, controlTransform * states.transform);

	// Enter Message
	sf::Transform msgTransform;
	sf::Text msgText("Press ENTER to select character", font);
	auto rect = msgText.getLocalBounds();
	msgText.move(-rect.width / 2, 0.0f);
	msgTransform.translate(300.0f, 400.0f);
	msgTransform *= states.transform;
	msgTransform.scale(0.4f, 0.4f);
	
	window.draw(msgText, msgTransform);

	window.display();
}

SETUP Menu::getSetup() {
	SETUP setup;

	std::string animFile = std::get<1>(playerCharacters[currentCharacter]);
	std::string spriteFile = std::get<2>(playerCharacters[currentCharacter]);

	setup.anim_file = animFile;
	setup.sprite_file = spriteFile;

	return setup;
}

void Menu::setupCharacter() {
	Texture::ID texID = std::get<0>(playerCharacters[currentCharacter]);
	std::string animFile = std::get<1>(playerCharacters[currentCharacter]);

	animation = new AnimationSet();
	animation -> setAnimation("DOWN");
	animation -> setTextureID(texID);
	animation -> loadAnimationFromFile(animFile);
}

Menu::~Menu() {
}
