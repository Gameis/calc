#include "RV.h"

unsigned CRV::compute(const vector<double>& answer_s)
{
	a1=answer_s[1];
	b1=answer_s[2];
	a=answer_s[3];
	b=answer_s[4];
	x=answer_s[5];
		if (b1<a1)
		{
		return 10;	//левая граница не может быть больше правой и быть меньше 0
		}
		else if (a<a1)
		{
		return 11; //Левая граница интервала не может быть меньше левой границы интервала для x;
		}
		else if (a>b1)
		{
			return 12; //Левая граница интервала не может быть больше границы интервала для x;
		}
		else if (b<a || b>b1)
		{
			return 13; //Правая граница интервала не может быть больше правой границы интервала для x и не может быть больше левой границы;
		}
		else if (x<=0)
		{
			return 14; //Костанта не может быть меньше 0 и не может быть = 0;
		}
		else if (x>=1)
		{
			return 15; //Константа не может быть больше или равной 1
		}
		else {
			p = x * (b - a);
			if (p < 0)
			{
				p = p * (-1);
			}
			else if (p > 1 || p == 1)
			{
				p = 1;
			}
				this->answer_s.push_back(p);
				return 0;
		}
}