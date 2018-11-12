#include "RV.h"

unsigned CRV::compute(const vector<double>& answers)
{
	_a1 = answers[1];
	_b1 = answers[2];
	_a = answers[3];
	_b = answers[4];
	_x = answers[5];
	if (_b1 < _a1)
	{
		return 10;	//левая граница не может быть больше правой и быть меньше 0
	}
	else if (_a < _a1)
	{
		return 11; //Левая граница интервала не может быть меньше левой границы интервала для x;
	}
	else if (_a > _b1)
	{
		return 12; //Левая граница интервала не может быть больше границы интервала для x;
	}
	else if (_b<_a || _b>_b1)
	{
		return 13; //Правая граница интервала не может быть больше правой границы интервала для x и не может быть больше левой границы;
	}
	else if (_x <= 0)
	{
		return 14; //Костанта не может быть меньше 0 и не может быть = 0;
	}
	else if (_x >= 1)
	{
		return 15; //Константа не может быть больше или равной 1
	}
	else {
		_p = _x * (_b - _a);
		if (_p < 0)
		{
			_p = _p * (-1);
		}
		else if (_p > 1 || _p == 1)
		{
			_p = 1;
		}
		_answers.clear();
		this->_answers.push_back(_p);
		return 0;
	}
}