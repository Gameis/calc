#pragma once

#include <iostream>
#include "math.h"
#include "func.h"
#include <vector>
using namespace std;

class Bernully: public func
{
private:
	int _n, _m;
	double _p, _q;
	vector<double> _result;
	long long computeFactorial(int N)
	{
		if (N < 0) // если пользователь ввел отрицательное число
			return 0; // возвращаем ноль
		if (N == 0) // если пользователь ввел ноль,
			return 1; // возвращаем факториал от нуля - не удивляетесь, но это 1 =)
		else // Во всех остальных случаях
			return N * computeFactorial(N - 1); // делаем рекурсию.
	}
public:
	vector<double> answer()
	{
		return _result;
	}
	unsigned compute(const vector<double> & vect)
	{
		_result.clear();
		try
		{
			vect.at(0);
			vect.at(1);
			vect.at(2);
		}
		catch (...)
		{
			return 10; //недостаточно аргументов 
		}
		_n = vect[0];
		if (_n > 15 || _n<=0)
			return 11; //n не может быть больше 15 и меньше или равным 0
		_m = vect[1];
		if (_m > _n || _m < 0)
			return 12; //m не может быть больше n И меньше 0
		_p = vect[2];
		if (_p > 1 || _p < 0) return 13; //p не может быть больше 1 и меньше 0
		_q = 1 - _p;
		_result.push_back(computeFactorial(_n) / (computeFactorial(_m)*computeFactorial(_n - _m))*pow(_p, _m)*pow(_q, _n - _m));
		return 0;
	}
};