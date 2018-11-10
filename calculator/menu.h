#pragma once
#include <vector>
#include <iostream>

using namespace std;

class menu
{
private:
	vector<double> data;
	vector<string> errors;
public:
	vector<double> start();
	
	void begin() { data = start(); } 
	//����� � ������� ���������� ����, ���������� ������ ������������
	
	inline vector<double> result() { return this->data; } 
	//���������� ������ ���� double, � ������ �������� ������, ��������� � ������� 
	
	void set(const vector<string>& error) { errors = error; }; 
	//������ ������ ����� �� ������� ������

	void error_handler(int value); 
	//������������ ������; 
	//value - ��� ������


	/////////////////////////////////////////
	/// \breif ����� ����������
	/// \param ansver - ������ ����������
	///               value - ����� �������
	/////////////////////////////////////////
	void answer_output(vector<double> ansver, int value);

};

