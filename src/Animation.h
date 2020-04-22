/*
 *
 *	Animation.h
 *
 *	April 13, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#include <SFML/Graphics.hpp>
#include <vector>

#ifndef __ANIMATION_H_
#define __ANIMATION_H_

#define PLAYER_WIDTH 20.0f
#define PLAYER_HEIGHT 30.0f

class Animation {

public:

	Animation();

	void draw(sf::RenderTarget& target, sf::RenderStates states);
	void addFrame(float x, float y, float w, float h); 
	void reset();
	void setTexture(sf::Texture& texture);
	void setDuration(float duration);
	float getDuration();

	~Animation();

private:

	sf::Sprite sprite;
	sf::Clock clock;
	sf::Time elapsedTime;
	float duration;
	std::vector<sf::IntRect> frames;
};

#endif
