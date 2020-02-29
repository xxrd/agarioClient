#pragma once
#include <iostream>
#include "ServerMessage.pb.h"
#include <SFML/Graphics.hpp>
#include "config.h"
#include "CurrentPlayer.h"
#include "Food.h"
#include "FoodList.h"
#include "PlayersMap.h"

using namespace std;

class WindowWrapper {
private:
	sf::RenderWindow window;
	Camera& camera;
public:
	WindowWrapper(Camera& camera);
	void setTitle(string title);
	void setFps(int fps);
	void setCamera(Camera& camera);
	void updateCamera();
	float getWindowCenterPositionX() const;
	float getWindowCenterPositionY() const;
	void drawBackground(size_t step = 50, sf::Color color = sf::Color::Black, float borderLength = 1);
	void draw(FoodList foodList);
	void draw(PlayersMap playersMap);
	void draw(CurrentPlayer& cp);
	sf::RenderWindow& getWindow();
	void clear(sf::Color color);
	void display();
	void updateCameraSize();
};