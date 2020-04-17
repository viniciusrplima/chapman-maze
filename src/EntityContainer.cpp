/*
 *
 *	EntityContainer.cpp
 *
 *	April 09, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>

#include "Block.h"
#include "EntityContainer.h"


EntityContainer::EntityContainer() : playerAnimation() {
}

void EntityContainer::draw(sf::RenderTarget& target, sf::RenderStates states) {
	for(auto iter = ground.begin(); iter != ground.end(); iter++) {
		iter->second->draw(target, states);
	}
}

void EntityContainer::drawAddMark(sf::Vector2f pos, sf::RenderTarget& target, sf::RenderStates states) {
	auto quadPos = calculateBlockQuad(pos.x, pos.y);

	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(BLOCK_WIDTH, BLOCK_WIDTH));
	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineColor(sf::Color(120, 220, 120));
	rect.setOutlineThickness(1.0f);

	states.transform.translate(quadPos.x, quadPos.y);
	target.draw(rect, states);
}

void EntityContainer::drawDelMark(sf::Vector2f pos, sf::RenderTarget& target, sf::RenderStates states) {
	auto quadPos = calculateBlockQuad(pos.x, pos.y);

	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(BLOCK_WIDTH, BLOCK_WIDTH));
	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineColor(sf::Color(220, 120, 120));
	rect.setOutlineThickness(1.0f);

	states.transform.translate(quadPos.x, quadPos.y);
	target.draw(rect, states);
}

void EntityContainer::update() {
}

void EntityContainer::setTextureHolder(TextureHolder* textures) {
	this->textures = textures;
}

void EntityContainer::loadTextures() {
	textures->load(Texture::SOLDIER, "./assets/soldier.png");
	textures->load(Texture::WATER, "./assets/water.png");
	textures->load(Texture::ROCK, "./assets/rock.png");
	textures->load(Texture::GRASS, "./assets/grass.png");
	textures->load(Texture::WALL, "./assets/wall.png");
	textures->load(Texture::DINO_GREEN, "./assets/dino_green.png");
	textures->load(Texture::VERTICAL_WALL, "./assets/vertical_wall.png");
	textures->load(Texture::FLOOR, "./assets/floor.png");
}

void EntityContainer::createBlock(Entity::Type type, float x, float y) {

	auto blockQuad = calculateBlockQuad(x, y);
	auto pos = std::make_tuple(blockQuad.x, blockQuad.y);
	auto found = ground.find(pos);

	if(found != ground.end()) return;


	Texture::ID tex;

	switch(type) {
		case Entity::WATER: 
			tex = Texture::WATER;
			break;
		case Entity::ROCK:
			tex = Texture::ROCK;
			break;
		case Entity::GRASS:
			tex = Texture::GRASS;
			break;
		case Entity::WALL:
			tex = Texture::WALL;
			break;
		case Entity::VERTICAL_WALL:
			tex = Texture::VERTICAL_WALL;
			break;
		case Entity::FLOOR:
			tex = Texture::FLOOR;
			break;
	}

	Entity* entity = new Block(type, blockQuad.x, blockQuad.y, textures->get(tex));

	if(type == Entity::WALL || type == Entity::VERTICAL_WALL) entity->setPhysic(Entity::BLOCK);
	else entity->setPhysic(Entity::NONE);

	ground.insert(std::make_pair(pos, entity));
}

void EntityContainer::removeBlock(float x, float y) {
	auto quadPos = calculateBlockQuad(x, y);

	auto found = ground.find(std::make_tuple(quadPos.x, quadPos.y));
	if(found != ground.end()) {
		ground.erase(found);
	}
}

Player* EntityContainer::createPlayer(float x, float y) {

	playerAnimation.setAnimation("STOP_DOWN");
	playerAnimation.setTexture(Texture::DINO_GREEN);
	playerAnimation.setTextureHolder(textures);
	playerAnimation.loadAnimationFromFile("./animations/dino_green.anim");

	Player* player = new Player(x, y, &playerAnimation);
	return player;
}

void EntityContainer::saveWorldMap(const std::string& filename) {
	std::ofstream file(filename);
	
	if(!file) {
		std::cout << "Error: impossible to create " << filename << std::endl;
		return;
	}

	for(auto iter = ground.begin(); iter != ground.end(); iter++) {
		int entType = iter->second->getType();
		
		if(entType != Entity::PLAYER) {
			auto position = iter->second->getPosition();
	
			file << entType << ':'
			     << position.x << ':' 
			     << position.y << '\n';
		}
	}

	file.close();
}

void EntityContainer::loadWorldMap(const std::string& filename) {
	std::ifstream file(filename);

	if(!file) {
		std::cout << "Erro: " << filename << " don't exist" << std::endl;
		return;
	}

	std::string line = "";

	while(!file.eof()) {
		std::getline(file, line);
		parseLine(line);
	}
}

void EntityContainer::parseLine(const std::string& line) {
	auto tokens = splitLine(line, ':');

	if(line == "") return;

	Entity::Type type = (Entity::Type) std::stoi(tokens[0]);
	float posX = std::stof(tokens[1]);
	float posY = std::stof(tokens[2]);

	createBlock(type, posX, posY);
}

std::vector<std::string> EntityContainer::splitLine(const std::string& line, char delimiter) {
	std::vector<std::string> tokens;
	std::string token = "";

	for(int i = 0; i < line.length(); i++) {
		if(line[i] == delimiter) {
			if(token != "") {
				tokens.push_back(token);
				token = "";
			}
		}
		else {
			token += line[i];
		}
	}

	if(token != "") 
		tokens.push_back(token);

	return tokens;
}

sf::Vector2i EntityContainer::calculateBlockQuad(float x, float y) {
	int line = BLOCK_WIDTH * floor(y / BLOCK_WIDTH );
	int column = BLOCK_WIDTH * floor(x / BLOCK_WIDTH );
	return sf::Vector2i(column, line);
}

void EntityContainer::cleanEntities() {
	for(auto iter = ground.begin(); iter != ground.end(); iter++) {
		delete (iter->second);
	}
}

EntityContainer::~EntityContainer() {
	cleanEntities();
}
