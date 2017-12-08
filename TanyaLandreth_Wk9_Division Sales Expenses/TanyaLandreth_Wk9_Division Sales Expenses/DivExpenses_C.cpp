#include "stdafx.h"
#include "DivSales_C.h"
#include "DivExpenses_C.h"
#include <iostream>
#include <string>

using namespace std;

//static variable definition
	double DivExpenses_C::allExp = 0.0;

//*****************************************
//CONSTRUCTORS: _______________________________________________
	DivExpenses_C::DivExpenses_C()
		{
			expFig[3] = { 0.00 };

		}


	DivExpenses_C::~DivExpenses_C()
		{
		}


//SETTERS: _______________________________________________
// member functions Set_Expenses and Get_Expenses
	void DivExpenses_C::Set_Expenses(double e, int num)
		{
			expFig[num] = e;

		}


	//add up expenses
	void DivExpenses_C::Set_AllExpenses(double ex)
		{
			allExp += ex;

		}

//*****************************************
//GETTERS: _______________________________________________
//return value in array
	double DivExpenses_C::Get_Expenses(int num)
	{
		return expFig[num];

	}

	//return all expenses
	double DivExpenses_C::Get_AllExpenses()
		{
			return allExp;

		}
