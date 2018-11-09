#include "DRV.h"



DRV::DRV()
{
}


DRV::~DRV()
{
}
unsigned DRV::compute(const vector<double> & answer) {
	this->initialize_Data(answer);
	if (this->check_P() == true && this->already_X() == false) {
		if (answer.size() < 5) return 11; // Кол-во X-ов должно быть > "2"
		this->solution();
		return 0;
	}
	else {
		if (answer.size() < 5) return 11; // Кол-во X-ов должно быть > "2"
		if (this->check_P() != true) return 1; // В распределение ДСВ присутствуют одинаковые Х-ы
		if (this->already_X() != false) return 10; // Вероятность < или > "1"
	}
}
void DRV::initialize_Data(vector<double> answer) {
	int i = 1;
	while (i < answer.size()) {
		this->x.push_back(answer[i]);
		drv.insert(pair<double, double>(answer[i], answer[i+1]));
		i += 2;
	}
}
bool DRV::already_X() {
	for (int i = 0; i < this->x.size();i++) {
		for (int it = i+1; it < this->x.size(); it++) {
			if (this->x[i] == this->x[it]) return true;
		}
	}
	return false;
}
bool DRV::check_P() {
	for (auto it = drv.begin(); it != drv.end(); ++it) {
		sum += (*it).second;
	}
	if (this->sum == 1) { 
		return true; 
	}
	else {
		return false;
	}
}
void DRV::solution() {
	this->answer.push_back(this->NY(1));
	this->answer.push_back(this->NY(2)- pow(this->NY(1),2));
	this->SR = sqrt(this->NY(2) - pow(this->NY(1), 2));
	this->answer.push_back(this->SR);
	this->MY3 = this->NY(3) - 3 * this->NY(1)*this->NY(2) + 2 * pow(this->NY(1), 3);
	this->MY4 = this->NY(4) - 4 * this->NY(1)*this->NY(3) + 6 * pow(this->NY(1), 2)*this->NY(2) - 3 * pow(this->NY(1), 4);
	this->answer.push_back(this->MY3 / (pow(this->SR, 3)));
	this->answer.push_back((this->MY4 / (pow(this->SR, 4))) - 3);
}
double DRV::NY(int i) {
	double temp = 0;
	for (auto it = drv.begin(); it != drv.end(); ++it) {
		temp += pow((*it).first, i)*(*it).second;
	}
	return temp;
}