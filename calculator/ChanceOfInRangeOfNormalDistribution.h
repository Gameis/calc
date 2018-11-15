#pragma once
#include "func.h"
#include "Integral.h"

class ChanceOfInRangeOfNormalDistribution : public Func
{
private:
	vector<double> _answer;
	double computeFi(double x)
		{
		Integral * integral = new Integral([]() {return "2.7182818284^(-x^2/2)"; });
		integral->compute(vector<double>({ 0, x, x / 0.02, 0.00001 }));
		double phi = (1 / sqrt(2 * 3.1415926535))* integral->answer().at(0);
		return phi;
		}
public:
	vector<double> answer()
		{
		return _answer;
		}
	unsigned compute(const vector<double> & data)
		{
		_answer.clear();
		try
		{
			data.at(0);
			data.at(1);
			data.at(2);
			data.at(3);
		}
		catch (...)
		{
			return 11; //недостаточно аргументов 
		}
		double a = data[0];
		double sigma = data[1];
		double alpha = data[2];
		double beta = data[3];
		if(alpha >= beta)
			{
			return 19;
			}
		double temp1 = ((beta - a) / sigma);
		double temp2 = ((alpha - a) / sigma);
		_answer.push_back(computeFi(temp1) - computeFi(temp2));
		}

};
