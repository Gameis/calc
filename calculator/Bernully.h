#pragma once

#include "iostream"
#include "math.h"
#include "func.h"
#include "vector"
using namespace std;

class Bernully: public Func
{
private:
	int n, m;
	double p,q;
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
		if (n > 15 || n<=0)
			return 11; //n �� ����� ���� ������ 15 � ������ ��� ������ 0
		m = vect[1];
		if (m > n || m < 0)
			return 12; //m �� ����� ���� ������ n � ������ 0
		p = vect[2];
		if (p > 1 || p < 0) return 13; //p �� ����� ���� ������ 1 � ������ 0
		q = 1 - p;
		v.push_back(fact(n) / (fact(m)*fact(n - m))*pow(p, m)*pow(q, n - m));
		return 0;
	}
};