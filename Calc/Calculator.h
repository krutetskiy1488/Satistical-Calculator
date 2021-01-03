#pragma once
#include <iostream>
#include <string>
#include <vector>


#include <SFML/Graphics.hpp>

#include "Button.h"
#include "TextBox.h"
#include "MathHelper.h"
#include "TextInput.h"

using namespace sf;
using namespace std;

class Calculator
{
public:
	Calculator(int width, int height, string name);

	void run();
private:
	RenderWindow _window;
	vector<TextBox>  texts;
	vector<Button> buttons;
	vector<TextInput> inputs;

	int highBound;
	int lowBound;

	void events();
	void display();
};

