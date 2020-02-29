#include "WindowWrapper.h"

WindowWrapper::WindowWrapper(Camera& camera) : window(sf::VideoMode(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT), GAME_TITLE), camera(camera) {
	window.setFramerateLimit(DEFAULT_MAX_FPS);
}

void WindowWrapper::setTitle(string title) {
	window.setTitle(title);
}

void WindowWrapper::setFps(int fps) {
	window.setFramerateLimit(fps);
}

void WindowWrapper::setCamera(Camera& camera) {
	this->camera = camera;
	window.setView(camera.getView());
}

void WindowWrapper::updateCameraSize() {
	camera.getView().setSize(window.getSize().x, window.getSize().y);
}

void WindowWrapper::updateCamera() {
	window.setView(camera.getView());
}

float WindowWrapper::getWindowCenterPositionX() const {
	sf::Vector2u windowSize = window.getSize();
	return windowSize.x / 2;
}

float WindowWrapper::getWindowCenterPositionY() const {
	sf::Vector2u windowSize = window.getSize();
	return windowSize.y / 2;
}

void WindowWrapper::drawBackground(size_t step, sf::Color color, float borderLength) {
	for (size_t i = step; i < GAME_HEIGHT; i += step) {
		sf::RectangleShape lineX(sf::Vector2f(GAME_HEIGHT, borderLength));
		lineX.setFillColor(color);
		lineX.setPosition(0, (float)i);
		window.draw(lineX);
	}
	for (size_t i = step; i < GAME_WIDTH; i += step) {
		sf::RectangleShape lineX(sf::Vector2f(borderLength, GAME_WIDTH));
		lineX.setFillColor(color);
		lineX.setPosition((float)i, 0);
		window.draw(lineX);
	}
}

void WindowWrapper::draw(FoodList foodList) {
	vector<Food> fl = foodList.getFoodList();
	for (int i = 0; i < fl.size(); i++) {
		if (fl[i].isEaten()) continue;
		window.draw(fl[i].getCircle());
	}
}

void WindowWrapper::draw(PlayersMap playersMap) {
	map<int, Player> pm = playersMap.getPlayersMap();

	for (pair<int, Player> p : pm) {
		window.draw(p.second.getCircle());
	}
}

void WindowWrapper::draw(CurrentPlayer& cp) {
	window.draw(cp.getCircle());
}

sf::RenderWindow& WindowWrapper::getWindow() {
	return window;
}

void WindowWrapper::clear(sf::Color color) {
	window.clear(color);
}

void WindowWrapper::display() {
	window.display();
}