#pragma once
#include "vector"
#include "iostream"
#include "func.h"

using namespace std;

class combination : public Func
{
private:
	vector<double> v;

	double factorial(double n);
public:
	vector <double> answer();
	unsigned compute(const vector<double>& data);//���������� 1, ���� n < 0 
};