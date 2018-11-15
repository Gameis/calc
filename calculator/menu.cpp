#include "menu.h"
#include "iostream"
#include "clocale"
#include "string"
#include "vector"
#include "cstdlib"
#include "windows.h"
#include "conio.h"

using namespace std;

int var;

double input() {
	string str;
	while (true) {
		bool point = false;
		getline(cin, str);
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ',')
				str[i] = '.';
			if (str[i]!='-' && str[i]!= '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i]!= '.')
					point = true;
		}
		if (point == true) continue;
		else return atof(str.c_str());
	}
}

void inputingData(int var, vector<double>& data) {
	system("cls");
	double templ;
	switch (var) {
	case 0: exit(0);
	case 1: cout << "n: "; data.push_back(input()); cout << "m: "; data.push_back(input()); break;
	case 2: cout << "n: "; data.push_back(input()); cout << "m: "; data.push_back(input()); break;
	case 3: cout << "n: "; data.push_back(input()); break;
	case 4: cout << "n: "; data.push_back(input()); cout << "m: "; data.push_back(input()); cout << "p: "; data.push_back(input()); break;
	case 5: cout << "n: "; data.push_back(input()); cout << "m: "; data.push_back(input()); cout << "p: "; data.push_back(input()); break;
	case 6: cout << "������� ����������� ������: "; templ = input(); for (int i = 0; i < templ; i++) { cout << "x" << i + 1 << ' '; data.push_back(input()); cout << "p" << i + 1 << ' '; data.push_back(input()); } break;
	case 7: cout << "n: "; data.push_back(input()); cout << "p: "; data.push_back(input()); cout << "q: "; data.push_back(input()); break;
	case 8: cout << "n: "; data.push_back(input()); cout << "p: "; data.push_back(input()); break;
	case 9: cout << "n: "; data.push_back(input()); cout << "p: "; data.push_back(input()); break;
	case 10: cout << "����� ������� ���������: "; data.push_back(input());  cout << "������ ������� ���������: "; data.push_back(input()); cout << "����� ������� �������� ���������: "; data.push_back(input()); cout << "������ ������� �������� ���������: "; data.push_back(input()); cout << "x: "; data.push_back(input());
	case 11: cout << "����� ������� ���������: "; data.push_back(input());  cout << "������ ������� ���������: "; data.push_back(input());
	case 12: cout << "��� �� �������� ������ ��������, ������� ������ ���������� �����������, ������� �� ������������ �:";
	case 13: cout << "a: "; data.push_back(input()); cout << "�: "; data.push_back(input()); break;
	case 14: cout << "������ ���������: "; data.push_back(input()); cout << "����� ���������: "; data.push_back(input());  cout << "���������� �����: "; data.push_back(input()); cout << "��������: "; data.push_back(input());
	case 15: cout << "n: "; data.push_back(input()); cout << "p: "; data.push_back(input()); cout << "m: "; data.push_back(input()); cout << "����� ������� ���������: "; data.push_back(input());  cout << "������ ������� ���������: "; data.push_back(input()); break;
	case 16: cout << "n: "; data.push_back(input()); cout << "p: "; data.push_back(input()); cout << "����� ������� ���������: "; data.push_back(input());  cout << "������ ������� ���������: ";
	case 17: cout << "a: "; data.push_back(input()); cout << "�����:"; data.push_back(input()); cout << "����� ������� ���������: "; data.push_back(input());  cout << "������ ������� ���������: "; data.push_back(input()); break;
	case 18: cout << "����� ������� ���������: "; data.push_back(input());  cout << "������ ������� ���������: "; data.push_back(input()); cout << "������: "; data.push_back(input());
	case 19: cout << "��� �� �������� ������ ��������, ������� ������ ���������� �����������, ������� �� ������������ �:";
	case 20: cout << "������� :"; data.push_back(input()); cout << "�����:"; data.push_back(input()); break;
	case 21: cout << "������� :"; data.push_back(input()); cout << "�����:"; data.push_back(input()); break;
	default: cout << "��������� ����\n";
	}
}

vector<double> Menu::start() {
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("color F0");
	vector<double> data;
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 1));
	cout << "\t\t\t����\n";
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
	cout << "\n\t1 - ���������� ����������" <<  "\n\t2 - ���������� ����������" <<  "\n\t3 - ���������� ������������" << "\n\t4 - ���������� ����������� �������� ��������" << "\n\t";
	cout << "5 - ���������� ����������� �������� ��������" << "\n\t6 - ��� - �������� ��������������" << "\n\t7 - ������������� ������������� - �������� ��������������" << "\n\t";
	cout << "8 - ������� ������������� �������� - �������� ��������������" << "\n\t9 - ��� - �������� ��������������" << "\n\t10 - ��� - ����������� ��������� � �������� ��������" << "\n\t";
	cout << "11 - ������������� �������������" << "\n\t12 - ����������� �������������" << "\n\t13 - ���������� �������������" << "\n\t14 - ���������� ������������� �������� ���������" << "\n\t";
	cout << "\n\t ����� ����������� ��������� � �������� ��������:\n\n";
	cout << "\t15 - ������������ ��������������\n\t16 - �������������� �� ��������\n\t17 - ���������� ��������������\n\t18 - ������������� ��������������\n\t19 - ����������� ��������������\n\t20 - ������� ���� ����\n\t21 - ���� ����������� ����������\n";
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 4));
	cout << "\t      0 - �����\n" << "";
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
	var = input();
	data.push_back(var);
	inputingData(var, data);
	return data;
}

void Menu::errorHandler(int value)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 4));
	cout <<"\nERROR \n" << Errors.at(value) << endl;
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
	system("pause");
	system("cls");
}

string Menu::getFunction()
{
	string str;
	cout << "\n����� - sin, \n������� - cos, \n������� - tan, \n��������� - ctan, \n�������� - asin, \n���������� - acos, \n��������� - atan, \n������������ - actan, \n���������� ������ - sqrt, \n���������� ������ - cbrt, \n������ - abs" << endl << "������� �������: ";
	getline(cin, str);
	return str;
}

void Menu::outputinAnswer(vector<double> ansver, int value)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 4));
	switch (value) {
	case 1: cout << "\n����������� ���������: "; cout << ansver.at(0); break;
	case 2: cout << "\n����������� ����������: "; cout << ansver.at(0); break;
	case 3: cout << "\n����������� ������������: "; cout << ansver.at(0); break;
	case 4: cout << "\n�����������: "; cout << ansver.at(0); break;
	case 5: cout << "\n�����������: "; cout << ansver.at(0); break;
	case 6: cout << "\n�������������� ��������: "; cout << ansver.at(0); cout << "\n���������: "; cout << ansver.at(1); cout << "\n������� �������������� �����������: "; cout << ansver.at(2); cout << "\n����������: " << ansver.at(3); cout << "\n�������: " << ansver.at(4); break;
	case 7: cout << "\n�������������� ��������: "; cout << ansver.at(0); cout << "\n���������: "; cout << ansver.at(1); cout << "\n������� �������������� �����������: "; cout << ansver.at(2); cout << "\n����������: " << ansver.at(3); cout << "\n�������: " << ansver.at(4); break;
	case 8: cout << "\n�������������� ��������: "; cout << ansver.at(0); cout << "\n���������: "; cout << ansver.at(1); cout << "\n������� �������������� �����������: "; cout << ansver.at(2); cout << "\n����������: " << ansver.at(3); cout << "\n�������: " << ansver.at(4); break;
	case 9: cout << "\n�������������� ��������: "; cout << ansver.at(0); cout << "\n���������: "; cout << ansver.at(1); cout << "\n������� �������������� �����������: "; cout << ansver.at(2); cout << "\n����������: " << ansver.at(3); cout << "\n�������: " << ansver.at(4); break;
	case 10: cout << "\n�����������: "; cout << ansver.at(0); break;
	case 11: cout << "\n�������������� ��������: "; cout << ansver.at(0); cout << "\n���������: "; cout << ansver.at(1); cout << "\n������� �������������� �����������: "; cout << ansver.at(2); cout << "\n����������: " << ansver.at(3); cout << "\n�������: " << ansver.at(4); break;
	case 12: cout << "\n�������������� ��������: "; cout << ansver.at(0); cout << "\n���������: "; cout << ansver.at(1); cout << "\n������� �������������� �����������: "; cout << ansver.at(2); cout << "\n����������: " << ansver.at(3); cout << "\n�������: " << ansver.at(4); break;
	case 13: cout << "\n�������������� ��������: "; cout << ansver.at(0); cout << "\n���������: "; cout << ansver.at(1); cout << "\n������� �������������� �����������: "; cout << ansver.at(2); cout << "\n����������: " << ansver.at(3); cout << "\n�������: " << ansver.at(4); break;
	case 14: cout << "\n���������: "; cout << ansver.at(0); break;
	case 15: cout << "\n�����������: "; cout << ansver.at(0); break;
	case 16: cout << "\n�����������: "; cout << ansver.at(0); break;
	case 17: cout << "\n�����������: "; cout << ansver.at(0); break;
	case 18: cout << "\n�����������: "; cout << ansver.at(0); break;
	case 19: cout << "\n�����������: "; cout << ansver.at(0); break;
	case 20: cout << "\n����� ������� "; cout << ansver.at(0); cout << "\n����� ������� "; cout << ansver.at(1); break;
	case 21: cout << "\n�����������: "; cout << ansver.at(0); break;
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
	}
	cout << endl;
	system("pause");
	system("cls");
}