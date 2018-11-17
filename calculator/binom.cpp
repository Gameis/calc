#include "binom.h"



vector<double> Binom::answer() {
	return _data;
}

unsigned Binom::compute(const vector<double> & v) {
	_data.clear();
	double m, D, dev, A, E;
	try
	{
		v.at(0);
		v.at(1);
		v.at(2);
	}
	catch (...)
	{
		return 11;//������������ ����������
	}
	int n = v[0];
	double p = v[1], q = v[2];
	
	if (p + q != 1)
		return 13; //����� ������������ �� ����� 1
	else if (n == 0)
		return 1; //n ����� 0
	else if (n > 15)
		return 5; // n �� ������ ��������� 15 � ������� ��������
	else if (p < 0 || p > 1 || q < 0 || q > 1)
		return 17; // ���� �� ������������ ������ 0 ��� ������ 1
	else if (n < 0)
		return 12; //����� ������� ������ ���� ������ 0
	
	m = n*p;
	D = n*p*q;
	dev = sqrt(D);
	A = (q - p) / sqrt(n*p*q);
	E = (1 - 6 * p*q) / n*p*q;
	_data.push_back(m);
	_data.push_back(D);
	_data.push_back(dev);
	_data.push_back(A);
	_data.push_back(E);
	
	
	return 0;//�������� ��� ������ �� ����...
	
}



