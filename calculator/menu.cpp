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

HWND GetConsoleHwnd(void) {
#define MY_BUFSIZE 1024 
	HWND hwndFound;
	char pszNewWindowTitle[MY_BUFSIZE];
	char pszOldWindowTitle[MY_BUFSIZE];
	GetConsoleTitleA(pszOldWindowTitle, MY_BUFSIZE);
	wsprintfA(pszNewWindowTitle, "%d/%d",
		GetTickCount(),
		GetCurrentProcessId());
	SetConsoleTitleA(pszNewWindowTitle);
	Sleep(1);
	hwndFound = FindWindowA(NULL, pszNewWindowTitle);
	SetConsoleTitleA(pszOldWindowTitle);
	return(hwndFound);
}

int d() {
	string cursor[15] = { "" };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	RECT r;
	POINT p;
	HWND wh = GetConsoleHwnd();
	COORD c = { 1,1 };
	while (1) {
		GetWindowRect(wh, &r);
		GetCursorPos(&p);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
		cout << p.x - r.left << ":" << p.y - r.top << "    ";
		if (p.y - r.top > 85 && p.y - r.top < 90) {
			for (int i = 0; i < 15; i++)
				cursor[i] = "       ";
			cursor[1] = "  <-";
			if (MK_RBUTTON) {
				cursor[1] += "->";
			}
		}
		if (p.y - r.top > 100 && p.y - r.top < 110) {
			for (int i = 0; i < 15; i++)
				cursor[i] = "       ";
			cursor[2] = "  <-";
		}
		if (p.y - r.top > 116 && p.y - r.top < 124) {
			for (int i = 0; i < 15; i++)
				cursor[i] = "       ";
			cursor[3] = "  <-";
		}
		if (p.y - r.top > 130 && p.y - r.top < 143) {
			for (int i = 0; i < 15; i++)
				cursor[i] = "       ";
			cursor[4] = "  <-";
		}
		if (p.y - r.top > 146 && p.y - r.top < 158) {
			for (int i = 0; i < 15; i++)
				cursor[i] = "       ";
			cursor[5] = "  <-";
		}
		if (p.y - r.top > 180 && p.y - r.top < 190) {
			for (int i = 0; i < 15; i++)
				cursor[i] = "       ";
			cursor[6] = "  <-";
		}
		if (p.y - r.top > 200 && p.y - r.top < 210) {
			for (int i = 0; i < 15; i++)
				cursor[i] = "       ";
			cursor[7] = "  <-";
		}
		if (p.y - r.top > 220 && p.y - r.top < 230) {
			for (int i = 0; i < 15; i++)
				cursor[i] = "       ";
			cursor[8] = "  <-";
		}
		if (p.y - r.top > 240 && p.y - r.top < 250) {
			for (int i = 0; i < 15; i++)
				cursor[i] = "       ";
			cursor[9] = "  <-";
		}
		if (p.y - r.top > 260 && p.y - r.top < 270) {
			for (int i = 0; i < 15; i++)
				cursor[i] = "       ";
			cursor[10] = "  <-";
		}
		if (p.y - r.top > 280 && p.y - r.top < 290) {
			for (int i = 0; i < 15; i++)
				cursor[i] = "       ";
			cursor[11] = "  <-";
		}
		if (p.y - r.top > 300 && p.y - r.top < 310) {
			for (int i = 0; i < 15; i++)
				cursor[i] = "       ";
			cursor[12] = "  <-";
		}
		if (p.y - r.top > 320 && p.y - r.top < 330) {
			for (int i = 0; i < 15; i++)
				cursor[i] = "       ";
			cursor[13] = "  <-";
		}
		if (p.y - r.top > 340 && p.y - r.top < 350) {
			for (int i = 0; i < 15; i++)
				cursor[i] = "       ";
			cursor[14] = "  <-";
		}
		if (p.y - r.top > 360 && p.y - r.top < 370) {
			for (int i = 0; i < 15; i++)
				cursor[i] = "       ";
			cursor[0] = "  <-";
		}

		SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 1));
		cout << "\t\t\tМеню\n";
		SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
		cout << "\n\t1 - Вычисление сочентания" << cursor[1] << "\n\t2 - Вычисление размещения" << cursor[2] << "\n\t3 - Вычисление перестановок" << cursor[3] << "\n\t4 - Вычисление вероятности формулой Бернулли" << cursor[4] << "\n\t";
		cout << "5 - Вычисление вероятности формулой Пуассона" << cursor[5] << "\n\t6 - ДСВ - числовые характеристики" << cursor[6] << "\n\t7 - Биноминальное распеределине - числовые характеристики" << cursor[7] << "\n\t";
		cout << "8 - Формула распределения Пуассона - числовые характеристики" << cursor[8] << "\n\t9 - НСВ - числовые характеристики" << cursor[9] << "\n\t10 - НСВ - вероятность попадания в заданный интервал" << cursor[9] << "\n\t";
		cout << "11 - Показательное распределение" << cursor[11] << "\n\t12 - Равномерное распределение" << cursor[12] << "\n\t13 - Нормальное распределение" << cursor[13] << "\n\t14 - Нахождение приближенного значения интеграла" << cursor[14] << "\n\t";
		SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 4));
		cout << "\t      0 - Выход" << cursor[0] << "";
	}
	return 0;
}

double input() {
	string str;
	while (true) {
		bool point = false;
		getline(cin, str);
		for (int i = 0; i < str.size(); i++) {
			if (str[i]!= '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i]!= '.')
					point = true;
		}
		if (point == true) continue;
		else return atof(str.c_str());
	}
}

void input_data(int var, vector<double>& data) {
	system("cls");
	double templ;
	switch (var) {
	case 0: exit(0);
	case 1: cout << "n: "; data.push_back(input()); cout << "m: "; data.push_back(input()); break;//
	case 2: cout << "n: "; data.push_back(input()); cout << "m: "; data.push_back(input()); break;//
	case 3: cout << "n: "; data.push_back(input()); break;//
	case 4: cout << "n: "; data.push_back(input()); cout << "m: "; data.push_back(input()); cout << "p: "; data.push_back(input()); break;//
	case 5: cout << "n: "; data.push_back(input()); cout << "m: "; data.push_back(input()); cout << "p: "; data.push_back(input()); break;//
	case 6: cout << "Введите колличество данных: "; templ = input(); for (int i = 0; i < templ; i++) { cout << "x" << i + 1 << ' '; data.push_back(input()); cout << "p" << i + 1 << ' '; data.push_back(input()); } break;//
	case 7: cout << "n: "; data.push_back(input()); cout << "p: "; data.push_back(input()); cout << "q: "; data.push_back(input()); break;//
	case 8: cout << "n: "; data.push_back(input()); cout << "p: "; data.push_back(input()); break;
	//case 9:
	//case 10:
	//case 11:
	//case 12:
	case 13: cout << "a: "; data.push_back(input()); cout << "Ъ: "; data.push_back(input()); break;
	//case 14:
	}
}

vector<double> menu::start() {
	string cursor[15] = { "" };
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	/*CONSOLE_CURSOR_INFO CCI;
	CCI.bVisible = false;
	CCI.dwSize = true;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CCI);*/
	system("color F0");
	vector<double> data;
	//setlocale(LC_ALL, "rus");
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 1));
	cout << "\t\t\tМеню\n";
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
	cout << "\n\t1 - Вычисление сочентания" << cursor[1] << "\n\t2 - Вычисление размещения" << cursor[2] << "\n\t3 - Вычисление перестановок" << cursor[3] << "\n\t4 - Вычисление вероятности формулой Бернулли" << cursor[4] << "\n\t";
	cout << "5 - Вычисление вероятности формулой Пуассона" << cursor[5] << "\n\t6 - ДСВ - числовые характеристики" << cursor[6] << "\n\t7 - Биноминальное распеределине - числовые характеристики" << cursor[7] << "\n\t";
	cout << "8 - Формула распределения Пуассона - числовые характеристики" << cursor[8] << "\n\t9 - НСВ - числовые характеристики" << cursor[9] << "\n\t10 - НСВ - вероятность попадания в заданный интервал" << cursor[9] << "\n\t";
	cout << "11 - Показательное распределение" << cursor[11] << "\n\t12 - Равномерное распределение" << cursor[12] << "\n\t13 - Нормальное распределение" << cursor[13] << "\n\t14 - Нахождение приближенного значения интеграла" << cursor[14] << "\n\t";
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 4));
	cout << "\t      0 - Выход\n" << cursor[0] << "";
	//d();
	var = input();
	data.push_back(var);
	input_data(var, data);
	return data;
}

void menu::error_handler(int value)
{
	if (value > 10) {
		cout << errors[value];
		system("pause");
		system("cls");
		input_data(var,data);
	}
	else {
		cout << errors[value] << endl;
	}
}

void menu::answer_output(vector<double> ansver, int value)
{
	cout << "Результат: ";
	for (auto &it : ansver) {
		cout << it << endl;
	}
}



