#include "binom.h"



binom::binom()
{
}

vector<double> binom::answer() {
	return data;
}

unsigned binom::compute(const vector<double> & v) {
	/*double m, D, dev, A, E;
	int n = v[0];
	double p = v[1], q = v[2];
	if (p + q == 1 && (A >= -2 && A <= 2) && (E >= -2 && E <= 2))
		return 0;
	else if (p + q != 1)
		return 1; //сумма вероятностей не равна 1
	else if (p <= 0 || p >= 1 || q <= 0 || q >= 1)
		return 2; // одна из вероятностей меньше/равна 0 или больше/равна 1
	else if (n <= 0)
		return 3; //число событий меньше/равно 0
	try
	{
		v.at(0);
		v.at(1);
		v.at(2);
	}
	catch (...)
	{
		return 11;//недостаточно аргументов
	}
	m = n*p;
	D = n*p*q;
	dev = sqrt(D);
	A = (q - p) / sqrt(n*p*q);
	E = (1 - 6 * p*q) / n*p*q;
	data.push_back(m);
	data.push_back(D);
	data.push_back(dev);
	data.push_back(A);
	data.push_back(E);
	*/
	return 0;//Которого тут вообще не было...
	
}


binom::~binom()
{
}
