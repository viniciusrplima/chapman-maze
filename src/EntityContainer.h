/*
 *
 *	EntityContainer.h
 *
 *	April 09, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Entity.h"
#include "Player.h"
#include "TextureHolder.h"

class EntityContainer {

public:

	EntityContainer();

	void draw(sf::RenderTarget&, sf::RenderStates);
	void setTextureHolder(TextureHolder* textures);
	void loadTextures();
	void createEntity(Texture::ID, float x, float y);
	Player* createPlayer(float x, float y);

	void saveWorldMap(const std::string& filename);
	void loadWorldMap(const std::string& filename);

	~EntityContainer();

private:

	void parseLine(const std::string& line);
	std::vector<std::string> splitLine(const std::string& line, char delimiter);
	void cleanEntities();

	TextureHolder* textures;
	std::vector<Entity*> entities;
};
