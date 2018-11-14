#pragma once
#include "func.h"
#include "Integral.h"
#include <vector>

using namespace std;

class ChanceOfDeviation :
	public Func
{
	vector<double> _answer;
	Integral * _integral;
public:
	ChanceOfDeviation();

	virtual vector<double> answer() override;
	virtual unsigned compute(const vector<double>& data) override;

};

