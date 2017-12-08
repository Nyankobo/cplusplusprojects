// TanyaLandreth
// Wk9_Division Sales Expenses.cpp
// 7/15/16
//

#include "stdafx.h"
#include "DivSales_C.h"
#include "DivExpenses_C.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Fill_DivSales(DivSales_C[], const int);
void Fill_DivExp(DivExpenses_C[], const int);

int main()
{	
	//objects created
	DivSales_C divisionSales;
	DivExpenses_C divisionExpenses;

	//create arrays

	const int SIZE = 3;
	DivSales_C divisionSalesArray[SIZE];			//3 DivSales objects
	DivExpenses_C divisionExpensesArray[SIZE];		//3 DivExpenses_C objects

	Fill_DivSales(divisionSalesArray, SIZE);
	Fill_DivExp(divisionExpensesArray, SIZE);

	double quarterTot = 0.00;

	//this loop should pick up the division array
	double number = 0.00;
	int s = SIZE + 1;

	cout << "\nDivision:\tQuarter:\tSales:" << endl;

	//this loops to pick the division array
	for (int outer = 0; outer < SIZE ; outer++)
	{		
		//this loops to pick the quarter array
		for (int inner = 0; inner < s; inner++)
		{
			//Division		Quarter		Amount
			cout << right << setprecision(2) << fixed << showpoint
				<< outer + 1 << "\t\t"
				<< inner + 1 << "\t\t$"
				<< divisionSalesArray[inner].Grab_Value(inner) << endl;
		}

		cout << "Division #" << outer + 1 << " Annual Expenses: " <<
			divisionSalesArray[outer].Get_Expenses(divisionExpensesArray[outer], outer) << endl;

	}

	cout << "\n==================================================" << endl;

	double overallTotalSales = 0.00, overallTotalExp = 0.00, overallNetSales = 0.00;

	cout << right << setprecision(2) << fixed << showpoint <<
		"\nOverall Total Sales:\t$";
		overallTotalSales = DivSales_C::Get_All_Sales();
	cout << right << overallTotalSales << endl;

	cout << "Total Expenses:\t\t$";
		overallTotalExp = DivExpenses_C::Get_AllExpenses();
	cout << right << overallTotalExp << endl;

	cout << "Net Sales:\t\t$";
		overallNetSales = (DivSales_C::Get_All_Sales()) - (DivExpenses_C::Get_AllExpenses());
	cout << right << overallNetSales << endl;

	system("pause");
    return 0;
}
//the user will fill the array containing the three DivSales objects with four quarters 
//of sales figures for each division
void Fill_DivSales(DivSales_C fill[], const int size)
{
	double number = 0.00;
	int s = size + 1;

	//this loops to pick the division array
	for (int outer = 0; outer < size; outer++)
	{

		//this loops to pick the quarter array
		for (int inner = 0; inner < s; inner++)
		{
			cout << "Enter Sales for Division #" << outer + 1 << ", Quarter #" << inner + 1 << ": > $";
			cin >> number;

			fill[inner].Set_Sales_Figures(number, inner);

			//add sales to static variable
			fill[inner].Set_All_Sales(number);

		}
		
	}
}
// the user will fill the array containing the three DivExpenses objects
//with an annual expense figure for each division 
void Fill_DivExp(DivExpenses_C fill[], const int size) 
{
	int s = size;
	double number = 0.00;

	for (int outer = 0; outer < size; outer++)
	{
			//this loops to pick the quarter array
		cout << "Enter Division #" << outer + 1 << " Annual Expenses: > $";
			cin >> number;

			fill[outer].Set_Expenses(number, outer);

			fill[outer].Set_AllExpenses(number);
	}



}