#include "MathHelper.h"

float MathHelper::randomFloat()
{
	return (float)rand() / RAND_MAX;
}

float MathHelper::normalRand()
{
	float z = randomFloat();
	float f = randomFloat();

	float r = cos(2 * pi * f) * sqrt(-2 * log(z));
	
	return r;
}

vector<int> MathHelper::randomSelection(int l, int u, int count)
{
	vector<int> selection;

	for (int i = 0; i < count; i++)
		selection.push_back(l + rand() % (l - u));

	return selection;
}

vector<int> MathHelper::normalSelection(int l, int u, int count)
{
	vector<int> selection;

	for (int i = 0; i < count; i++)
		selection.push_back(l + (int(normalRand() * 10000) % (l - u)));

	return selection;
}

vector<int> MathHelper::extract(string values)
{
	if(values[values.size() - 1] != ' ')
		values = values + " ";
	vector<int> vec;
	string delimiter = " ";

	size_t pos = 0;
	string token;
	while ((pos = values.find(delimiter)) != string::npos) {
		token = values.substr(0, pos);
		vec.push_back(stoi(token));
		values.erase(0, pos + delimiter.length());
	}
	

	return vec;
}

int MathHelper::min(string values)
{
	if (values == "")
		return 0;

	vector<int> vec = extract(values);

	auto min = min_element(vec.begin(), vec.end());

	return (*min);
}

int MathHelper::max(string values)
{
	if (values == "")
		return 0.0f;

	vector<int> vec = extract(values);

	auto min = max_element(vec.begin(), vec.end());

	return (*min);
}

float MathHelper::middle(string values)
{
	if (values == "")
		return 0.0f;

	vector<int> vec = extract(values);
	float ans = 0.0f;
	for (int i = 0; i < vec.size(); i++)
		ans += vec[i];

	return ans / vec.size();
}

float MathHelper::median(string values)
{
	if (values == "")
		return 0.0f;

	vector<int> vec = extract(values);
	sort(vec.begin(), vec.end());
	float ans = 0.0f;

	if (vec.size() % 2 != 0)
		return vec[vec.size() / 2];
	else 
		return (vec[vec.size() / 2] + vec[vec.size() / 2 - 1]) / 2.0f;
}

float MathHelper::variance(string values)
{
	if (values == "")
		return 0.0f;

	vector<int> vec = extract(values);
	float mid = middle(values);
	float sum = 0.0f;

	for (int i = 0; i < vec.size(); i++)
		sum += vec[i] - mid;

	return sum / mid;
}

float MathHelper::asymmetry(string values)
{
	if (values == "")
		return 0.0f;

	vector<int> vec = extract(values);
	float ans = 0.0f;
	float mid = middle(values);
	float num = 0.0f;
	float den = 0.0f;

	for (int i = 0; i < vec.size(); i++) {
		num +=  (vec[i] - mid) * (vec[i] - mid) * (vec[i] - mid);
		den += (vec[i] - mid) * (vec[i] - mid);
	}
	num /= vec.size() - 1;
	den /= vec.size() - 1;
	den = powf(sqrtf(den), 3);

	return num / den;
}

float MathHelper::excess(string values)
{
	if (values == "")
		return 0.0f;

	vector<int> vec = extract(values);
	float ans = 0.0f;
	float mid = middle(values);
	float num = 0.0f;
	float den = 0.0f;

	for (int i = 0; i < vec.size(); i++) {
		num += (vec[i] - mid) * (vec[i] - mid) * (vec[i] - mid) * (vec[i] - mid);
		den += (vec[i] - mid) * (vec[i] - mid);
	}
	num /= vec.size() - 1;
	den /= vec.size() - 1;
	den = powf(sqrtf(den), 4);

	return num / den;
}

bool MathHelper::normalTest(string values)
{
	if (values == "")
		return false;

	vector<int> vec = extract(values);

	float A = asymmetry(values);
	float E = excess(values);
	float ma = stderrorA(vec.size());
	float me = stderrorE(vec.size());

	if (abs(A) < ma * 3.0f && abs(E) < me * 3.0f)
		return true;
	else
		return false;
}

float MathHelper::stderrorA(int n)
{
	return sqrtf(6.0f / n);
}

float MathHelper::stderrorE(int n)
{
	return 2.0f * sqrtf(6.0f / n);
}
