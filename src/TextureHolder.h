/*
 *
 *	TextureHolder.h
 *
 *	April 11, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */


#include <SFML/Graphics.hpp>
#include <map>

#include "Entity.h"

#ifndef __TEXTURE_HOLDER_H_
#define __TEXTURE_HOLDER_H_

namespace Texture {
	enum ID {
		SOLDIER, 
		WATER, 
		ROCK, 
		GRASS, 
		WALL, 
		VERTICAL_WALL,
		FLOOR, 

		DINO_GREEN,
		PRINCESS
	};
}

class TextureHolder {

public:

	TextureHolder();

	void load(Texture::ID id, const std::string& filename);
	sf::Texture& get(Texture::ID id);
	sf::Texture& get(Entity::Type type);

	~TextureHolder();

private:

	std::map<Texture::ID, std::unique_ptr<sf::Texture>> textureMap;

};

#endif
