#pragma once
#include "Food.h"
#include "ServerMessage.pb.h"

using namespace std;

class FoodList {
private:
	vector<Food> foodList;
public:
	FoodList();
	FoodList(ServerMessage::FoodList fl);
	vector<Food>& getFoodList();
	void update(ServerMessage::FoodList fl);
};