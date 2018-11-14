#pragma once

#include "vector"
#include "func.h"

using namespace std;

class binom: public Func
{
private:
	vector<double>data;
public:
	vector<double> answer();
	unsigned compute(const vector<double> & v);
};

