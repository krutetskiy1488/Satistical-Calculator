#pragma once
#include <iostream>
#include <string>
#include <algorithm>

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Button : public Drawable
{
public:
	virtual void set(Font& font, int x, int y, string value);

	bool isPressed(RenderWindow& window);
protected:
	Text _text;
	Clock _timer;

	// Унаследовано через Drawable
	virtual void draw(RenderTarget& target, RenderStates states) const override;
};