#pragma once
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Menu
{
private:
	vector<double> Data;
	map <int, string> Errors = { {1,"n = 0"},{2,"����� ��������� ���� ��� ������� ��������"},{3,"����������� ������ ��� ��������"},{4,"����� ������ ���� �����"},{5,"n > 15"},{6,"����� < 0"},{10,"� ������������� ������������ ���������� X-�"},{11,"�������� ����������"},{12,"����� ������ ���� ������ 0"},{13,"����� ������������ �� ����� 1"},{14,"m > n"} };
public:
	vector<double> start();
	
	void begin() { Data = start(); } 
	//����� � ������� ���������� ����, ���������� ������ ������������
	
	inline vector<double> result() { return this->Data; } 
	//���������� ������ ���� double, � ������ �������� ������, ��������� � ������� 
	
	void set(const map<int,string>& error) { Errors = error; }; 
	//������ ������ ����� �� ������� ������

	void errorHandler(int value); 
	//������������ ������; 
	//value - ��� ������

	string getFunction();


	/////////////////////////////////////////
	/// \breif ����� ����������
	/// \param ansver - ������ ����������
	///               value - ����� �������
	/////////////////////////////////////////
	void outputinAnswer(vector<double> ansver, int value);

};

