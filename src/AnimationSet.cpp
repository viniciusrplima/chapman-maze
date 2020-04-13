/*
 *
 *	AnimationSet.cpp
 *
 *	April 13, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#include <sstream>
#include <fstream>

#include "AnimationSet.h"

AnimationSet::AnimationSet() {
}

void AnimationSet::setAnimation(std::string id) {
	currentAnimation = id;
}

void AnimationSet::draw(sf::RenderTarget& target, sf::RenderStates states) {
	auto found = animations.find(currentAnimation);
	found->second->draw(target, states);
}

void AnimationSet::setTexture(Texture::ID id){
	textureID = id;
}

void AnimationSet::setTextureHolder(TextureHolder* texHolder) {
	textureHolder = texHolder;
}

void AnimationSet::loadAnimationFromFile(const std::string& filename) {
	std::ifstream file(filename);
	std::string line = "";

	while(!file.eof()) {
		std::getline(file, line);
		
		if(line != "") {
			parseAnimation(line, file);
		}
	}
}

void AnimationSet::parseAnimation(const std::string& id, std::ifstream& file) {
	std::string line = "";

	std::getline(file, line);
	float duration = std::stof(line);

	Animation* anim = new Animation();
	anim->setTexture(textureHolder->get(textureID));
	anim->setDuration(duration);

	std::getline(file, line);
	int numOfFrames = std::stoi(line);

	for(int i = 0; i < numOfFrames; i++) {
		std::getline(file, line);
		sf::IntRect rect = parseFrame(line);
		anim->addFrame(rect.left, rect.top, rect.width, rect.height);
	}

	addAnimation(id, anim);
}

sf::IntRect AnimationSet::parseFrame(const std::string& line) {
	std::stringstream tokens(line);
	std::string token = "";

	sf::IntRect rect;

	tokens >> token;
	rect.left = std::stoi(token);

	tokens >> token;
	rect.top = std::stoi(token);

	tokens >> token;
	rect.width = std::stoi(token);

	tokens >> token;
	rect.height = std::stoi(token);

	return rect;
}

void AnimationSet::addAnimation(const std::string& id, Animation* anim) {
	animations.insert(std::make_pair(id, anim));
}

void AnimationSet::cleanAnimations() {
	for(auto i = animations.begin(); i != animations.end(); i++) {
		delete i->second;
	}
}

AnimationSet::~AnimationSet() {
	cleanAnimations();
}
