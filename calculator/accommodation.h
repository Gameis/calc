#pragma once
#include "vector"
#include "iostream"
#include "func.h"
using namespace std;
class accommodation : public Func
{
private:
	vector<double> v;

	double factorial(double n);
public:
	vector <double> answer();
	unsigned compute(const vector<double> & data);
	//возвращает 1, если n < 0 
	//возвращает 1, если m < 0 
};

