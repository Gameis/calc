#ifndef DRV_H
#define DRV_H

#include <map>
#include <iostream>
#include <string>
#include <vector>
#include "func.h"
#include <algorithm>

using namespace std;

class DRV : public Func
{
private:
	map <double, double> _drv;
	double _my3 = 0, _my4 = 0, _theAvarageSquare = 0;
	float _sum = 0;
	vector<double> _answers;
	vector<double> _x;
	void initializeData(vector<double> answer);
	void computeNumericalCharacteristics();
	double computeNY(int i);
	bool isAlreadyX();
public:
	vector<double> answer() { return this->_answers; }
	unsigned compute(const vector<double> & answer);
};
#endif DRV_H