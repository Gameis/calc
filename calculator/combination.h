#pragma once
#include "vector"
#include "iostream"

using namespace std;

class combination
{
private:
	vector<double> v;
public:
	vector <double> ansver();
	unsigned compute(vector<double> data);//возвращает 1, если n < 0 
};