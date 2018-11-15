#pragma once

#include <iostream>
#include "math.h"
#include <vector>
using namespace std;

class Puasson : public Func
{
private:
	int _n, _m;
	double _p, _lambda;
	vector<double> _v;
	long long computeFactorial(int N)
	{
		if (N < 0) // ���� ������������ ���� ������������� �����
			return 0; // ���������� ����
		if (N == 0) // ���� ������������ ���� ����,
			return 1; // ���������� ��������� �� ���� - �� �����������, �� ��� 1 =)
		else // �� ���� ��������� �������
			return N * computeFactorial(N - 1); // ������ ��������.
	}
public:
	vector<double> answer()
	{
		return _v;
	}
	unsigned compute(const vector<double> & vect)
	{
		_v.clear();
		try
		{
			vect.at(0);
			vect.at(1);
			vect.at(2);
		}
		catch (...)
		{
			return 11; //������������ ���������� 
		}
		_n = vect[0];
		if (_n < 100)
		{
			return 7;// ���� n ������ 100
		}
		_m = vect[1];
		if (_m > _n)
		{
			return 14;//���� m ������ n
		}
		if (_m < 0)
		{
			return 18;//m ������ 0
		}
		_p = vect[2];
		if (_p > 1 || _p < 0)
		{
			return 17;//���� ������ 1 ��� � ������ 0
		}
		_lambda = _n*_p;
		if (_lambda >= 10)
		{
			return 20;// ���� ������ ������ ��� ����� 10
		}
		_v.push_back((pow(_lambda, _m) * exp(-_lambda)) / computeFactorial(_m));
		return 0;
	}
};