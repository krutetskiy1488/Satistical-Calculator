#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static const float pi = 3.1415926535;

class MathHelper
{
public:
	static float randomFloat();
	static float normalRand();
	static vector<int> randomSelection(int l = -10, int u = 10, int count = 30);
	static vector<int> normalSelection(int l = -10, int u = 10, int count = 20);
	static vector<int> extract(string values);
	static int min(string values);
	static int max(string values);
	static float middle(string values);
	static float median(string values);
	static float variance(string values);
	static float asymmetry(string values);
	static float excess(string values);
	static bool normalTest(string values);
	static float stderrorA(int n);
	static float stderrorE(int n);
};

