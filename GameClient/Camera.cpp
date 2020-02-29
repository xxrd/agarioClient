#include "Camera.h"

Camera::Camera() {
	view = sf::View(sf::FloatRect(0, 0, DEFAULT_CAMERA_WIDTH, DEFAULT_CAMERA_HEIGHT));
}

sf::View& Camera::getView() {
	return view;
}