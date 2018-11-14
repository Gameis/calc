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
	//Вывод в консоль начального меню, считывание данных пользователя
	
	inline vector<double> result() { return this->data; } 
	//Возвращает вектор типа double, в которм хранятся данные, считанные с консоли 

	menu();

	void error_handler(unsigned value); 
	//Обрабатывает ошибку; 
	//value - код ошибки

	string getFunction();


	/////////////////////////////////////////
	/// \breif вывод результата
	/// \param ansver - вектор результата
	///               value - номер функции
	/////////////////////////////////////////
	void answer_output(vector<double> ansver, int value);

};

