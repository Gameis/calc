#pragma once
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class menu
{
private:
	vector<double> data;
	vector<string> errors;
public:
	vector<double> start();
	
	void begin() { data = start(); } 
	//Вывод в консоль начального меню, считывание данных пользователя
	
	inline vector<double> result() { return this->data; } 
	//Возвращает вектор типа double, в которм хранятся данные, считанные с консоли 
	
	void set(const vector<string>& error) { errors = error; }; 
	//Задает вектор строк со списком ошибок

	void error_handler(int value); 
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

