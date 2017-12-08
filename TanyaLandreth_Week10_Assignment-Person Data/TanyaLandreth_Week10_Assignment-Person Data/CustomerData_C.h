#pragma once
#ifndef CUSTOMERDATA_C_H
#define CUSTOMERDATA_C_H

#include "stdafx.h"
#include "CustomerData_C.h"
#include "PersonData_C.h"
#include <iostream>
#include <iomanip>

using namespace std;

class CustomerData_C : public PersonData_C
{
private:
	int customerNum;
	bool mailingList;

public:
//Constructors:
	CustomerData_C();
	CustomerData_C(int, bool);

//Mutators:
	void Set_CustomerNum(int);
	void Set_MailingList(bool);

//Accessors:
	int Get_CustomerNum() const;
	string Get_MailingList() const;

	virtual void Display_Data() const;
	
//Destructor:
	~CustomerData_C();
};

#endif