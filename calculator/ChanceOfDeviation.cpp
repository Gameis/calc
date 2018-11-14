#include "ChanceOfDeviation.h"



ChanceOfDeviation::ChanceOfDeviation()
{
	_integral = new Integral([]() {return "2.7182818284^(-x^2/2)"; });

}


vector<double> ChanceOfDeviation::answer()
{
	return _answer;
}

unsigned ChanceOfDeviation::compute(const vector<double>& data)
{
	if (data.size() < 2) return 11;
	double x = data.at(0) / data.at(1);
	_integral->compute(vector<double>({ 0, x, x/0.02, 0.00001}));
	double phi = (1 / sqrt(2 * 3.1415926535))* _integral->answer().at(0);
	_answer.clear();
	_answer.push_back(2*phi);
	return 0;
}
