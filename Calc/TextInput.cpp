#include "TextInput.h"

void TextInput::set(Font& font, int x, int y, string name)
{
	_active = false;
	_name = name;
	_value = "";

	_text.setFont(font);
	_text.setString(name);
	_text.setPosition(x, y);
	_text.setCharacterSize(50);
	_text.setFillColor(Color::Black);
}

void TextInput::activate(RenderWindow& window)
{
	auto bounds = _text.getGlobalBounds();
	auto pos = Mouse::getPosition(window);
	//auto time = _timer.ElapsedTime.AsSeconds();

	if (bounds.contains(pos.x, pos.y) && Mouse::isButtonPressed(Mouse::Button::Left))
		_active = !_active;
}

bool TextInput::update(char c)
{
	bool digit = (isdigit(c) || c == '\b' || c == '\r' || c == '-')? true : false;

	if (_active && digit) {
		if (c == '\r')
			return true;
		if (c == '\b' && _value.size() > 0)
			_value = _value.substr(0, _value.size() - 1);
		else if (c != '\b' && _value.size() < 4)
			_value += c;

		_text.setString(_name + _value);
	}

	return false;
}
