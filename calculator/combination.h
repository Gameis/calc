#pragma once
#include "vector"
#include "iostream"

using namespace std;

class combination
{
private:
	vector<double> v;

	double factorial(double n);
public:
	vector <double> answer();
	unsigned compute(vector<double> data);//���������� 1, ���� n < 0 
};