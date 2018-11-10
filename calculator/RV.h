#pragma once

#include <vector>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class CRV
{
private:
vector<double> answer_s;
double a, b, a1, b1, x, p;
public:
	unsigned compute(const vector<double>& answer_s);
	inline vector<double> answer(){return this->answer_s;}
};
