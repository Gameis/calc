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
	case 6: cout << "Введите колличество данных: "; templ = input(); for (int i = 0; i < templ; i++) { cout << "x" << i + 1 << ' '; data.push_back(input()); cout << "p" << i + 1 << ' '; data.push_back(input()); } break;
	case 7: cout << "n: "; data.push_back(input()); cout << "p: "; data.push_back(input()); cout << "q: "; data.push_back(input()); break;
	case 8: cout << "n: "; data.push_back(input()); cout << "p: "; data.push_back(input()); break;
	case 9: cout << "n: "; data.push_back(input()); cout << "p: "; data.push_back(input()); break;
	case 10: cout << "Левая граница интервала: "; data.push_back(input());  cout << "Правая граница интервала: "; data.push_back(input()); cout << "Левая граница искомого интервала: "; data.push_back(input()); cout << "Правая граница искомого интервала: "; data.push_back(input()); cout << "x: "; data.push_back(input());
	case 11: cout << "Левая граница интервала: "; data.push_back(input());  cout << "Правая граница интервала: "; data.push_back(input());
	case 12: cout << "Это не конечная версия продукта, поэтому данный функционал отсутствует, следите за обновлениями с:";
	case 13: cout << "a: "; data.push_back(input()); cout << "Ъ: "; data.push_back(input()); break;
	case 14: cout << "Начало интервала: "; data.push_back(input()); cout << "Конец интервала: "; data.push_back(input());  cout << "Количество точек: "; data.push_back(input()); cout << "Точность: "; data.push_back(input());
	case 15: cout << "n: "; data.push_back(input()); cout << "p: "; data.push_back(input()); cout << "m: "; data.push_back(input()); cout << "Левая граница интервала: "; data.push_back(input());  cout << "Правая граница интервала: "; data.push_back(input()); break;
	case 16: cout << "n: "; data.push_back(input()); cout << "p: "; data.push_back(input()); cout << "Левая граница интервала: "; data.push_back(input());  cout << "Правая граница интервала: ";
	case 17: cout << "a: "; data.push_back(input()); cout << "Сигма:"; data.push_back(input()); cout << "Левая граница интервала: "; data.push_back(input());  cout << "Правая граница интервала: "; data.push_back(input()); break;
	case 18: cout << "Левая граница интервала: "; data.push_back(input());  cout << "Правая граница интервала: "; data.push_back(input()); cout << "Лямбда: "; data.push_back(input());
	case 19: cout << "Это не конечная версия продукта, поэтому данный функционал отсутствует, следите за обновлениями с:";
	case 20: cout << "Эпсилон :"; data.push_back(input()); cout << "Сигма:"; data.push_back(input()); break;
	case 21: cout << "Эпсилон :"; data.push_back(input()); cout << "Сигма:"; data.push_back(input()); break;
	default: cout << "повторите ввод\n";
	}
}

vector<double> Menu::start() {
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("color F0");
	vector<double> data;
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 1));
	cout << "\t\t\tМеню\n";
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
	cout << "\n\t1 - Вычисление сочентания" <<  "\n\t2 - Вычисление размещения" <<  "\n\t3 - Вычисление перестановок" << "\n\t4 - Вычисление вероятности формулой Бернулли" << "\n\t";
	cout << "5 - Вычисление вероятности формулой Пуассона" << "\n\t6 - ДСВ - числовые характеристики" << "\n\t7 - Биноминальное распеределине - числовые характеристики" << "\n\t";
	cout << "8 - Формула распределения Пуассона - числовые характеристики" << "\n\t9 - НСВ - числовые характеристики" << "\n\t10 - НСВ - вероятность попадания в заданный интервал" << "\n\t";
	cout << "11 - Показательное распределение" << "\n\t12 - Равномерное распределение" << "\n\t13 - Нормальное распределение" << "\n\t14 - Нахождение приближенного значения интеграла" << "\n\t";
	cout << "\n\t Найти вероятность попадания в заданный интервал:\n\n";
	cout << "\t15 - Биномиальное распеределение\n\t16 - Распеределение по Пуассону\n\t17 - Нормальное распеределение\n\t18 - Показательное распеределение\n\t19 - Равномерное распеределение\n\t20 - Правило Трех сигм\n\t21 - шанс нормального отклонения\n";
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 4));
	cout << "\t      0 - Выход\n" << "";
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
	cout << "\nСинус - sin, \nКосинус - cos, \nТангенс - tan, \nКотангенс - ctan, \nАрксинус - asin, \nАрккосинус - acos, \nАртангенс - atan, \nАрккатангенс - actan, \nКвадратный корень - sqrt, \nКубический корень - cbrt, \nМодуль - abs" << endl << "Введите функцию: ";
	getline(cin, str);
	return str;
}

void Menu::outputinAnswer(vector<double> ansver, int value)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 4));
	switch (value) {
	case 1: cout << "\nКолличество сочетаний: "; cout << ansver.at(0); break;
	case 2: cout << "\nКолличество размещений: "; cout << ansver.at(0); break;
	case 3: cout << "\nКолличество перестановок: "; cout << ansver.at(0); break;
	case 4: cout << "\nВероятность: "; cout << ansver.at(0); break;
	case 5: cout << "\nВероятность: "; cout << ansver.at(0); break;
	case 6: cout << "\nМатематическое ожидание: "; cout << ansver.at(0); cout << "\nДисперсия: "; cout << ansver.at(1); cout << "\nСреднее квадратическое отклоенение: "; cout << ansver.at(2); cout << "\nАссиметрия: " << ansver.at(3); cout << "\nЭксцесс: " << ansver.at(4); break;
	case 7: cout << "\nМатематическое ожидание: "; cout << ansver.at(0); cout << "\nДисперсия: "; cout << ansver.at(1); cout << "\nСреднее квадратическое отклоенение: "; cout << ansver.at(2); cout << "\nАссиметрия: " << ansver.at(3); cout << "\nЭксцесс: " << ansver.at(4); break;
	case 8: cout << "\nМатематическое ожидание: "; cout << ansver.at(0); cout << "\nДисперсия: "; cout << ansver.at(1); cout << "\nСреднее квадратическое отклоенение: "; cout << ansver.at(2); cout << "\nАссиметрия: " << ansver.at(3); cout << "\nЭксцесс: " << ansver.at(4); break;
	case 9: cout << "\nМатематическое ожидание: "; cout << ansver.at(0); cout << "\nДисперсия: "; cout << ansver.at(1); cout << "\nСреднее квадратическое отклоенение: "; cout << ansver.at(2); cout << "\nАссиметрия: " << ansver.at(3); cout << "\nЭксцесс: " << ansver.at(4); break;
	case 10: cout << "\nВероятность: "; cout << ansver.at(0); break;
	case 11: cout << "\nМатематическое ожидание: "; cout << ansver.at(0); cout << "\nДисперсия: "; cout << ansver.at(1); cout << "\nСреднее квадратическое отклоенение: "; cout << ansver.at(2); cout << "\nАссиметрия: " << ansver.at(3); cout << "\nЭксцесс: " << ansver.at(4); break;
	case 12: cout << "\nМатематическое ожидание: "; cout << ansver.at(0); cout << "\nДисперсия: "; cout << ansver.at(1); cout << "\nСреднее квадратическое отклоенение: "; cout << ansver.at(2); cout << "\nАссиметрия: " << ansver.at(3); cout << "\nЭксцесс: " << ansver.at(4); break;
	case 13: cout << "\nМатематическое ожидание: "; cout << ansver.at(0); cout << "\nДисперсия: "; cout << ansver.at(1); cout << "\nСреднее квадратическое отклоенение: "; cout << ansver.at(2); cout << "\nАссиметрия: " << ansver.at(3); cout << "\nЭксцесс: " << ansver.at(4); break;
	case 14: cout << "\nРезультат: "; cout << ansver.at(0); break;
	case 15: cout << "\nВероятность: "; cout << ansver.at(0); break;
	case 16: cout << "\nВероятность: "; cout << ansver.at(0); break;
	case 17: cout << "\nВероятность: "; cout << ansver.at(0); break;
	case 18: cout << "\nВероятность: "; cout << ansver.at(0); break;
	case 19: cout << "\nВероятность: "; cout << ansver.at(0); break;
	case 20: cout << "\nЛевая граница "; cout << ansver.at(0); cout << "\nЛевая граница "; cout << ansver.at(1); break;
	case 21: cout << "\nВероятность: "; cout << ansver.at(0); break;
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
	}
	cout << endl;
	system("pause");
	system("cls");
}