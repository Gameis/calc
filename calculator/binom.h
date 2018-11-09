#pragma once

#include "vector"
#include "func.h"

using namespace std;

class binom: public func
{
private:
	vector<double>data;
public:
	vector<double> answer();
	unsigned compute(const vector<double> & v);
	binom();
	~binom();
};

