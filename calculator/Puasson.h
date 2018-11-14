#pragma once

#include "iostream"
#include "math.h"
#include "vector"
#include "func.h"
using namespace std;

class Puasson : public Func
{
private:
	int n, m;
	double p, lambda;
	vector<double> v;
	long long fact(int N)
	{
		if (N < 0) // ���� ������������ ���� ������������� �����
			return 0; // ���������� ����
		if (N == 0) // ���� ������������ ���� ����,
			return 1; // ���������� ��������� �� ���� - �� �����������, �� ��� 1 =)
		else // �� ���� ��������� �������
			return N * fact(N - 1); // ������ ��������.
	}
public:
	vector<double> answer()
	{
		return v;
	}
	unsigned compute(const vector<double> & vect)
	{
		try
		{
			vect.at(0);
			vect.at(1);
			vect.at(2);
		}
		catch (...)
		{
			return 10; //������������ ���������� 
		}
		n = vect[0];
		if (n < 100)
		{
			return 10;
		}
		m = vect[1];
		if (m > n || m < 0)
		{
			return 11;
		}
		p = vect[2];
		if (p > 1 || p < 0)
		{
			return 12;
		}
		lambda = n*p;
		if (lambda >= 10)
		{
			return 13;
		}
		v.push_back((pow(lambda, m) * exp(-lambda)) / fact(m));
		return 0;
	}
};