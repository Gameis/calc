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

using namespace std;


int main()
{

		menu currentMenu;
		vector<Func*> functions = vector<Func*>({ new combination() , new accommodation(), new arrangement(), new Bernully(), new Puasson(), new DRV(), new Binom(), new Poisson(), new stub(), new CRV(), new IndicataseDistribution(), new stub(), new NormalDistribution(), new Integral([&currentMenu]() {return currentMenu.getFunction(); }) });

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
				currentMenu.answer_output(answer,++function_number);
			}
			if (0 < executionCode)
			{
				currentMenu.error_handler(executionCode);
			}
			}
			catch (...)
			{

			}
		}
			


	return 0;
}