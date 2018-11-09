#include "arrangement.h"

double factorial(double n) {
	if (n == 0) return 1;
	if (n == 1) return 1;
	else return n*factorial(n - 1);
}

vector<double> arrangement::answer()
{
	return v;
}

unsigned arrangement::compute(const vector<double> & data)
{
	if (data[0] < 0) return 1;
	v.push_back(factorial(data[0]));
	return 0;
}
