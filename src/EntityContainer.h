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
#include <map>

#include "Entity.h"
#include "Player.h"
#include "TextureHolder.h"
#include "AnimationSet.h"

class EntityContainer {

public:

	EntityContainer();

	void draw(sf::RenderTarget&, sf::RenderStates);
	void update();
	void setTextureHolder(TextureHolder* textures);
	void loadTextures();
	void createBlock(Entity::Type, float x, float y);
	Player* createPlayer(float x, float y);

	void saveWorldMap(const std::string& filename);
	void loadWorldMap(const std::string& filename);

	~EntityContainer();

private:

	void parseLine(const std::string& line);
	std::vector<std::string> splitLine(const std::string& line, char delimiter);
	void cleanEntities();
	sf::Vector2i calculateBlockQuad(float x, float y);

	TextureHolder* textures;
	std::vector<Entity*> entities;
	std::map<std::tuple<int, int>, Entity*> ground;
	AnimationSet playerAnimation;
};
