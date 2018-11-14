#pragma once
#include "vector"
#include "math.h"
#include "func.h"
using namespace std;
class poisson : public Func
{
private:
	vector<double> answers;
	void calculation(vector<double> v)
	{
		answers.push_back(v[0] * v[1]);
		answers.push_back(v[0] * v[1]);
		answers.push_back(sqrt(v[0] * v[1]));
		answers.push_back(1. / (sqrt(v[0] * v[1])));
		answers.push_back(1. / (v[0] * v[1]));
	}
public:
	unsigned compute(const vector<double> &v)
	{
		if (v[0] < 100)    //v[0]-n v[1]-p
			return 11;     //���� ����� ��������� ���� ��� ���������� �� ������� ��������
		else
		if (v[1] < 0 || v[1]>1)
			return 12;     //���� ����������� ������� �� ��������� �������
		else
		if (v[0] * v[1] >= 10)
			return 14;     //���� ����������� ��������� ������ ��� ������� ��������
		else
		if (v[0] - int(v[0]) != 0)
			return 15;     //���� ����� ��������� �� �����
		else
		{
			calculation(v);
			return 0;
		}
	}
	vector<double> answer()
	{
		vector<double> answers1 = answers;
		return answers1;
	}
};