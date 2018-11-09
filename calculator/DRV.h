#pragma once
#include "map"
#include "iostream"
#include "string"
#include "vector"
#include "func.h"
#include <algorithm>

using namespace std;

class DRV : public func
{
private:
	map <double, double> drv;
	double sum=0,MY3 = 0, MY4 = 0, SR=0;
	vector<double> answers;
	vector<double> x;
	void initialize_Data(vector<double> answer);
	void solution();

	double NY(int i);

	bool check_P();
	bool already_X();
public:
	vector<double> answer() { return this->answers; }
	unsigned compute(const vector<double> & answer);
};

