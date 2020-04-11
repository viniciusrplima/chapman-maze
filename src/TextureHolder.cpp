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

TextureHolder::~TextureHolder() {
}
