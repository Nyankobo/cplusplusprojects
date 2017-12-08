#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "Employee_C.h"

using namespace std;

class Employee_C
{
private:
	string empFullName;				//Employee full name
	int empNumber;					//Employee ID number (6 digit int)
	double empSalary;				//Employee salary
	char empGender;					//Employee gender
	static double allSalary;		//static variable to hold all salaries total


public:
	//Constructors:
	Employee_C();
	Employee_C(string, int, char, double);

	//Setters:
	void Set_EmpFullName(string);
	void Set_EmpID(int);
	void Set_EmpGender(char);
	void Set_EmpSalary(double);

	static void Set_AllSalary(double);
	static double Get_AllSalary();

	//Getters:
	string Get_EmpFullName();
	int Get_EmpID();
	char Get_EmpGender();
	double Get_EmpSalary();
	
	//Destructor:
	~Employee_C();
};

