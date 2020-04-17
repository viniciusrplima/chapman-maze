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
		DINO_GREEN,
		FLOOR
	};
}

class TextureHolder {

public:

	TextureHolder();

	void load(Texture::ID id, const std::string& filename);
	sf::Texture& get(Texture::ID id);

	~TextureHolder();

private:

	std::map<Texture::ID, std::unique_ptr<sf::Texture>> textureMap;

};

#endif
