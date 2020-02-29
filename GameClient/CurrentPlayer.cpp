#include "CurrentPlayer.h"

CurrentPlayer::CurrentPlayer(Camera& camera, float x, float y, float mass, string name, int id) : Player(x, y, mass, name, id), camera(camera) {}

void CurrentPlayer::update(ServerMessage::CurrentPlayer cp) {
	setPosition(cp.x(), cp.y());
	setMass(cp.mass());
	setName(cp.name());
	updateCameraPosition();
}

void CurrentPlayer::attachCamera(Camera& camera) {
	this->camera = camera;
	updateCameraPosition();
}

void CurrentPlayer::updateCameraPosition() {
	camera.getView().setCenter(getX(), getY());
}