#pragma once
#include "Player.h"
#include <string>
#include "Camera.h"

using namespace std;

class CurrentPlayer :
	public Player {
private:
	Camera& camera;
public:
	CurrentPlayer(Camera& camera, float x = 0, float y = 0, float mass = 0, string name = "", int id = 0);
	void update(ServerMessage::CurrentPlayer cp);
	void attachCamera(Camera& camera);
	void updateCameraPosition();
};