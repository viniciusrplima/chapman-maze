/*
 *
 *	EntityContainer.h
 *
 *	April 09, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#include <SFML/Graphics.hpp>
#include <vector>

#include "Entity.h"
#include "TextureHolder.h"

class EntityContainer {

public:

	EntityContainer();

	void draw(sf::RenderTarget&, sf::RenderStates);
	void setTextureHolder(TextureHolder* textures);
	void loadTextures();
	void createEntity(Texture::ID, float x, float y);

	void saveWorldMap(const std::string& filename);

	~EntityContainer();

private:

	void cleanEntities();

	TextureHolder* textures;
	std::vector<Entity*> entities;
};
