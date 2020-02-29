#include "ClientMessageBuilder.h"

ClientMessageBuilder::ClientMessageBuilder() {
	clientMessage.set_messagetype(ClientMessage::ClientMessage::MessageType::ClientMessage_MessageType_firstConnect);
}

void ClientMessageBuilder::setMousePosition(float mouseX, float mouseY) {
	ClientMessage::MousePosition* mousePosition = new ClientMessage::MousePosition();
	mousePosition->set_x(mouseX);
	mousePosition->set_y(mouseY);
	clientInformation->set_allocated_mouseposition(mousePosition);
}

void ClientMessageBuilder::setWindowCenterPosition(float windowCX, float windowCY) {
	ClientMessage::WindowCenterPosition* windowCenterPosition = new ClientMessage::WindowCenterPosition();
	windowCenterPosition->set_x(windowCX);
	windowCenterPosition->set_y(windowCY);
	clientInformation->set_allocated_windowcenterposition(windowCenterPosition);
}

void ClientMessageBuilder::setType(ClientMessage::ClientMessage::MessageType type) {
	clientMessage.set_messagetype(type);
}

ClientMessage::ClientMessage ClientMessageBuilder::build() {
	clientMessage.set_allocated_clientinformation(clientInformation);
	return clientMessage;
}

void ClientMessageBuilder::setName(string name) {
	clientMessage.set_playername(name);
}