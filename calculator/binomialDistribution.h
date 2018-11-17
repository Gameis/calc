#pragma once

#include <iostream>
#include "math.h"
#include <vector>
#include "func.h"
using namespace std;

/*
ѕ–»Ќ»ћјё“—я «Ќј„≈Ќ»я в следующем пор€дке:
n,p,m,lb,rb
*/

class BinomialDistibution : public Func
{
private:
	vector<double> _result;
	long long computeFactorial(int N)
	{
		if (N < 0) // если пользователь ввел отрицательное число
			return 0; // возвращаем ноль
		if (N == 0) // если пользователь ввел ноль,
			return 1; // возвращаем факториал от нул€ - не удивл€етесь, но это 1 =)
		else // ¬о всех остальных случа€х
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
			vect.at(0);//n
			vect.at(1);//p
			vect.at(2);//m
			vect.at(3);//lb
			vect.at(4);//rb ѕ–ј¬јя √–јЌ»÷ј ¬ Ћё„»“≈Ћ№Ќј ѕќ ”ћќЋ„јЌ»ё
		}
		catch (...)
		{
			return 11; //недостаточно аргументов 
		}
		int n = vect[0];
		if (n < 0)
			return 12; // n должно быть больше 0
		double p = vect[1];
		if (p < 0 || p > 1)
			return 17; // p не может быть меньше 0 или больше 1
		double q = 1 - p;
		if (p + q != 1)
			return 13; // сумма веро€тностей не равна 1
		int m = vect[2];
		if (m > n)
			return 14; // m не может быть больше n
		int lb = vect[3];
		int rb = vect[4];
		if (lb < 0)
			return 12; //лева€ граница не может быть левее 0 
		if (lb > rb)
			return 15; //лева€ граница не может быть правее правой
		if (rb > n)
			return 16; //права€ граница не может быть больше n
		double temp = 0;
		for (int i = lb; i <= rb; i++)
		{
			temp += computeFactorial(n) / (computeFactorial(m)*computeFactorial(n - m))*pow(p, m)*pow(q, n - m);
		}
		_result.push_back(temp);
		if (n == 0)
			return 1; //n равно 0
		if (n > 15)
			return 5; //n не может быть больше 15
		return 0;
	}
};