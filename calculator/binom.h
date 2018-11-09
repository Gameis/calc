#pragma once

#include "vector"

using namespace std;

class binom
{
private:
	vector<double>data;
public:
	vector<double> answer();
	unsigned computer(const vector<double> & v);
	binom();
	~binom();
};

