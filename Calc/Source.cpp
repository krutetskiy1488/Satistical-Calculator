#include <iostream>
#include <time.h>
#include <algorithm>
#include <string>

#include <SFML/Graphics.hpp>

#include "Calculator.h"

using namespace sf;
using namespace std;

int main() {
	srand(time(0));

	Calculator calc(1000, 480, "Statistical Calculator");
	calc.run();

	return 0;
}