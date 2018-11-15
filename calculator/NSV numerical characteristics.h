#ifndef NSVNUMBERICALCHATACTERISRICS_H
#define NSVNUMBERICALCHATACTERISRICS_H

#include <vector>
#include <iostream>
#include <math.h>
#include <string>
#include "func.h"

using namespace std;

class NSVNC : public Func
{
private:

	vector<double> _answers;
	double _n, _p, _q, _Mx, _Dx, _sigma, _A, _E;
public:
	unsigned compute(const vector<double>& answers);
	inline vector<double> answer() { return this->_answers; }
};
#endif NSVNUMBERICALCHATACTERISRICS_H