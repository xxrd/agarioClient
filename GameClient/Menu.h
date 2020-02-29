#pragma once
#include <string>
#include "WindowWrapper.h"
#include "Button.h"
#include "Textbox.h"

using namespace std;

class Menu {
private:
	string inputDate = "";
public:
	void showMenu(WindowWrapper& ww);
	std::string getInputDate();
};