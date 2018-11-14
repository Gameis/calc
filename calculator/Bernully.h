#pragma once

#include "iostream"
#include "math.h"
#include "func.h"
#include "vector"
using namespace std;

class Bernully: public Func
{
private:
	int n, m;
	double p,q;
	vector<double> v;
	long long fact(int N)
	{
		if (N < 0) // если пользователь ввел отрицательное число
			return 0; // возвращаем ноль
		if (N == 0) // если пользователь ввел ноль,
			return 1; // возвращаем факториал от нуля - не удивляетесь, но это 1 =)
		else // Во всех остальных случаях
			return N * fact(N - 1); // делаем рекурсию.
	}
public:
	vector<double> answer()
	{
		return v;
	}
	unsigned compute(const vector<double> & vect)
	{
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
		n = vect[0];
		if (n > 15 || n<=0)
			return 11; //n не может быть больше 15 и меньше или равным 0
		m = vect[1];
		if (m > n || m < 0)
			return 12; //m не может быть больше n И меньше 0
		p = vect[2];
		if (p > 1 || p < 0) return 13; //p не может быть больше 1 и меньше 0
		q = 1 - p;
		v.push_back(fact(n) / (fact(m)*fact(n - m))*pow(p, m)*pow(q, n - m));
		return 0;
	}
};