#pragma once
#include "vector"
#include "iostream"
#include "func.h"

using namespace std;

class arrangement: public Func
{
private:
	vector<double> v;
public:
	vector <double> answer();
	unsigned compute(const vector<double> & data);//возвращает 1, если n < 0 
};

