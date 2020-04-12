/*
 *
 *	Camera.h
 *
 *	April 12, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#include <SFML/Graphics.hpp>

#ifndef __CAMERA_H_
#define __CAMERA_H_

#define CAM_ZOOM_FACTOR 1.1f

class Camera {

public:

	Camera();

	void zoomIn();
	void zoomOut();
	void setPosition(sf::Vector2f);
	void setPosition(float x, float y);
	void setWindowSize(sf::Vector2f);
	void setWindowSize(float w, float h);
	
	sf::RenderStates getRenderState();

	~Camera();

private:

	float zoom;
	sf::Vector2f position;
	sf::Vector2f windowSize;
};

#endif
