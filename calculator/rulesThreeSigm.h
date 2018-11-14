#ifndef RULESTHREESIGM_H
#define RULESTHREESIGM_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class rulesThreeSigm
{
private:
	double _a, _sigma, _leftBorder, _rightBorder;
	vector<double> _answers;

public:
	vector<double> answer() { return this->_answers; }
	unsigned compute(const vector<double> & answer);
};
#endif RULESTHREESIGM_H

