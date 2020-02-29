#pragma once
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class Button {
private:
	sf::RectangleShape button;
	sf::Text text;
	int btnWidth;
	int btnHeight;
public:
	Button(string btnText, sf::Vector2f buttonSize, int charSize, sf::Color bgColor, sf::Color textColor);
	void setFont(sf::Font& fonts);
	void setBackColor(sf::Color color);
	void setTextColor(sf::Color color);
	void setPosition(sf::Vector2f point);
	void drawTo(sf::RenderWindow& window);
	bool isMouseOver(sf::RenderWindow& window);
};