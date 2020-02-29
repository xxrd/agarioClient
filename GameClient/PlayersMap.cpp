#include "ServerMessage.pb.h"
#include "PlayersMap.h"


PlayersMap::PlayersMap() {}

void PlayersMap::update(ServerMessage::PlayerList pl) {
	if (playersMap.size() == 0) {
		for (int i = 0; i < pl.player_size(); i++) {
			ServerMessage::Player player = pl.player(i);
			Player p(player.x(), player.y(), player.mass(), player.name(), player.id());
			playersMap[player.id()] = p;
		}
		return;
	}
	set<int> ids;
	for (int i = 0; i < pl.player_size(); i++) {
		ServerMessage::Player player = pl.player(i);
		ids.insert(player.id());

		if (playersMap.find(player.id()) != playersMap.end()) {
			playersMap[player.id()].setPosition(player.x(), player.y());
			playersMap[player.id()].setMass(player.mass());
			playersMap[player.id()].setId(player.id());
		}
		else {
			Player p(player.x(), player.y(), player.mass(), player.name(), player.id());
			playersMap[player.id()] = p;
		}
	}

	std::map<int, Player>::iterator it = playersMap.begin();
	while (it != playersMap.end()) {
		if (ids.find(it->first) == ids.end()) {
			it = playersMap.erase(it);
			continue;
		}
		it++;
	}
}

map<int, Player>& PlayersMap::getPlayersMap() {
	return playersMap;
}