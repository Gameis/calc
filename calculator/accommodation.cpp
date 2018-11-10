#include "accommodation.h"

double factorial(double n) {
	if (n == 0) return 1;
	if (n == 1) return 1;
	else return n * factorial(n - 1);
}

vector<double> accommodation::ansver()
{
	return v;
}

unsigned accommodation::compute(vector<double> data)
{
	if (data[0] < 0) return 1;
	if (data[1] < 0) return 2;
	v.push_back(factorial(data[0])/factorial(data[0]-data[1]));
	return 0;
}
