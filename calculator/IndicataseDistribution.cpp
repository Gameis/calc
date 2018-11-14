#include "IndicataseDistribution.h"


vector<double> IndicataseDistribution::answer()
{
	return _answer;
}


unsigned IndicataseDistribution::compute(const vector<double> & v)
{
	double x = v.at(0), l = v.at(1);
	double d,b, A = 2, E = 6;
	if (v.size() > 2)
	{
		return 11;
	}
	
	d = 1 / pow(l, 2);//���������
	b = 1 / l;//���������� ���������
	
	_answer.clear();
	_answer.push_back(d);
	_answer.push_back(b);
	_answer.push_back(l);
	_answer.push_back(A);
	_answer.push_back(E);
	return 0;
}




