#pragma once

#include <iostream>
#include "math.h"
#include <vector>
#include "func.h"
using namespace std;

/*
����������� �������� � ��������� �������:
n,p,m,lb,rb
*/

class BinomialDistibution : public Func
{
private:
	vector<double> _result;
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
		return _result;
	}
	unsigned compute(const vector<double> & vect)
	{
		_result.clear();
		try
		{
			vect.at(0);//n
			vect.at(1);//p
			vect.at(2);//m
			vect.at(3);//lb
			vect.at(4);//rb ������ ������� ������������ �� ���������
		}
		catch (...)
		{
			return 11; //������������ ���������� 
		}
		int n = vect[0];
		if (n < 0)
			return 12; // n ������ ���� ������ 0
		double p = vect[1];
		if (p < 0 || p > 1)
			return 17; // p �� ����� ���� ������ 0 ��� ������ 1
		double q = 1 - p;
		if (p + q != 1)
			return 13; // ����� ������������ �� ����� 1
		int m = vect[2];
		if (m > n)
			return 14; // m �� ����� ���� ������ n
		int lb = vect[3];
		int rb = vect[4];
		if (lb < 0)
			return 12; //����� ������� �� ����� ���� ����� 0 
		if (lb > rb)
			return 15; //����� ������� �� ����� ���� ������ ������
		if (rb > n)
			return 16; //������ ������� �� ����� ���� ������ n
		double temp = 0;
		for (int i = lb; i <= rb; i++)
		{
			temp += computeFactorial(n) / (computeFactorial(m)*computeFactorial(n - m))*pow(p, m)*pow(q, n - m);
		}
		_result.push_back(temp);
		if (n == 0)
			return 1; //n ����� 0
		if (n > 15)
			return 5; //n �� ����� ���� ������ 15
		return 0;
	}
};