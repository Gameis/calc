#pragma once
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class menu
{
private:
	vector<double> data;
	map <unsigned,string> errors;
public:
	vector<double> start();
	
	void begin() { data = start(); } 
	//����� � ������� ���������� ����, ���������� ������ ������������
	
	inline vector<double> result() { return this->data; } 
	//���������� ������ ���� double, � ������ �������� ������, ��������� � ������� 

	menu();

	void error_handler(unsigned value); 
	//������������ ������; 
	//value - ��� ������

	string getFunction();


	/////////////////////////////////////////
	/// \breif ����� ����������
	/// \param ansver - ������ ����������
	///               value - ����� �������
	/////////////////////////////////////////
	void answer_output(vector<double> ansver, int value);

};

