/*
 *
 *	TextureHolder.cpp
 *
 *	April 11, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#include "TextureHolder.h"

TextureHolder::TextureHolder() {
}

void TextureHolder::load(Texture::ID id, const std::string& filename) {
	std::unique_ptr<sf::Texture> texture(new sf::Texture);
	texture->loadFromFile(filename);

	textureMap.insert(std::make_pair(id, std::move(texture)));
}

sf::Texture& TextureHolder::get(Texture::ID id) {
	auto found = textureMap.find(id);
	return *found->second;
}

sf::Texture& TextureHolder::get(Entity::Type type) {
	Texture::ID tex;

	switch(type) {
		case Entity::WATER: 
			tex = Texture::WATER;
			break;
		case Entity::ROCK:
			tex = Texture::ROCK;
			break;
		case Entity::GRASS:
			tex = Texture::GRASS;
			break;
		case Entity::WALL:
			tex = Texture::WALL;
			break;
		case Entity::VERTICAL_WALL:
			tex = Texture::VERTICAL_WALL;
			break;
		case Entity::FLOOR:
			tex = Texture::FLOOR;
			break;
	}

	return get(tex);
}

TextureHolder::~TextureHolder() {
}
