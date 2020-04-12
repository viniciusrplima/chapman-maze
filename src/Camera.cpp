/*
 *
 *	Camera.cpp
 *
 *	April 12, 2020
 *	by Vinicius Rodrigues
 *
 *
 *
 */

#include <cmath>

#include "Camera.h"

Camera::Camera() {
	zoom = 1.0f;
	position.x = 0.0f;
	position.y = 0.0f;
	windowSize.x = 100.0f;
	windowSize.y = 100.0f;
}

void Camera::zoomIn() {
	zoom *= CAM_ZOOM_FACTOR;
}

void Camera::zoomOut() {
	zoom /= CAM_ZOOM_FACTOR;
}

void Camera::setPosition(sf::Vector2f pos) {
	position = pos;
}

void Camera::setPosition(float x, float y) {
	position.x = x;
	position.y = y;
}

void Camera::setWindowSize(sf::Vector2f size) {
	windowSize = size;
}

void Camera::setWindowSize(float w, float h) {
	windowSize.x = w;
	windowSize.y = h;
}

sf::RenderStates Camera::getRenderState() {

	sf::Transform transform;

	transform.scale(600.0f / windowSize.x, 480.0f / windowSize.y);
	transform.translate(windowSize.x / 2, windowSize.y / 2);
	transform.scale(zoom, zoom);
	transform.translate(-position.x, -position.y);

	return transform;
}

Camera::~Camera() {
}
