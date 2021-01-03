#include "Calculator.h"

Calculator::Calculator(int width, int height, string name) : _window(VideoMode(width, height), name)
{
	
}

void Calculator::run()
{
	highBound = 10;
	lowBound = 0;

	Font font;
	font.loadFromFile("res/Apex.ttf");
	
	for (int i = 0; i < 23; i++)
		buttons.push_back(Button());
	for (int i = 0; i < 3; i++)
		texts.push_back(TextBox());
	for (int i = 0; i < 2; i++)
		inputs.push_back(TextInput());

	/*BUTTONS*/
	/*NUMS*/
	buttons[0] .set(font, 70 , 400, 40, 50, "0"  );
	buttons[1] .set(font, 20 , 100, 40, 50, "1"  );
	buttons[2] .set(font, 70 , 100, 40, 50, "2"  );
	buttons[3] .set(font, 120, 100, 40, 50, "3"  );
	buttons[4] .set(font, 20 , 200, 40, 50, "4"  );
	buttons[5] .set(font, 70 , 200, 40, 50, "5"  );
	buttons[6] .set(font, 120, 200, 40, 50, "6"  );
	buttons[7] .set(font, 20 , 300, 40, 50, "7"  );
	buttons[8] .set(font, 70 , 300, 40, 50, "8"  );
	buttons[9] .set(font, 120, 300, 40, 50, "9"  );
	/*ROOLS*/
	buttons[10].set(font, 170, 100, 85, 50, "RND");
	buttons[11].set(font, 170, 200, 85, 50, "NRM");
	buttons[12].set(font, 270, 100, 85, 50, "CLR");
	buttons[13].set(font, 20 , 400, 40, 50, "+"  );
	buttons[14].set(font, 125, 400, 37, 50, "-"  );
	buttons[15].set(font, 170, 300, 85, 50, "MIN");
	buttons[16].set(font, 270, 300, 85, 50, "MAX");
	buttons[17].set(font, 270, 200, 85, 50, "MDL");
	buttons[18].set(font, 170, 400, 85, 50, "MDN");
	buttons[19].set(font, 270, 400, 85, 50, "VRN");
	buttons[20].set(font, 370, 300, 85, 50, "ASM");
	buttons[21].set(font, 370, 400, 85, 50, "EXC");
	buttons[22].set(font, 600, 100,100, 50, "TEST");

	/*BOXES*/
	texts[0].set(font, 10, 10, 40, 970, "Selection:");
	texts[1].set(font, 10, 60, 40, 970, "Result:");
	texts[2].set(font, 720, 115, 40, 260, "Normality test:");

	/*INPUTS*/
	inputs[0].set(font, 370, 100, "UPR: "); inputs[0].setValue(to_string(highBound));
	inputs[1].set(font, 370, 200, "LWR: "); inputs[1].setValue(to_string(lowBound));

	while (_window.isOpen())
	{
		events();
		display();
	}
}

void Calculator::events()
{
	Event event;
	while (_window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			_window.close();
		if (event.type == Event::TextEntered){
			if (event.text.unicode < 128) {
				char value = static_cast<char>(event.text.unicode);

				int num = 0;
				for (int i = 0; i < inputs.size(); i++) {
					if (inputs[i].update(value)) {
						num = inputs[i].getValue();
						
						if (i == 1)
							lowBound = num;
						else if (i == 0)
							highBound = num;

						break;
					}
				}

				
			}
		}
	}

	//FillColor
	for (int i = 0; i < buttons.size(); i++)
		buttons[i].onBound(_window);

	//NUMS
	for (int i = 0; i < 10; i++) {
		if (buttons[i].isPressed(_window)) {
			texts[0].addValue(to_string(i));
		}
	}

	//ADD NUMBER
	if (buttons[13].isPressed(_window))
		texts[0].addSpace();

	//REMOVE DIGIT
	if (buttons[14].isPressed(_window))
		texts[0].removeLast();

	//RANDOM SELECTION
	if (buttons[10].isPressed(_window)) {
		string value = "";

		auto sel = MathHelper::randomSelection(lowBound, highBound);
		for (int i = 0; i < sel.size(); i++)
			value += to_string(sel[i]) + " ";

		texts[0].setValue(value);
	}

	//NORMAL SELECTION
	if (buttons[11].isPressed(_window)) {
		string value = "";

		auto sel = MathHelper::normalSelection(lowBound, highBound);
		for (int i = 0; i < sel.size(); i++)
			value += to_string(sel[i]) + " ";

		texts[0].setValue(value);
	}

	//CLEAR SELECTION
	if (buttons[12].isPressed(_window)) {
		texts[0].clear();
		texts[1].clear();
		texts[2].clear();
	}

	//MIN
	if (buttons[15].isPressed(_window)) {
		texts[1].clear();
		texts[1].setValue(to_string(MathHelper::min(texts[0].getValue())));
	}

	//MAX
	if (buttons[16].isPressed(_window)) {
		texts[1].clear();
		texts[1].setValue(to_string(MathHelper::max(texts[0].getValue())));
	}

	//MIDDLE
	if (buttons[17].isPressed(_window)) {
		texts[1].clear();
		texts[1].setValue(to_string(MathHelper::middle(texts[0].getValue())));
	}

	//MEDIAN
	if (buttons[18].isPressed(_window)) {
		texts[1].clear();
		texts[1].setValue(to_string(MathHelper::median(texts[0].getValue())));
	}

	//MEDIAN
	if (buttons[19].isPressed(_window)) {
		texts[1].clear();
		texts[1].setValue(to_string(MathHelper::variance(texts[0].getValue())));
	}

	//ASYMMETRY
	if (buttons[20].isPressed(_window)) {
		texts[1].clear();
		texts[1].setValue(to_string(MathHelper::asymmetry(texts[0].getValue())));
	}

	//ASYMMETRY
	if (buttons[21].isPressed(_window)) {
		texts[1].clear();
		texts[1].setValue(to_string(MathHelper::excess(texts[0].getValue())));
	}

	//TEST
	if (buttons[22].isPressed(_window)) {
		texts[2].clear();
		texts[2].setValue(MathHelper::normalTest(texts[0].getValue())? "TRUE" : "FALSE");
	}

	//INPUTS
	for (int i = 0; i < inputs.size(); i++)
		inputs[i].activate(_window);
}

void Calculator::display() {

	_window.clear(Color::White);

	for (int i = 0; i < buttons.size(); i++)
		_window.draw(buttons[i]);
	for (int i = 0; i < texts.size(); i++)
		_window.draw(texts[i]);
	for (int i = 0; i < inputs.size(); i++)
		_window.draw(inputs[i]);

	_window.display();
}

