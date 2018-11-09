#pragma once
#include "map"
#include "iostream"
#include "string"
#include "vector"
#include <algorithm>

using namespace std;

class DRV
{
private:
	map <double, double> drv;
	double sum=0,MY3 = 0, MY4 = 0, SR=0;
	vector<double> answer;
	vector<double> x;
	void initialize_Data(vector<double> answer);
	void solution();

	double NY(int i);

	bool check_P();
	bool already_X();
public:
	DRV();
	virtual ~DRV();
	inline vector<double> Answer() { return this->answer; }
	unsigned compute(const vector<double> & answer);
};

