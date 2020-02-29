#pragma once
#include <SFML/Graphics.hpp>
#include "util.h"

using namespace std;

class Food {
private:
	float x;
	float y;
	float mass;
	bool eaten = false;
	sf::CircleShape circle;
	int border = 1;
	sf::Color color = sf::Color(randomInRange(0, 255), randomInRange(0, 255), randomInRange(0, 255));
public:
	Food(float x, float y, float mass, bool eaten);
	void setBorder(int border);
	void setFillColor(sf::Color color);
	void setMass(float n);
	float getRadius() const;
	float getX() const;
	float getY() const;
	void setX(float x);
	void setY(float y);
	void setEaten(bool b);
	bool isEaten();
	float getMass() const;
	sf::CircleShape& getCircle();
};