#pragma once
#include "ServerMessage.pb.h"
#include "Player.h"

class PlayersMap {
private:
	map<int, Player> playersMap;
public:
	PlayersMap();
	map<int, Player>& getPlayersMap();
	void update(ServerMessage::PlayerList pl);
};