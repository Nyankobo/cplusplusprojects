#include "stdafx.h"
#include "PreferredCustomer_C.h"
#include "PersonData_C.h"
#include "CustomerData_C.h"

double const FIRST_LEVEL = 500.00;
double const SECOND_LEVEL = 1000.00;
double const THIRD_LEVEL = 1500.00;
double const FOURTH_LEVEL = 2000.00;
double const FIVE_PCT_DISC = 0.95;
double const SIX_PCT_DISC = 0.94;
double const SEVEN_PCT_DISC = 0.93;
double const TEN_PCT_DISC = 0.90;
double const FIVE = 5.00;
double const SIX = 6.00;
double const SEVEN = 7.00;
double const TEN = 10.00;

//Constructors:
PreferredCustomer_C::PreferredCustomer_C() : PersonData_C::PersonData_C(), CustomerData_C::CustomerData_C()
	{
		purchasesAmount = 0.0;
		discountLevel = 0.0;
	}

	PreferredCustomer_C::PreferredCustomer_C(double amt, double lvl, int num, bool yn, string l, string f, int z) : PersonData_C::PersonData_C(l, f, z), CustomerData_C::CustomerData_C(num, yn)
	{
		purchasesAmount = amt;
		discountLevel = lvl;
	}

//Setters:
	void PreferredCustomer_C::Set_PurchaseAmt(double amt)
	{
		purchasesAmount += amt;
	}
	void PreferredCustomer_C::Set_DiscountLvl(double lvl)
	{
		discountLevel = lvl;
	}

//Getters:
	double PreferredCustomer_C::Get_PurchaseAmt() const
	{
		return purchasesAmount;
	}
	double PreferredCustomer_C::Get_DiscountLvl() const
	{
		return discountLevel;
	}
	
	void PreferredCustomer_C::Display_Data() const
	{

		// This class will override virtual function Display_Data, 
		//and this version will display the purchase amount to-date and discount level
		//(hint: also display the other classes' data).

		CustomerData_C::Display_Data();

		PersonData_C::Display_Data();

		cout << setprecision(2) << fixed << showpoint <<
			"\tPurchase Amount To Date: $" << Get_PurchaseAmt() << endl;
		cout <<
			"\tDiscount Level (%): " << Get_DiscountLvl() << "%" << endl;

	}

	void PreferredCustomer_C::Purchasing(double spend)
	{
		//double newAmt = 0.0;

		//If purchase amount is > first level, 
		if (purchasesAmount >= FIRST_LEVEL && purchasesAmount < SECOND_LEVEL)
		{
			Set_DiscountLvl(FIVE);					//set discount level
			double newAmt2 = spend * FIVE_PCT_DISC;
			Set_PurchaseAmt(newAmt2);			//add purchase amount, after discount

		}

		//If purchase amount is > second level,
		else if (purchasesAmount >= SECOND_LEVEL && purchasesAmount < THIRD_LEVEL)
		{
			Set_DiscountLvl(SIX);					//set discount level
			double newAmt3 = spend * SIX_PCT_DISC;
			Set_PurchaseAmt(newAmt3);			//add purchase amount, after discount

		}

		//If purchase amount is > third level,
		else if (purchasesAmount >= THIRD_LEVEL && purchasesAmount < FOURTH_LEVEL)
		{
			Set_DiscountLvl(SEVEN);					//set discount level
			double newAmt4 = spend * SEVEN_PCT_DISC;
			Set_PurchaseAmt(newAmt4);			//add purchase amount, after discount

		}

		//If purchase amount is > fourth level,
		else if (purchasesAmount >= FOURTH_LEVEL)
		{
			Set_DiscountLvl(TEN);					//set discount level
			double newAmt5 = spend * TEN_PCT_DISC;
			Set_PurchaseAmt(newAmt5);			//add purchase amount, after discount

		}

		//If purchase amount has not met any discount level, just add it to purchase amount
		else
		{
			Set_PurchaseAmt(spend);
		}
	}



//Deconstructor:
PreferredCustomer_C::~PreferredCustomer_C()
{
}
