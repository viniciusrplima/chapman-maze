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

#include "EntityContainer.h"


EntityContainer::EntityContainer() {
}

void EntityContainer::draw(sf::RenderTarget& target, sf::RenderStates states) {
	for(int i = 0; i < entities.size(); i++) {
		entities[i]->draw(target, states);
	}
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
}

void EntityContainer::createEntity(Texture::ID id, float x, float y) {
	Entity* entity = new Entity(id, x, y, textures);
	entities.push_back(entity);
}

Player* EntityContainer::createPlayer(float x, float y) {
	Player* player = new Player(Texture::SOLDIER, x, y, textures);
	entities.push_back(player);
	return player;
}

void EntityContainer::saveWorldMap(const std::string& filename) {
	std::ofstream file(filename);
	
	if(!file) {
		std::cout << "Error: impossible to create " << filename << std::endl;
		return;
	}

	for(int i = 0; i < entities.size(); i++) {
		int texType = entities[i]->getTexture();
		auto position = entities[i]->getPosition();

		file << texType << ':'
		     << position.x << ':' 
		     << position.y << '\n';
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

	Texture::ID tex = (Texture::ID) std::stoi(tokens[0]);
	float posX = std::stof(tokens[1]);
	float posY = std::stof(tokens[2]);

	createEntity(tex, posX, posY);
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

void EntityContainer::cleanEntities() {
	for(int i = 0; i < entities.size(); i++) {
		delete entities[i];
	}
}

EntityContainer::~EntityContainer() {
	cleanEntities();
}
