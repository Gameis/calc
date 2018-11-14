#pragma once
#include "func.h"
class stub :
	public Func
{
public:
	virtual vector<double> answer() override;

	virtual unsigned compute(const vector<double>& data) override;

};

