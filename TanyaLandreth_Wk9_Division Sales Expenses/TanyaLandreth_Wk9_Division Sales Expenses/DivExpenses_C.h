#pragma once
#ifndef DIVSEXPENSES_C_H
#define DIVSEXPENSES_C_H

class DivExpenses_C
{
private:
	// a variable to hold a division's annual expenses
	double expFig[3];
	static double allExp;

public:
	//constructors 
	DivExpenses_C();

	// member functions Set_Expenses and Get_Expenses
	void Set_Expenses(double e, int num);
	
	//return value in array
	double Get_Expenses(int num);

	//add up expenses
	static void Set_AllExpenses(double ex);

	//return all expenses
	static double Get_AllExpenses();

	~DivExpenses_C();
};

#endif
