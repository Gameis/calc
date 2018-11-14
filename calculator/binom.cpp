#include "binom.h"



vector<double> Binom::answer() {
	return _data;
}

unsigned Binom::compute(const vector<double> & v) {
	double m, D, dev, A, E;
	int n = v[0];
	double p = v[1], q = v[2];
	if (p + q == 1)
		return 0;
	else if (p + q != 1)
		return 13; //����� ������������ �� ����� 1
	else if (n == 0)
		return 1; //n ����� 0
	else if (n > 15)
		return 5; // n �� ������ ��������� 15 � ������� ��������
	else if (p <= 0 || p >= 1 || q <= 0 || q >= 1)
		return 10; // ���� �� ������������ ������/����� 0 ��� ������/����� 1
	else if (n < 0)
		return 12; //����� ������� ������ ���� ������ 0
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
	m = n*p;
	D = n*p*q;
	dev = sqrt(D);
	A = (q - p) / sqrt(n*p*q);
	E = (1 - 6 * p*q) / n*p*q;
	vector<double> _data = vector<double>{ m,D,dev,A,E };
	
	
	return 0;//�������� ��� ������ �� ����...
	
}



