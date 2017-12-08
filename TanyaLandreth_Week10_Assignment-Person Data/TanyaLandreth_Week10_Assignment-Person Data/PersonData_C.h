#pragma once
#ifndef PERSONDATA_C_H
#define PERSONDATA_C_H

#include "stdafx.h"
#include "PersonData_C.h"
#include <iostream>
#include <iomanip>

using namespace std;

class PersonData_C
{
private: 
	string lastName, firstName;
	int zipCode;

public:
//Constructors:
	PersonData_C();
	PersonData_C(string, string, int);

//Setters:
	void Set_Last_Name(string);
	void Set_First_Name(string);
	void Set_Zip(int);

//Getters:
	string Get_Last_Name() const;
	string Get_First_Name() const;
	int Get_Zip() const;

//Virtual function:
	virtual void Display_Data() const;

//Deconstructor:
	~PersonData_C();
};



#endif