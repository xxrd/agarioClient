#include "Textbox.h"

void Textbox::deleteLastChar() {
	std::string t = text.str();
	std::string newT = "";
	for (int i = 0; i < t.length() - 1; i++) {
		newT += t[i];
	}
	text.str("");
	text << newT;
	textbox.setString(text.str() + "_");
}

void Textbox::inputLogic(int charTyped) {

	if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
		text << static_cast<char>(charTyped);
	}

	else if (charTyped == DELETE_KEY) {
		if (text.str().length() > 0) {
			deleteLastChar();
		}
	}

	textbox.setString(text.str() + "_");
}
Textbox::Textbox(int size, sf::Color color, bool sel) {
	textbox.setCharacterSize(size);
	textbox.setFillColor(color);
	isSelected = sel;


	if (isSelected)
		textbox.setString("_");
	else
		textbox.setString("");
}

void Textbox::setFont(sf::Font& fonts) {
	textbox.setFont(fonts);
}

void Textbox::setPosition(sf::Vector2f point) {
	textbox.setPosition(point);
}

void Textbox::setLimit(bool ToF) {
	hasLimit = ToF;
}

void Textbox::setLimit(bool ToF, int lim) {
	hasLimit = ToF;
	limit = lim - 1;
}

void Textbox::setSelected(bool sel) {
	isSelected = sel;

	if (!sel) {
		std::string t = text.str();
		std::string newT = "";
		for (int i = 0; i < t.length(); i++) {
			newT += t[i];
		}
		textbox.setString(newT);
	}
}

std::string Textbox::getText() {
	return text.str();
}

void Textbox::drawTo(sf::RenderWindow& window) {
	window.draw(textbox);
}

void Textbox::typedOn(sf::Event input) {
	if (isSelected) {
		int charTyped = input.text.unicode;

		if (charTyped < 128) {
			if (hasLimit) {
				if (text.str().length() <= limit) {
					inputLogic(charTyped);
				}
				else if (text.str().length() > limit && charTyped == DELETE_KEY) {
					deleteLastChar();
				}
			}
			else {
				inputLogic(charTyped);
			}
		}
	}
}