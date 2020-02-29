#pragma once
#include <SFML/Graphics.hpp>
#include "config.h"

class Camera {
private:
	float x;
	float y;
	sf::View view;
public:
	Camera();
	sf::View& getView();
};