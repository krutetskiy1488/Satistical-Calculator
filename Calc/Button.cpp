#include "Button.h"

void Button::set(Font& font, int x, int y, string value) {
	_text.setFont(font);
	_text.setString(value);
	_text.setPosition(x, y);
	_text.setCharacterSize(50);
	_text.setFillColor(Color::Black);
}

bool Button::isPressed(RenderWindow& window)
{
	auto pos = Mouse::getPosition(window);
	auto bnd = _text.getGlobalBounds();
	auto delta = _timer.getElapsedTime().asSeconds();

	if (delta > 0.1 && bnd.contains(pos.x, pos.y) && Mouse::isButtonPressed(Mouse::Left)) {
		_timer.restart();
		return true;
	}
	else
		return false;
}

void Button::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(_text);
}
