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
	// Draw all blocks
	for(auto iter = ground.begin(); iter != ground.end(); iter++) {
		iter->second->draw(target, states);
	}
}

// Draw green mark for block addition
void EntityContainer::drawAddMark(sf::Vector2f pos, sf::RenderTarget& target, sf::RenderStates states) {
	auto quadPos = calculateBlockQuad(pos.x, pos.y);

	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(BLOCK_WIDTH, BLOCK_WIDTH));
	rect.setFillColor(sf::Color(120, 220, 120, 200));

	states.transform.translate(quadPos.x, quadPos.y);
	target.draw(rect, states);
}

// Draw red mark for block deletion
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

// Load sprites for blocks
void EntityContainer::loadTextures() {
	WATER = g_pTextureHolder->load("./assets/water.png");
	ROCK = g_pTextureHolder->load("./assets/rock.png");
	GRASS = g_pTextureHolder->load("./assets/grass.png");
	WALL = g_pTextureHolder->load("./assets/wall.png");
	VERTICAL_WALL = g_pTextureHolder->load("./assets/vertical_wall.png");
	FLOOR = g_pTextureHolder->load("./assets/floor.png");
}

void EntityContainer::createBlock(Entity::Type type, float x, float y) {

	auto blockQuad = calculateBlockQuad(x, y);
	auto pos = std::make_tuple(blockQuad.x, blockQuad.y);
	auto found = ground.find(pos);

	if(found != ground.end()) return;

	Texture::ID tex = getTextureFromEntity(type);

	Entity* entity = new Block(type, blockQuad.x, blockQuad.y, g_pTextureHolder->get(tex));

	if(type == Entity::WALL || 
	   type == Entity::VERTICAL_WALL || 
	   type == Entity::WATER )
		entity->setPhysic(Entity::BLOCK);
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

Texture::ID EntityContainer::getTextureFromEntity(Entity::Type type) {
	Texture::ID tex;

	// Choose texture for Entity type
	switch(type) {
		case Entity::WATER: 
			tex = WATER;
			break;
		case Entity::ROCK:
			tex = ROCK;
			break;
		case Entity::GRASS:
			tex = GRASS;
			break;
		case Entity::WALL:
			tex = WALL;
			break;
		case Entity::VERTICAL_WALL:
			tex = VERTICAL_WALL;
			break;
		case Entity::FLOOR:
			tex = FLOOR;
			break;
	}

	return tex;
}

Player* EntityContainer::createPlayer(
		float x, 
		float y, 
		const std::string& spriteFile, 
		const std::string& animFile) {


	Texture::ID id = g_pTextureHolder->load(spriteFile);
	playerAnimation.setAnimation("STOP_DOWN");
	playerAnimation.setTextureID(id);
	playerAnimation.loadAnimationFromFile(animFile);

	player = new Player(x, y, &playerAnimation);
	return player;
}

void EntityContainer::movePlayer(Player::Move move, float deltaTime) {
	auto pos = player->getPosition();

	switch(move) {
		case Player::LEFT: 
			pos.x -= PLAYER_SPEED * deltaTime;
			break;
		case Player::RIGHT: 
			pos.x += PLAYER_SPEED * deltaTime;
			break;
		case Player::UP: 
			pos.y -= PLAYER_SPEED * deltaTime;
			break;
		case Player::DOWN: 
			pos.y += PLAYER_SPEED * deltaTime;
			break;
	}

	sf::Vector2f top_left(pos.x - PLAYER_WIDTH / 2, pos.y);
	sf::Vector2f down_left(pos.x - PLAYER_WIDTH / 2, pos.y + PLAYER_HEIGHT / 2);
	sf::Vector2f top_right(pos.x + PLAYER_WIDTH / 2, pos.y);
	sf::Vector2f down_right(pos.x + PLAYER_WIDTH / 2, pos.y + PLAYER_HEIGHT / 2);

	if(isMoveEnable(top_left) &&
	   isMoveEnable(down_left) &&
	   isMoveEnable(top_right) &&
	   isMoveEnable(down_right)) {

		player->setPosition(pos.x, pos.y);
		
		switch(move) {
			case Player::LEFT:
				player->left();
				break;
			case Player::RIGHT:
				player->right();
				break;
			case Player::UP:
				player->up();
				break;
			case Player::DOWN:
				player->down();
				break;
		}
	}
}

bool EntityContainer::isMoveEnable(sf::Vector2f pos) {
	auto quadPos = calculateBlockQuad(pos.x, pos.y);
	auto found = ground.find(std::make_pair(quadPos.x, quadPos.y));

	if(found != ground.end() && found->second->getPhysic() == Entity::BLOCK)
		return false;
	return true;
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
