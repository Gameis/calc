#include "DRV.h"

unsigned DRV::compute(const vector<double> & answer) {
	this->initializeData(answer);
	if (this->isHappen() == true && this->isAlreadyX() == false) {
		if (answer.size() < 4) return 11; // ���-�� X-�� ������ ���� >= "2"
		this->computeNumericalCharacteristics();
		return 0;
	}
	else {
		if (this->isHappen() != true) return 13; // ����������� < ��� > "1", ������ ���� = "1"
		else if (this->isAlreadyX() != false) return 10; // � ������������� ��� ������������ ���������� �-�
		else if (answer.size() < 4) return 11; // ���-�� X-�� ������ ���� >= "2"
	}
}
void DRV::initializeData(vector<double> answer) {
	int _i = 0;
	while (_i < answer.size()) {
		this->_x.push_back(answer[_i]);
		_drv.insert(pair<double, double>(answer[_i], answer[_i + 1]));
		_i += 2;
	}
}
bool DRV::isAlreadyX() {
	for (int _i = 0; _i < this->_x.size(); _i++) {
		for (int _it = _i + 1; _it < this->_x.size(); _it++) {
			if (this->_x[_i] == this->_x[_it]) return true;
		}
	}
	return false;
}
bool DRV::isHappen() {
	for (auto _it = _drv.begin(); _it != _drv.end(); ++_it) {
		_sum += (*_it).second;
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
double DRV::computeNY(int _i) {
	double _temp = 0;
	for (auto _it = _drv.begin(); _it != _drv.end(); ++_it) {
		_temp += pow((*_it).first, _i)*(*_it).second;
	}
	return _temp;
}