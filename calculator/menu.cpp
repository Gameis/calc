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
	case 1: cout << "n: "; data.push_back(input()); cout << "m: "; data.push_back(input()); break;
	case 2: cout << "n: "; data.push_back(input()); cout << "m: "; data.push_back(input()); break;
	case 3: cout << "n: "; data.push_back(input()); break;
	case 4: cout << "n: "; data.push_back(input()); cout << "m: "; data.push_back(input()); cout << "p: "; data.push_back(input()); break;
	case 5: cout << "n: "; data.push_back(input()); cout << "m: "; data.push_back(input()); cout << "p: "; data.push_back(input()); break;
	case 6: cout << "Введите колличество данных: "; templ = input(); for (int i = 0; i < templ; i++) { cout << "x" << i + 1 << ' '; data.push_back(input()); cout << "p" << i + 1 << ' '; data.push_back(input()); } break;
	case 7: cout << "n: "; data.push_back(input()); cout << "p: "; data.push_back(input()); cout << "q: "; data.push_back(input()); break;
	case 8: cout << "n: "; data.push_back(input()); cout << "p: "; data.push_back(input()); break;
	//case 9:
	//case 10:
	//case 11:
	//case 12:
	case 13: cout << "a: "; data.push_back(input()); cout << "Ъ: "; data.push_back(input()); break;
	case 14: cout << "Начало интервала: "; data.push_back(input()); cout << "Конец интервала: "; data.push_back(input());  cout << "Точность: "; data.push_back(input()); cout << "Эпсилон: "; data.push_back(input());
	}
}

vector<double> menu::start() {
	string cursor[15] = { "" };
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("color F0");
	vector<double> data;
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 1));
	cout << "\t\t\tМеню\n";
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
	cout << "\n\t1 - Вычисление сочентания" << cursor[1] << "\n\t2 - Вычисление размещения" << cursor[2] << "\n\t3 - Вычисление перестановок" << cursor[3] << "\n\t4 - Вычисление вероятности формулой Бернулли" << cursor[4] << "\n\t";
	cout << "5 - Вычисление вероятности формулой Пуассона" << cursor[5] << "\n\t6 - ДСВ - числовые характеристики" << cursor[6] << "\n\t7 - Биноминальное распеределине - числовые характеристики" << cursor[7] << "\n\t";
	cout << "8 - Формула распределения Пуассона - числовые характеристики" << cursor[8] << "\n\t9 - НСВ - числовые характеристики" << cursor[9] << "\n\t10 - НСВ - вероятность попадания в заданный интервал" << cursor[9] << "\n\t";
	cout << "11 - Показательное распределение" << cursor[11] << "\n\t12 - Равномерное распределение" << cursor[12] << "\n\t13 - Нормальное распределение" << cursor[13] << "\n\t14 - Нахождение приближенного значения интеграла" << cursor[14] << "\n\t";
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 4));
	cout << "\t      0 - Выход\n" << cursor[0] << "";
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
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

string menu::getFunction()
{
	string str;
	cout << "Введите функцию: ";
	getline(cin, str);
	return string();
}

void menu::answer_output(vector<double> ansver, int value)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
	switch (value) {
	case 1: cout << "\nКолличество сочетаний: "; cout << ansver[0]; break;
	case 2: cout << "\nКолличество размещений: "; cout << ansver[0]; break;
	case 3: cout << "\nКолличество перестановок: "; cout << ansver[0]; break;
	case 4: cout << "\nВероятность: "; cout << ansver[0]; break;
	case 5: cout << "\nВероятность: "; cout << ansver[0]; break;
	case 6: cout << "\nМатематическое ожидание: "; cout << ansver[0]; cout << "\nДисперсия: "; cout << ansver[1]; cout << "\nСреднее квадратическое отклоенение: "; cout << ansver[2]; cout << "\nАссиметрия: " << ansver[3]; cout << "\nЭксцесс: " << ansver[4]; break;
	case 7: cout << "\nМатематическое ожидание: "; cout << ansver[0]; cout << "\nДисперсия: "; cout << ansver[1]; cout << "\nСреднее квадратическое отклоенение: "; cout << ansver[2]; cout << "\nАссиметрия: " << ansver[3]; cout << "\nЭксцесс: " << ansver[4]; break;
	case 8: cout << "\nМатематическое ожидание: "; cout << ansver[0]; cout << "\nДисперсия: "; cout << ansver[1]; cout << "\nСреднее квадратическое отклоенение: "; cout << ansver[2]; cout << "\nАссиметрия: " << ansver[3]; cout << "\nЭксцесс: " << ansver[4]; break;
	case 9: cout << "\nМатематическое ожидание: "; cout << ansver[0]; cout << "\nДисперсия: "; cout << ansver[1]; cout << "\nСреднее квадратическое отклоенение: "; cout << ansver[2]; cout << "\nАссиметрия: " << ansver[3]; cout << "\nЭксцесс: " << ansver[4]; break;
	case 10: cout << "\nВероятность: "; cout << ansver[0]; break;
	case 11: cout << "\nМатематическое ожидание: "; cout << ansver[0]; cout << "\nДисперсия: "; cout << ansver[1]; cout << "\nСреднее квадратическое отклоенение: "; cout << ansver[2]; cout << "\nАссиметрия: " << ansver[3]; cout << "\nЭксцесс: " << ansver[4]; break;
	case 12: cout << "\nМатематическое ожидание: "; cout << ansver[0]; cout << "\nДисперсия: "; cout << ansver[1]; cout << "\nСреднее квадратическое отклоенение: "; cout << ansver[2]; cout << "\nАссиметрия: " << ansver[3]; cout << "\nЭксцесс: " << ansver[4]; break;
	case 13: cout << "\nМатематическое ожидание: "; cout << ansver[0]; cout << "\nДисперсия: "; cout << ansver[1]; cout << "\nСреднее квадратическое отклоенение: "; cout << ansver[2]; cout << "\nАссиметрия: " << ansver[3]; cout << "\nЭксцесс: " << ansver[4]; break;
	case 14: cout << "\nРезультат: "; cout << ansver[0]; break;
	}
	cout << endl;
	system("pause");
}



