/*
 *
 *	HUD.h
 *
 *	April 19, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#include <SFML/Graphics.hpp>
#include <iostream>

#include "HandState.h"
#include "TextureHolder.h"

#ifndef __HUD_H_
#define __HUD_H_

class HUD {

public:
	HUD();

	void setHandState(HandState* hand);
	void setAspect(sf::Vector2f);
	void draw(sf::RenderTarget& target);

	~HUD();


private:
	HandState* hand;
	sf::Vector2f aspect;
	sf::Font font;
};

#endif
