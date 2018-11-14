#pragma once
#include <vector>
#include <math.h>
#include "func.h"

using namespace std;

class Poisson : public Func
{
private:
	vector<double> _answers;
	void calculateCharacteristic(vector<double> v)
	{
		_answers.clear();
		_answers.push_back(v[0] * v[1]);
		_answers.push_back(v[0] * v[1]);
		_answers.push_back(sqrt(v[0] * v[1]));
		_answers.push_back(1. / (sqrt(v[0] * v[1])));
		_answers.push_back(1. / (v[0] * v[1]));
	}
public:
	unsigned compute(const vector<double> & v)
	{
		if (v.size() < 2)
			return 11;
		if (v[0] == 0)
			return 1;
		if (v[0] < 100)    //v[0]-n v[1]-p
			return 2;     //если число испытаний мало дл€ вычислени€ по формуле ѕуассона
		else
		if (v[1] < 0 || v[1]>1)
			return 13;     //если веро€тность выходит за возможные пределы
		else
		if (v[0] * v[1] >= 10)
			return 3;     //если веро€тность по€влени€ велика дл€ формулы ѕуассона
		else
		if (v[0] - int(v[0]) != 0)
			return 4;     //если число испытаний не целое
		else
		{
			calculateCharacteristic(v);
			return 0;
		}
	}
	vector<double> answer()
	{
		return _answers;
	}
};