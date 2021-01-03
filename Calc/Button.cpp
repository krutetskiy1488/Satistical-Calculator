#include "Button.h"

void Button::set(Font& font, int x, int y, int h, int w, string value) {
	_bound.setOutlineColor(Color::Black);
	_bound.setOutlineThickness(2);
	_bound.setPosition(x - 5, y + 5);
	_bound.setSize(Vector2f(h, w));

	_text.setFont(font);
	_text.setString(value);
	_text.setPosition(x, y);
	_text.setCharacterSize(50);
	_text.setFillColor(Color::Black);
}

bool Button::isPressed(RenderWindow& window)
{
	auto pos = Mouse::getPosition(window);
	auto bnd = _bound.getGlobalBounds();
	auto delta = _timer.getElapsedTime().asSeconds();

	if (delta > 0.1 && bnd.contains(pos.x, pos.y) && Mouse::isButtonPressed(Mouse::Left)) {
		_timer.restart();
		return true;
	}
	else
		return false;
}

void Button::onBound(RenderWindow& window)
{
	auto pos = Mouse::getPosition(window);
	auto bnd = _bound.getGlobalBounds();

	if (bnd.contains(pos.x, pos.y)) {
		_text.setFillColor(Color::White);
		_bound.setFillColor(Color::Black);
	}
	else
	{
		_text.setFillColor(Color::Black);
		_bound.setFillColor(Color::White);
	}
}

void Button::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(_bound);
	target.draw(_text);
}
