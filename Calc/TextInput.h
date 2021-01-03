#pragma once
#include "Button.h"
class TextInput : public Button
{
public:
	void set(Font& font, int x, int y, string name);

	void setValue(string value) { _value = value; _text.setString(_name + _value); }
	void activate(RenderWindow& window);
	bool update(char value);
	int getValue() { return stoi(_value); }
private:
	bool _active;
	string _name;
	string _value;
};

