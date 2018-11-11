#include "Integral.h"


double Integral::getValueByX(double x)
{
	_calc.setXVal(x);
	return _calc.calculate(_function);
}


Integral::Integral(const vector<string> & functions, const vector<function<double(double)>> & funcsValue)
{
	_calc = Calculator(functions);
	_calc.setFunctions(funcsValue);
}


unsigned Integral::compute(const vector<double> & data, const vector<string> & function)
{
	if (data.size() < 4 || function.empty() ) return 11;
	_function = function;

	double e = data[3], n = data[2], a = data[0], b = data[1], a1, s, s1, g;

	double len = (b - a) / n;
	a1 = a;
	do {
		s = 0; s1 = 0;
		a = a1;
		g = a + len;
		for (int i = 0; i < n; i++) {
			if (getValueByX(a) > getValueByX(g)) s += getValueByX(a)*len - ((getValueByX(a) - getValueByX(g))*len / 2.);
			else if (getValueByX(a) < getValueByX(g)) s += getValueByX(a)*len + ((getValueByX(g) - getValueByX(a))*len / 2.);
			else s += getValueByX(a)*len;
			a += len;
			g += len;
		}
		a = a1;
		len /= 2;
		n *= 2;
		g = a + len;
		for (int i = 0; i < n; i++) {
			if (getValueByX(a) > getValueByX(g)) s1 += getValueByX(a)*len - ((getValueByX(a) - getValueByX(g))*len / 2.);
			else if (getValueByX(a) < getValueByX(g)) s1 += getValueByX(a)*len + ((getValueByX(g) - getValueByX(a))*len / 2.);
			else s1 += getValueByX(a)*len;
			a += len;
			g += len;
		}
	} while (!((s - s1) < e));

	_answer = vector<double>{s};
	return 0;
}


vector<double> Integral::answer()
{
	return _answer;
}
