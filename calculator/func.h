#pragma once
#include <vector>

using namespace std;

class func
{
public:
	virtual vector <double> answer() = 0;
	virtual unsigned compute(const vector<double> & data) = 0;
};

