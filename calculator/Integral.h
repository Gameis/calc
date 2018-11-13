#pragma once
#define PI 3.1415926
#include <vector>
#include <string>
#include "Calculator.h"
#include <functional>
#include "FunctionParser.h"
#include "func.h"
using namespace std;
class Integral : public func
{
private:
	vector<double> _answer;
	vector<string> _function;
	double getValueByX(double x);
	Calculator * _calc;
	function<string()> getExpression;
	FunctionParser  * _parser;
public:
	Integral(function<string()> callBack);
	~Integral();
	unsigned compute(const vector<double> & data);
	vector<double> answer();
};

