#include "NSV numerical characteristics.h"
#include <vector>
#include "math.h"
#include <iostream>

using namespace std;

unsigned NSVNC::compute(const vector<double>& answers)
{
	_n = answers[1];
	_p = answers[2];
	if (_n < 1)
	{
		return 11;	//n не может быть меньше одного 
	}
	else if (_p<0 || _p>1)
	{
		return 17; //вероятность не может быть меньше 0 и не быть больше 1
	}
	else {
		_q = 1 - _p;
		_Mx = _n * _p;
		_Dx = _n *_p*_q;
		_sigma = sqrt(_Dx);
		_A = (_q - _p) / _sigma;
		_E = (1 - 6 *_p*_q) / _sigma;
		_answers.clear();
		this->_answers.push_back(_Mx);
		this->_answers.push_back(_Dx);
		this->_answers.push_back(_sigma);
		this->_answers.push_back(_A);
		this->_answers.push_back(_E);
		return 0;
	}
}