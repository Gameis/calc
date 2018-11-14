#pragma once

#include <vector>
#include "func.h"

using namespace std;

class Binom : public func
{
private:
	vector<double> _data;
public:
	vector<double> answer();
	unsigned compute(const vector<double> & v);
};

