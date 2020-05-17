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
#include "Singleton.hpp"

#ifndef __TEXTURE_HOLDER_H_
#define __TEXTURE_HOLDER_H_

#define g_pTextureHolder TextureHolder::Instance()

namespace Texture {

	typedef unsigned int ID;
}

// Singleton for Textures
// Accessible in whole system
class TextureHolder: public Singleton<TextureHolder> {

public:

	TextureHolder();

	Texture::ID load(Texture::ID id, const std::string& filename);
	Texture::ID load(const std::string& filename);
	sf::Texture& get(Texture::ID id);

	~TextureHolder();

private:

	Texture::ID counter;
	std::map<Texture::ID, std::unique_ptr<sf::Texture>> textureMap;
};

#endif
