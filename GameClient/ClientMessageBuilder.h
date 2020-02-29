#pragma once
#include "ClientMessage.pb.h"

using namespace std;

class ClientMessageBuilder {
private:
	ClientMessage::ClientMessage clientMessage;
	ClientMessage::ClientInformation* clientInformation = new ClientMessage::ClientInformation();
public:
	ClientMessageBuilder();
	void setMousePosition(float mouseX, float mouseY);
	void setWindowCenterPosition(float windowCX, float windowCY);
	void setType(ClientMessage::ClientMessage::MessageType type);
	ClientMessage::ClientMessage build();
	void setName(string name);
};