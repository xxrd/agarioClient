#include "FoodList.h"

FoodList::FoodList() {}

FoodList::FoodList(ServerMessage::FoodList fl) {
	update(fl);
}

void FoodList::update(ServerMessage::FoodList fl) {
	if (foodList.size() > fl.food_size()) return;
	if (foodList.size() == 0) {
		foodList.clear();
		for (int i = 0; i < fl.food_size(); i++) {
			ServerMessage::Food food = fl.food(i);
			Food f(food.x(), food.y(), food.mass(), food.eaten());
			foodList.push_back(f);
		}
		return;
	}

	for (int i = 0; i < foodList.size(); i++) {

		foodList[i].setEaten(fl.food(i).eaten());
		if (foodList[i].isEaten()) continue;

		if (fl.food(i).x() != foodList[i].getX()) {
			foodList[i].setX(fl.food(i).x());
		}
		if (fl.food(i).y() != foodList[i].getY()) {
			foodList[i].setY(fl.food(i).y());
		}
	}
}

vector<Food>& FoodList::getFoodList() {
	return foodList;
}