#include "ProbabilityIndicataseDistribution.h"




vector<double> ProbabilityIndicataseDistribution::answer()
{
	return _answer;
}


unsigned  ProbabilityIndicataseDistribution::compute(const vector<double> & vec)
{
	double l = vec.at(2), alfa = vec.at(0), beta = vec.at(1);
	double f,t,F2, F1, p,ex=2.71828182845904;

	if (alfa >= beta) {
		return 19;
	}
	
	if (vec.size() > 3)
	{
		return 11;
	}

	t = (-1) *l*alfa;
	f= (-1) *l*beta;

	
	F1 = 1 - pow(ex, t);
	F2 = 1 - pow(ex, f);
	p = F2 - F1;


	_answer.clear();

	_answer.push_back(p);
	
	return 0;
}
