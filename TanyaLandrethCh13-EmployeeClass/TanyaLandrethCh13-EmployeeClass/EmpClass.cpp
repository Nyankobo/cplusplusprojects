#include "stdafx.h"
#include "EmployeeClass.h"
#include <iostream>

//Default constructor
//using it to initialize the object arrays...
Employee_Class_C::Employee_Class_C()
{
	name = "0";
	idNumber = 0;
	department = "0";
	position = "0";
	SIZE = 100;
}

//setters?
		void Employee_Class_C::Set_Name(string nam)
		{
			name = nam;
		}
		void Employee_Class_C::Set_ID(int id)
		{
			idNumber = id;
		}
		void Employee_Class_C::Set_Dept(string d)
		{
			department = d;
		}
		void Employee_Class_C::Set_Posit(string p)
		{
			position = p;
		}


//constructor to accept name/ID as argument
//assigns them to appropriate member variables
//I have no idea what these are for.
		Employee_Class_C::Employee_Class_C(string n, int id)
		{
			name = n;
			idNumber = id;
		}

		Employee_Class_C::Employee_Class_C(string nm, int ID, string dept, string posit)
		{
			name = nm;
			idNumber = ID;
			department = dept;
			position = posit;

		}
		

//getters?
			string Employee_Class_C::Get_Name()
			{	
				return name;
			}

			int Employee_Class_C::Get_ID()
			{
				return idNumber;
			}
			string Employee_Class_C::Get_Dept()
			{
				return department;

			}
			string Employee_Class_C::Get_Posit()
			{
				return position;
			}

//store data in array
void Employee_Class_C::Enter_Data(Employee_Class_C empArray[], int size)
{
	char continuing;
	string name;
	int idnum;
	string dep;
	string pos;
	int sz = size;
	int count = 0;

	cout << "\n\n";
	cout << "|------[ENTER EMPLOYEE DATA]--------------------|\n";
	cout << "|\n";
	cout << "| Enter data for each employee: > ";
	cout << "|\n";

		do
		{	
				cin.ignore();
				cout << "|\tEnter name: ";
				getline(cin, name);
				empArray[count].Set_Name(name);

				cout << "|\tEnter ID Number: ";
				cin >> idnum;
				empArray[count].Set_ID(idnum);

				cin.ignore();
				cout << "|\tEnter Department name: ";
				getline(cin, dep);
				empArray[count].Set_Dept(dep);

				cout << "|\tEnter Position name: ";
				getline(cin, pos);
				empArray[count].Set_Posit(pos);


				cout << "\n| Do you want to enter data for another employee (Y or N)? ";
				cin >> continuing;

				count++;

		} while (toupper(continuing) == 'Y' && count < sz);

		cout << "\n";
		cout << "|-----------------------------------------------|\n";

}


//display data in array
void Employee_Class_C::Display_Data(Employee_Class_C empArray[], int size)
{
	int sz = size;

	cout << "\n\n";
	cout << "|-----------------------------------------------|\n";
	cout << "| Displaying Employee Data:                     |\n";
	cout << "|-----------------------------------------------|\n\n";
	for (int count = 0; count < sz; count++)
	{				
		if (empArray[count].Get_Name() != "0")
		{
			cout << "|\tName: " << empArray[count].Get_Name() << endl;
			cout << "|\tID Number: " << empArray[count].Get_ID() << endl;
			cout << "|\tDepartment: " << empArray[count].Get_Dept() << endl;
			cout << "|\tPosition: " << empArray[count].Get_Posit() << endl;
			cout << "|-----------------------------------------------|\n";
		}
		}
}

//search data in array and return found/not found
bool Employee_Class_C::Search(Employee_Class_C empArray[], int size, int idLookUp)
{
	int index = 0;
	bool found = false;

	while (index < size && !found)
	{
		if (empArray[index].Get_ID() == idLookUp)
		{
			found = true;		
		}

		index++;
	}

	return found;
}

//Default destructor
Employee_Class_C::~Employee_Class_C()
{
}