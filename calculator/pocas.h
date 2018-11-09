#pragma once
#include <vector>
using namespace std;
class pokaz_ras
{
private:
	vector<double> _answer;
public:
	vector<double> answer();
	unsigned compute(const vector<double> & v);

};

