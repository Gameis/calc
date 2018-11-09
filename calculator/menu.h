#pragma once
#include <vector>
#include <iostream>

using namespace std;

class menu
{
private:
	vector<double> data;
public:
	vector<double> start();
	void begin() {
		data = start();
	}
	inline vector<double> result() { return this->data; }
};

