#include <vector>
#include "menu.h"
#include "arrangement.h"
#include "Bernully.h"
#include "binom.h"
#include "DRV.h"
#include "IndicataseDistribution.h"
#include "Puasson.h"
#include "func.h"
#include "stub.h"
#include "combination.h"
#include "Poisson.h"
#include "accommodation.h"
#include "RV.h"
#include "FunctionParser.h"
#include "Integral.h"
#include "NormalDistribution.h"
#include "ChanceOfDeviation.h"
#include "ProbabilityIndicataseDistribution.h"
#include "rulesThreeSigm.h"
#include "binomialDistribution.h"

using namespace std;


int main()
{

		Menu currentMenu;
		vector<Func*> functions = vector<Func*>({ new combination() , new accommodation(), new arrangement(), new Bernully(), new Puasson(), new DRV(), new Binom(), new Poisson(), new stub(), new CRV(), new IndicataseDistribution(), new stub(), new NormalDistribution(), new Integral([&currentMenu]() {return currentMenu.getFunction(); }),
			new BinomialDistibution(), new stub(), new stub(), new ProbabilityIndicataseDistribution(), new stub(), new rulesThreeSigm(), new ChanceOfDeviation()});

		while (true)
		{
			try
			{
			currentMenu.begin();
			auto vectorOfParameters = currentMenu.result();
			unsigned function_number = vectorOfParameters.at(0);
			if (function_number == 0) break;
			else
			{
				--function_number;
			}
			vectorOfParameters = vector<double>(++vectorOfParameters.begin(), vectorOfParameters.end());
			unsigned executionCode = functions.at(function_number)->compute(vectorOfParameters);
			if (0 <= executionCode && executionCode < 11)
			{
				auto answer = functions.at(function_number)->answer();
				currentMenu.outputinAnswer(answer,++function_number);
			}
			if (0 < executionCode)
			{
				currentMenu.errorOutput(executionCode);
			}
			}
			catch (...)
			{

			}
		}
			


	return 0;
}