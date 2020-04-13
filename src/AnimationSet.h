/*
 *
 *	AnimationSet.h
 *
 *	April 13, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#include <iostream>
#include <map>

#include "TextureHolder.h"
#include "Animation.h"

#ifndef __ANIMATION_SET_H_
#define __ANIMATION_SET_H_

class AnimationSet {

public:
	
	AnimationSet();

	void setAnimation(std::string id);
	void draw(sf::RenderTarget& target, sf::RenderStates states);
	void setTexture(Texture::ID id);
	void setTextureHolder(TextureHolder* texHolder);
	void loadAnimationFromFile(const std::string& filename);

	~AnimationSet();

private:

	void parseAnimation(const std::string& id, std::ifstream& file);
	sf::IntRect parseFrame(const std::string& line);
	void addAnimation(const std::string& id, Animation* anim);

	void cleanAnimations();

	Texture::ID textureID;
	TextureHolder* textureHolder;
	std::string currentAnimation;
	std::map<std::string, Animation*> animations;
};

#endif
