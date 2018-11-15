#pragma once
#define _USE_MATH_DEFINES
#include <vector>
#include <math.h>
#include "func.h"
using namespace std;
class IntervalPoisson : public Func
{
private:
	vector<double> _answer;
	int factorial(int i)
	{
		if (i == 0)
			return 1;
		else
		return i*factorial(i-1);
	}
	void calculatePropability(vector<double> v)
	{
		double l;
		l = v[0] * v[1];
		for (int i = v[2]; i < v[3]; i++)
		{
			_answer[0]+=((pow(l, i)*pow(M_E, -1 * l)) / double(factorial(i)));
		}
	}
public:
	unsigned compute(const vector<double> & vec)
	{
		auto v = vec;
		double temp;
		if (v[0] < 100)
		{
			return 7; //число испытаний должно быть больше 100 
		}
		else if (v[0]*v[1] >= 10)
		{
			return 8; //лямбда не может быть больше 10
		}
		else if (v[1] < 0 || v[1]>1)
		{
			return 17; //вероятность не может быть меньше 0 и не больше 1
		}
		else if (v[2] < 0)
		{
			return 20; //начало интервала не может быть меньше 0;
		}
		else if (v[2] >= v[3])
		{
			return 21; //начало интервала не может быть больше, либо равно концу интервала
		}
		else if (v[3] > v[0])
		{
			return 21; //конец интервала не может выходить за пределы закона распределения 
		}
		_answer.clear();
		_answer.push_back(0);
		if ((v[3]-v[2])>(v[0]-(v[3]-v[2])))
		{
			if (v[2]==0)
			{
				v[2]=v[3];
				v[3]=v[0];
			}
			else
			if (v[3]==v[0])
			{
				v[3]=v[2];
				v[2]=0;
			}
			else
			if (v[2]!=0 && v[3]!=v[1])
			{
				temp=v[3];
				v[3]=v[2];
				v[2]=0;
				calculatePropability(v);
				v[2]=temp;
				v[3]=v[0];
			}
			calculatePropability(v);
			_answer[0]=1.-_answer[0];
		}
		else
			calculatePropability(v);
		return 0;
	}
	vector<double> answer()
	{
		return _answer;
	}
};