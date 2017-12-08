#include "stdafx.h"
#include "Employee_C.h"
#include <string>

using namespace std;

 double Employee_C::allSalary = 0.0;

//Constructors:
Employee_C::Employee_C()
{
	string empFullName = " ";
	int empNumber = 0;
	double empSalary = 0.0;
	char empGender = ' ';

}

Employee_C::Employee_C(string name, int number, char s, double salary)
{
	string empFullName = name;
	int empNumber = number;
	double empSalary = salary;
	char empGender = s;
	
}

//Setters:
void Employee_C::Set_EmpFullName(string name)
{
	empFullName = name;
}
void Employee_C::Set_EmpID(int number)
{
	empNumber = number;

}
void Employee_C::Set_EmpGender(char gender)
{
	empGender = gender;

}
void Employee_C::Set_EmpSalary(double salary)
{
	empSalary = salary;
}



//Getters:
string Employee_C::Get_EmpFullName()
{
	return empFullName;
}
int Employee_C::Get_EmpID()
{
	return empNumber;
}
char Employee_C::Get_EmpGender()
{
	return empGender;
}
double Employee_C::Get_EmpSalary()
{
	return empSalary;
}



Employee_C::~Employee_C()
{
}


void Employee_C::Set_AllSalary(double anotherSalary)
{
	allSalary += anotherSalary;
}
double Employee_C::Get_AllSalary()
{
	return allSalary;
}