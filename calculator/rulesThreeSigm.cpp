#include "rulesThreeSigm.h"

unsigned rulesThreeSigm::compute(const vector<double> & answer) {
	this->_a = answer[0];
	this->_sigma = answer[1];
	if (this->_sigma < 0) return 6; //Сигма не может быть < 0
	else if (answer.size() != 2) return 11; //Слишком много или мало аргументов
	else return 0;
	double threeSigm;
	threeSigm = this->_sigma * 3;
	this->_answers.clear();
	if(this->_a>0){
		this->_leftBorder = this->_a + (-threeSigm);
		this->_rightBorder= this->_a + threeSigm;
		this->_answers.push_back(this->_leftBorder);
		this->_answers.push_back(this->_rightBorder);
	}
	else {

		this->_leftBorder = this->_a - (-threeSigm);
		this->_rightBorder = this->_a - threeSigm;
		this->_answers.push_back(this->_rightBorder);
		this->_answers.push_back(this->_leftBorder);
	}
}
