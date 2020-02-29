#include "Menu.h"

void Menu::showMenu(WindowWrapper& ww) {

	sf::RenderWindow& window = ww.getWindow();

	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
		std::cout << "Font not found!\n";
	Textbox text1(20, sf::Color::White, true);
	text1.setPosition({ 100, 100 });
	text1.setLimit(true, 30);
	text1.setFont(font);

	Button btn1("Enter", { 200, 100 }, 30, sf::Color::Yellow, sf::Color::Black);
	btn1.setFont(font);
	btn1.setPosition({ 100, 150 });

	while (window.isOpen()) {

		sf::Event Event;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			text1.setSelected(true);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			text1.setSelected(false);
		}

		while (window.pollEvent(Event)) {
			switch (Event.type) {

			case sf::Event::Closed:
				window.close();
			case sf::Event::TextEntered:
				text1.typedOn(Event);
			case sf::Event::MouseMoved:
				if (btn1.isMouseOver(window)) {
					btn1.setBackColor(sf::Color::Magenta);
				}
				else {
					btn1.setBackColor(sf::Color::Green);
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (btn1.isMouseOver(window)) {
					inputDate = text1.getText();
					return;
				}
			}
		}

		window.clear();
		text1.drawTo(window);
		btn1.drawTo(window);
		window.display();
	}
}

std::string Menu::getInputDate() {
	return inputDate;
}