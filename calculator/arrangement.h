#pragma once
#include "vector"
#include "iostream"

using namespace std;

class arrangement
{
private:
	vector<double> v;
public:
	vector <double> answer();
	unsigned compute(const vector<double> & data);//возвращает 1, если n < 0 
};

