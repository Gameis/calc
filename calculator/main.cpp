#include <vector>
#include "menu.h"
#include "arrangement.h"
#include "Bernully.h"
#include "binom.h"
#include "DRV.h"
#include "pocas.h"
#include "Puasson.h"
#include "func.h"
#include "stub.h"

using namespace std;


int main()
{
	try
	{
		vector<func*> functional = vector<func*>({ new stub() , new stub(), new arrangement(), new Bernully(), new Puasson(), new DRV(), new binom(), new stub(), new pokaz_ras(), new stub(), new stub(), new stub() });
		menu _menu;
		while (true)
		{
			_menu.begin();
			auto var = _menu.result();
			unsigned function_number = var.at(0);
			if (function_number == 0) break;
			else
			{
				--function_number;
			}
			var = vector<double>(++var.begin(), var.end());
			unsigned complete_code = functional.at(function_number)->compute(var);
			if (0 <= complete_code < 11)
			{
				auto answer = functional.at(function_number)->answer();
				_menu.answer_output(answer,++function_number);
			}
			if (0 < complete_code)
			{
				//_menu.error_handler(complete_code);
			}
		}
	}
	catch (const std::exception& _exception)
	{
		;
	}
	return 0;
}