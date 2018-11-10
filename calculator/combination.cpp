#include "combination.h"


double combination::factorial(double n)
	{
	if (n == 0) return 1;
	if (n == 1) return 1;
	else return n * factorial(n - 1);
	}


vector<double> combination::answer()
{
	return v;
}

unsigned combination::compute(vector<double> data)
{
	if (data[0] < 0) return 1;
	if (data[0] < 0) return 2;
	v.push_back(factorial(data[0])/(factorial(data[1])*factorial(data[0]-data[1])));
	return 0;
}
