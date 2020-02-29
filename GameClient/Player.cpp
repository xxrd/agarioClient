#include "Player.h"

Player::Player() : x(0), y(0), mass(0), name(""), id(0) {}

Player::Player(float x, float y, float mass, string name, int id) : x(x), y(y), mass(mass), name(name), id(id) {
	circle.setRadius(massToRadius(mass));
	circle.setFillColor(color);
	circle.setOutlineThickness(border);
	circle.setOrigin(circle.getRadius(), circle.getRadius());
	circle.setPosition(x, y);
}

void Player::setBorder(int border) {
	this->border = border;
	circle.setOutlineThickness(border);
}

void Player::setFillColor(sf::Color color) {
	this->color = color;
	circle.setFillColor(color);
}

void Player::setMass(float n) {
	this->mass = n;
	circle.setRadius(massToRadius(mass));
	circle.setOrigin(circle.getRadius(), circle.getRadius());
}

float Player::getRadius() const {
	return circle.getRadius();
}

float Player::getX() const {
	auto playerPosition = circle.getPosition();
	return playerPosition.x;
}

float Player::getY() const {
	auto playerPosition = circle.getPosition();
	return playerPosition.y;
}

sf::CircleShape& Player::getCircle() {
	return circle;
}

void Player::setPosition(float x, float y) {
	circle.setPosition(x, y);
}

void Player::setName(string name) {
	this->name = name;
}

int Player::getId() const {
	return id;
}

void Player::setId(int id) {
	this->id = id;
}

void Player::setX(float x) {
	this->x = x;
}

void Player::setY(float y) {
	this->y = y;
}