#include <vector>
#include "NormalDistribution.h"
#include <iostream>
using namespace std;

vector<double> NormalDistribution::answer()
	{
	return _answer;
	}

unsigned NormalDistribution::compute(const vector<double> & v)
	{
	double a = v.at(0), sigma = v.at(1);
	double M, D, S, A = 0, E = 0;
	if (v.size() > 2)
	{
		return 11;
	}
	M = a;
	D = sigma * sigma;
	_answer.push_back(M);
	_answer.push_back(sigma);
	_answer.push_back(D);
	_answer.push_back(A);
	_answer.push_back(E);
	return 0;
	}




