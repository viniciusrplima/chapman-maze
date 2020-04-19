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

#include "HandState.h"
#include "TextureHolder.h"

class HUD {

public:
	HUD();

	void setHandState(HandState* hand);
	void setTextureHolder(TextureHolder* textureHolder);
	void setAspect(sf::Vector2f);
	void draw(sf::RenderTarget& target);

	~HUD();


private:
	HandState* hand;
	TextureHolder* textureHolder;
	sf::Vector2f aspect;
};
