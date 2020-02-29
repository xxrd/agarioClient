#pragma once
#include <string>
#include <iostream>
#include <SFML/Network.hpp>
#include "ServerMessage.pb.h"
#include "ClientMessage.pb.h"

using namespace std;

class NetworkManager {
private:
	sf::TcpSocket socket;
	ServerMessage::ServerMessage lastServerMessage;
public:
	NetworkManager(string host, int port);
	void sendClientMessage(ClientMessage::ClientMessage cm);
	ServerMessage::ServerMessage& getLastServerMessage();
	void sendMessage(string data);
	void receiveMessage();
	void connect(string host, int port);
};