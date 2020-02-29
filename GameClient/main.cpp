#include "config.h"
#include "NetworkManager.h"
#include "WindowWrapper.h"
#include "Menu.h"
#include "ClientMessageBuilder.h"
#include "CurrentPlayer.h"
#include "PlayersMap.h"

using namespace std;

int main() {
	NetworkManager networkManager(GAME_HOST, GAME_PORT);
	Camera camera;
	WindowWrapper ww(camera);
	FoodList foodList;
	PlayersMap playersMap;

	CurrentPlayer currentPlayer(camera);

	Menu m;
	m.showMenu(ww);
	string playerName = m.getInputDate();

	ClientMessageBuilder clientMsgBuilder;
	clientMsgBuilder.setType(ClientMessage::ClientMessage::MessageType::ClientMessage_MessageType_firstConnect);
	clientMsgBuilder.setName(playerName);

	networkManager.sendClientMessage(clientMsgBuilder.build());
	networkManager.receiveMessage();

	while (ww.getWindow().isOpen()) {
		sf::Event event;

		ServerMessage::ServerMessage serverMessage = networkManager.getLastServerMessage();
		ClientMessageBuilder clientMsgBuilder;

		ww.clear(sf::Color::White);

		switch (serverMessage.messagetype()) {
		case ServerMessage::ServerMessage::MessageType::ServerMessage_MessageType_gameInfo: {
			ww.drawBackground();

			if (serverMessage.has_foodlist())
				foodList.update(serverMessage.foodlist());
			ww.draw(foodList);

			if(serverMessage.has_playerlist()) 
				playersMap.update(serverMessage.playerlist());
			ww.draw(playersMap);

			if(serverMessage.has_currentplayer())
				currentPlayer.update(serverMessage.currentplayer());
			ww.draw(currentPlayer);

			ww.updateCamera();
			ww.display();

			clientMsgBuilder.setType(ClientMessage::ClientMessage::MessageType::ClientMessage_MessageType_playerInfo);

			while (ww.getWindow().pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					ww.getWindow().close();
				if (event.type == sf::Event::Resized) {
					ww.updateCameraSize();
					clientMsgBuilder.setWindowCenterPosition(ww.getWindowCenterPositionX(), ww.getWindowCenterPositionY());
				}
			}

			sf::Vector2i mousePosition = sf::Mouse::getPosition(ww.getWindow());
			clientMsgBuilder.setMousePosition(mousePosition.x, mousePosition.y);

			networkManager.sendClientMessage(clientMsgBuilder.build());
			networkManager.receiveMessage();

			break;

		}
		case ServerMessage::ServerMessage::MessageType::ServerMessage_MessageType_disconnect: {
			networkManager.connect(GAME_HOST, GAME_PORT);
			clientMsgBuilder.setWindowCenterPosition(ww.getWindowCenterPositionX(), ww.getWindowCenterPositionY());
			
			camera.getView().setCenter(ww.getWindowCenterPositionX(), ww.getWindowCenterPositionY());
			ww.updateCamera();

			m.showMenu(ww);
			string playerName = m.getInputDate();
			
			clientMsgBuilder = ClientMessageBuilder();
			clientMsgBuilder.setType(ClientMessage::ClientMessage::MessageType::ClientMessage_MessageType_firstConnect);
			clientMsgBuilder.setName(playerName);
			clientMsgBuilder.setWindowCenterPosition(ww.getWindowCenterPositionX(), ww.getWindowCenterPositionY());

			networkManager.sendClientMessage(clientMsgBuilder.build());
			networkManager.receiveMessage();

			break;
		}
		}
	}
}