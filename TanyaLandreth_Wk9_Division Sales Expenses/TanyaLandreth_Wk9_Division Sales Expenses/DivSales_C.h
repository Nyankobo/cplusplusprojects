#pragma once
#ifndef DIVSALES_C_H
#define DIVSALES_C_H
#include "DivExpenses_C.h"


class DivSales_C
{
private:
	//an array with four elements for holding four quarters of sales figures for the division
		double salesFig[4];

	//a private static variable for holding the total corporate sales for all divisions for
	//the entire year.
		static double allSales;

public:
	//Constructors:
	//a default constructor 
		DivSales_C();

	//and a constructor which accepts four quarters of sales figures
	//which will be stored in the member array
		DivSales_C(double a, int subsc);

	//a member function which accepts four quarters of sales figures and stores them in
	//the member array
		void Set_Sales_Figures(double a, int subsc);

	//-a member function which takes an integer argument within the range of 0-3.
	//This argument is to be used as a subscript into the division quarterly sales array.
	//The function should return the value of the array element with that subscript. 
		double Grab_Value(int num);

//*****************************************
	//other appropriate getter and setter member functions for the two member variables

		static void Set_All_Sales(double);

		double Get_Expenses(DivExpenses_C &obj, int num);

		static double Get_All_Sales();

	//deconstructor
	~DivSales_C();
};

#endif