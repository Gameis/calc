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
		return 10;	//����� ������� �� ����� ���� ������ ������ � ���� ������ 0
	}
	else if (_a < _a1)
	{
		return 11; //����� ������� ��������� �� ����� ���� ������ ����� ������� ��������� ��� x;
	}
	else if (_a > _b1)
	{
		return 12; //����� ������� ��������� �� ����� ���� ������ ������� ��������� ��� x;
	}
	else if (_b<_a || _b>_b1)
	{
		return 13; //������ ������� ��������� �� ����� ���� ������ ������ ������� ��������� ��� x � �� ����� ���� ������ ����� �������;
	}
	else if (_x <= 0)
	{
		return 14; //�������� �� ����� ���� ������ 0 � �� ����� ���� = 0;
	}
	else if (_x >= 1)
	{
		return 15; //��������� �� ����� ���� ������ ��� ������ 1
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