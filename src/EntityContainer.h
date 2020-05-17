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

#ifndef __ENTITY_CONTAINER_H_
#define __ENTITY_CONTAINER_H_

class EntityContainer {

public:

	EntityContainer();

	void draw(sf::RenderTarget&, sf::RenderStates);
	void drawAddMark(sf::Vector2f, sf::RenderTarget&, sf::RenderStates);
	void drawDelMark(sf::Vector2f, sf::RenderTarget&, sf::RenderStates);
	void update();
	void loadTextures();
	void createBlock(Entity::Type, float x, float y);
	void removeBlock(float x, float y);
	Texture::ID getTextureFromEntity(Entity::Type);

	Player* createPlayer(float x, float y, const std::string&, const std::string&);
	void movePlayer(Player::Move, float);

	void saveWorldMap(const std::string& filename);
	void loadWorldMap(const std::string& filename);

	~EntityContainer();

private:
	
	Texture::ID WATER;
	Texture::ID ROCK;
	Texture::ID GRASS;
	Texture::ID WALL;
	Texture::ID VERTICAL_WALL;
	Texture::ID FLOOR;

	void parseLine(const std::string& line);
	std::vector<std::string> splitLine(const std::string& line, char delimiter);
	void cleanEntities();
	sf::Vector2i calculateBlockQuad(float x, float y);
	bool isMoveEnable(sf::Vector2f);

	std::map<std::tuple<int, int>, Entity*> ground;
	Player* player;
	AnimationSet playerAnimation;
};

#endif
