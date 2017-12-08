#include "stdafx.h"
#include "DivSales_C.h"
#include "DivExpenses_C.h"
#include <iostream>
#include <string>
using namespace std;

//static variable definition:
double DivSales_C::allSales = 0.00;

//*****************************************
//CONSTRUCTORS: _______________________________________________
//a default constructor 
	DivSales_C::DivSales_C()
		{
			salesFig[4];

			for (int i = 0; i < 4; i++)
				salesFig[i] = 0.00;

//			for (int i = 0; i < 4; i++)
//				cout << "Default sales array: " << salesFig[i] << endl;

		}

//and a constructor which accepts four quarters of sales figures				????????
//which will be stored in the member array
	DivSales_C::DivSales_C(double a, int subsc)
		{
			for (int i = subsc; i < 4; i++)
				salesFig[i] = a;
		}


//*****************************************
//SETTERS: _______________________________________________
//a member function which accepts four quarters of sales figures and stores them in
//the member array
	void DivSales_C::Set_Sales_Figures(double a, int subsc)
	{
		salesFig[subsc] = a;
	}

	void DivSales_C::Set_All_Sales(double toadd)
		{
			//add sales to the static variable whenever sales are posted to a division
			allSales += toadd;

		}

//GETTERS: _______________________________________________
//a member function which takes an integer argument within the range of 0-3.
//This argument is to be used as a subscript into the division quarterly sales array.
//The function should return the value of the array element with that subscript. 

	double DivSales_C::Grab_Value(int num)
	{
		return salesFig[num];
	}

	double DivSales_C::Get_All_Sales()
	{
		return allSales;
	}


	double DivSales_C::Get_Expenses(DivExpenses_C &obj, int num)
		{
		
			return obj.Get_Expenses(num);

		}

DivSales_C::~DivSales_C(){}