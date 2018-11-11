#pragma once
#include <vector>
#include <string>
#include "Calculator.h"
#include <functional>
using namespace std;
class Integral
{
private:
	vector<double> _answer;
	vector<string> _function;
	double getValueByX(double x);
	Calculator _calc;
public:
	Integral(const vector<string> & functions, const vector<function<double(double)>> & funcsValue);
	unsigned compute(const vector<double> & data, const vector<string> & function);
	vector<double> answer();
};

