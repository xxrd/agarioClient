#include "NetworkManager.h"

NetworkManager::NetworkManager(string host, int port) {
	//socket.setBlocking(false);
	socket.connect(host, port);
}

void NetworkManager::connect(string host, int port) {
	//socket.setBlocking(false);
	socket.connect(host, port);
}

void NetworkManager::sendClientMessage(ClientMessage::ClientMessage cm) {
	string str;
	cm.SerializeToString(&str);
	sendMessage(str);
}

ServerMessage::ServerMessage& NetworkManager::getLastServerMessage() {
	return lastServerMessage;
}

void NetworkManager::sendMessage(string data) {
	ClientMessage::ClientMessage* newMessage = new ClientMessage::ClientMessage();
	newMessage->ParseFromString(data);

	int size = newMessage->ByteSizeLong();
	char* buffer = new char[size];
	newMessage->SerializeToArray(buffer, size);

	if (socket.send(buffer, size) != sf::Socket::Done)
	{
		cerr << "error" << endl;
	}
}

void NetworkManager::receiveMessage() {
	char buffer[16384];
	std::size_t received = 0;

	if (socket.receive(buffer, sizeof(buffer), received) == sf::Socket::Status::Done) {
		ServerMessage::ServerMessage serverMessage;
		serverMessage.ParseFromArray(buffer, received);
		this->lastServerMessage = serverMessage;
	}
}