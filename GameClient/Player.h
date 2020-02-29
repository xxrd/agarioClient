#pragma once
#include <string>
#include "ServerMessage.pb.h"
#include "ClientMessage.pb.h"
#include <SFML/Graphics.hpp>
#include "util.h"

using namespace std;

class Player {
protected:
	float x;
	float y;
	float mass;
	int id;
	string name;
	sf::CircleShape circle;
	int border = 1;
	sf::Color color = sf::Color(randomInRange(0, 255), randomInRange(0, 255), randomInRange(0, 255));
public:
	Player();
	Player(float x, float y, float mass, string name, int id);
	void setBorder(int border);
	void setFillColor(sf::Color color);
	void setMass(float n);
	float getRadius() const;
	float getX() const;
	float getY() const;
	void setX(float x);
	void setY(float x);
	int getId() const;
	void setId(int id);
	void setName(string name);
	void setPosition(float x, float y);
	sf::CircleShape& getCircle();
};