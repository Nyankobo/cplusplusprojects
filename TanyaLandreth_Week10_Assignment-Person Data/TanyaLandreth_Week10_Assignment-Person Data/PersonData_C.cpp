#include "stdafx.h"
#include "PersonData_C.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Constructors:
	PersonData_C::PersonData_C()
	{
		string lastName = "";
		string firstName = "";
		int zipCode = 0;
	}

	PersonData_C::PersonData_C(string l, string f, int z)
	{
		Set_Last_Name(l);
		Set_First_Name(f);
		Set_Zip(z);
	}

//Setters:
	void PersonData_C::Set_Last_Name(string last)
		{
			lastName = last;
		}

	void PersonData_C::Set_First_Name(string first)
		{
			firstName = first;
		}

	void PersonData_C::Set_Zip(int zip)
		{
			zipCode = zip;

		}

//Getters:
	string PersonData_C::Get_Last_Name() const
	{
		return lastName;
	}
	string PersonData_C::Get_First_Name() const
	{
		return firstName;
	}
	int PersonData_C::Get_Zip() const
	{
		return zipCode;
	}

	void PersonData_C::Display_Data() const
	{
		cout << "\tFirst Name: " << Get_First_Name() << endl;
			cout <<"\tLast Name: " << Get_Last_Name() << endl;
			cout <<"\tZipCode: " << setprecision(2) << setfill('0') << setw(5) << Get_Zip() << endl;
	}

//Deconstructor:
	PersonData_C::~PersonData_C()
	{
	}
