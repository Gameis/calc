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

unsigned combination::compute(const vector<double>& data)
{
	vector<double> q;
	v = q;
	int temp = data[0];
	if (data[0] != temp) return 4;
		temp = data[1];
		if (data[1] != temp) return 4;
		if (data[0] < 0) return 12;
	if (data[1] < 0) return 22;
	try {
		data.at(0);
		data.at(1);
	}
	catch (...) {
		return 11;
	}
	v.push_back(factorial(data[0])/(factorial(data[1])*factorial(data[0]-data[1])));
	return 0;
}
