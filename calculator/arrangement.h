#pragma once
#include "vector"
#include "iostream"
#include "func.h"

using namespace std;

class arrangement: public Func //ÎÔÎĞÌËÅÍÈÅ
{
private:
	vector<double> v;//ÎÔÎĞÌËÅÍÈÅ
public:
	vector <double> answer();
	unsigned compute(const vector<double> & data);//âîçâğàùàåò 1, åñëè n < 0 
};

