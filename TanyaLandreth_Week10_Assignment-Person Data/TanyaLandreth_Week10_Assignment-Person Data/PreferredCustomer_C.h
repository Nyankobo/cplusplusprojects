#pragma once
#ifndef PREFERREDCUSTOMER_C_H
#define PREFERREDCUSTOMER_C_H

#include "stdafx.h"
#include "PreferredCustomer_C.h"
#include "CustomerData_C.h"
#include "PersonData_C.h"
#include <iostream>
#include <iomanip>

using namespace std;
class PreferredCustomer_C : public PersonData_C, public CustomerData_C
{
private:
	double purchasesAmount;
	double discountLevel;

public:
//Constructors:
	PreferredCustomer_C();
	PreferredCustomer_C(double, double, int , bool , string , string , int );

//Setters:
	void Set_PurchaseAmt(double);
	void Set_DiscountLvl(double);

	void Purchasing(double);			//member function to purchase/spend $$

//Getters:
	double Get_PurchaseAmt() const;
	double Get_DiscountLvl() const;

	virtual void Display_Data() const;

//Destructor:
	~PreferredCustomer_C();
};

#endif