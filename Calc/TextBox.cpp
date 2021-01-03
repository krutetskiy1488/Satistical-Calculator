#include "TextBox.h"

void TextBox::set(Font& font, int x, int y, int width, int height, string name) {
	_bound.setOutlineColor(Color::Black);
	_bound.setOutlineThickness(2.0f);
	_bound.setPosition(x, y);
	_bound.setSize(Vector2f(height, width));
	
	_text.setFont(font);
	_text.setString(name);
	_text.setPosition(x, y);
	_text.setCharacterSize(30);
	_text.setFillColor(Color::Black);

	_name = name;
}

void TextBox::addSpace()
{
	if (_value == "" || _value[_value.size() - 1] == ' ')
		return;

	_value += " "; 
	_text.setString(_name + _value); 
}

void TextBox::removeLast()
{
	if (_value.size() > 0)
		_value = _value.substr(0, _value.size() - 1);

	_text.setString(_name + _value);
}

void TextBox::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(_bound);
	target.draw(_text);
}
