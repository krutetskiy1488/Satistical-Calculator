#pragma once
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class TextBox : public Drawable
{
public:
	void set(Font& font, int x, int y, int width, int height, string name);
	string getValue() { return _value; }
	void setValue(string value) { _value = value; _text.setString(_name + _value); }
	void addValue(string value) { _value += value; _text.setString(_name + _value); }
	void addSpace();
	void removeLast();
	void clear() { _value = ""; _text.setString(_name); }
private:
	RectangleShape _bound;
	Text _text;
	string _name;
	string _value;

	// Унаследовано через Drawable
	virtual void draw(RenderTarget& target, RenderStates states) const override;

};