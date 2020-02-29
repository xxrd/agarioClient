#include "Food.h"

Food::Food(float x, float y, float mass, bool eaten) : x(x), y(y), mass(mass), eaten(eaten) {
	circle.setRadius(massToRadius(mass));
	circle.setFillColor(sf::Color(color));
	circle.setOutlineThickness(border);
	circle.setPosition(x, y);
	circle.setOrigin(circle.getRadius(), circle.getRadius());
}

void Food::setBorder(int border) {
	this->border = border;
	circle.setOutlineThickness(border);
}

void Food::setFillColor(sf::Color color) {
	this->color = color;
	circle.setFillColor(color);
}

void Food::setMass(float n) {
	this->mass = mass;
	circle.setRadius(massToRadius(mass));
}

float Food::getRadius() const {
	return circle.getRadius();
}

float Food::getX() const {
	return x;
}

float Food::getY() const {
	return y;
}

float Food::getMass() const {
	return mass;
}

sf::CircleShape& Food::getCircle() {
	return circle;
}

void Food::setX(float x) {
	circle.setPosition(x, y);
	this->x = x;
}

void Food::setY(float y) {
	circle.setPosition(x, y);
	this->y = y;
}

void Food::setEaten(bool b) {
	eaten = b;
}

bool Food::isEaten() {
	return eaten;
}