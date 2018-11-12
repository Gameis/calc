#ifndef RV_H
#define RV_H

#include <vector>
#include <iostream>
#include <math.h>
#include <string>
#include "func.h"

using namespace std;

class CRV : public func
{
private:
	vector<double> _answers;
	double _a, _b, _a1, _b1, _x, _p;
public:
	unsigned compute(const vector<double>& answers);
	inline vector<double> answer() { return this->_answers; }
};
#endif RV_H