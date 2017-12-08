#pragma once
#ifndef EmployeeClass_H
#define EmployeeClass_H
#include <string>

using namespace std;

class Employee_Class_C
{
//member variables
private:
	string name;
	int idNumber;
	string department;
	string position;
	int SIZE;

public:
	Employee_Class_C();	//default constructor
	~Employee_Class_C();	//destructor

//constructor to accept params & assigns them to appropriate member variables
	Employee_Class_C(string, int);	
	Employee_Class_C(string , int , string, string );

//member functions, besides constructors

	//getters
	string Get_Name();
	int Get_ID();
	string Get_Dept();
	string Get_Posit();
	int Get_Size();

	//setters?
	void Enter_Data(Employee_Class_C[], int);
	void Set_Name(string);
	void Set_ID(int);
	void Set_Dept(string);
	void Set_Posit(string);

	void Display_Data(Employee_Class_C[], int);

	bool Search(Employee_Class_C[], int, int);


};

#endif // !Employee_Class_C_H