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
#include "Error.hpp"

TextureHolder::TextureHolder() : counter(100) {
}

Texture::ID TextureHolder::load(Texture::ID id, const std::string& filename) {

	std::unique_ptr<sf::Texture> texture(new sf::Texture);
	texture->loadFromFile(filename);

	textureMap.insert(std::make_pair(id, std::move(texture)));
	return id;
}

Texture::ID TextureHolder::load(const std::string& filename) {

	std::unique_ptr<sf::Texture> texture(new sf::Texture);
	texture->loadFromFile(filename);

	textureMap.insert(std::make_pair(counter, std::move(texture)));
	return counter++;
}

sf::Texture& TextureHolder::get(Texture::ID id) {
	auto found = textureMap.find(id);
	return *found->second;
}

TextureHolder::~TextureHolder() {
}
