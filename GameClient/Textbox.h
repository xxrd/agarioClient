#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

using namespace std;

class Textbox {
private:
	sf::Text textbox;
	std::ostringstream text;
	bool isSelected = false;
	bool hasLimit = false;
	int limit = 0;
	void deleteLastChar();
	void inputLogic(int charTyped);
public:
	Textbox(int size, sf::Color color, bool sel);
	void setFont(sf::Font& fonts);
	void setPosition(sf::Vector2f point);
	void setLimit(bool ToF);
	void setLimit(bool ToF, int lim);
	void setSelected(bool sel);
	std::string getText();
	void drawTo(sf::RenderWindow& window);
	void typedOn(sf::Event input);
};