#include "DRV.h"

unsigned DRV::compute(const vector<double> & answer) {
	this->initializeData(answer);
	if (this->isHappen() == true && this->isAlreadyX() == false) {
		if (answer.size() < 4) return 11; // Кол-во X-ов должно быть >= "2"
		this->computeNumericalCharacteristics();
		return 0;
	}
	else {
		if (this->isHappen() != true) return 13; // Вероятность < или > "1", должна быть = "1"
		else if (this->isAlreadyX() != false) return 10; // В распределение ДСВ присутствуют одинаковые Х-ы
		else if (answer.size() < 4) return 11; // Кол-во X-ов должно быть >= "2"
	}
}
void DRV::initializeData(vector<double> answer) {
	int i = 0;
	while (i < answer.size()) {
		this->_x.push_back(answer[i]);
		_drv.insert(pair<double, double>(answer[i], answer[i + 1]));
		i += 2;
	}
}
bool DRV::isAlreadyX() {
	for (int i = 0; i < this->_x.size(); i++) {
		for (int it = i + 1; it < this->_x.size(); it++) {
			if (this->_x[i] == this->_x[it]) return true;
		}
	}
	return false;
}
bool DRV::isHappen() {
	for (auto it = _drv.begin(); it != _drv.end(); ++it) {
		this->_sum += (*it).second;
	}
	if (this->_sum == 1) {
		return true;
	}
	else {
		return false;
	}
}
void DRV::computeNumericalCharacteristics() {
	this->_answers.clear();
	this->_answers.push_back(this->computeNY(1));
	this->_answers.push_back(this->computeNY(2) - pow(this->computeNY(1), 2));
	this->_theAvarageSquare = sqrt(this->computeNY(2) - pow(this->computeNY(1), 2));
	this->_answers.push_back(this->_theAvarageSquare);
	this->_my3 = this->computeNY(3) - 3 * this->computeNY(1)*this->computeNY(2) + 2 * pow(this->computeNY(1), 3);
	this->_my4 = this->computeNY(4) - 4 * this->computeNY(1)*this->computeNY(3) + 6 * pow(this->computeNY(1), 2)*this->computeNY(2) - 3 * pow(this->computeNY(1), 4);
	this->_answers.push_back(this->_my3 / (pow(this->_theAvarageSquare, 3)));
	this->_answers.push_back((this->_my4 / (pow(this->_theAvarageSquare, 4))) - 3);
}
double DRV::computeNY(int i) {
	double temp = 0;
	for (auto it = _drv.begin(); it != _drv.end(); ++it) {
		temp += pow((*it).first, i)*(*it).second;
	}
	return temp;
}