#pragma once
#include <vector>
#include "func.h"
using namespace std;
class pokaz_ras : public func
{
private:
	vector<double> _answer;
public:
	vector<double> answer();
	unsigned compute(const vector<double> & v);

};

