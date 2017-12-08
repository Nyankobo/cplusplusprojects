// TanyaLandreth
//Ch13-Employee_Class_C.cpp
//7/1/16

#include "stdafx.h"
#include "EmployeeClass.h"
#include <string>
#include <iostream>

using namespace std;

void menu();

int main()
{
	Employee_Class_C employee;		//create an object so the constructor runs

	const int SIZE = 100;

	Employee_Class_C employeeList[SIZE];	//create array of objects?????

	char choice;

	do {	
		
	menu();	//display menu

	cout << "\nPlease select from the menu: > ";
	cin >> choice;

		while (toupper(choice) < 'A' || toupper(choice) > 'D')
		{
			cout << "\nPlease enter a valid selection: A, B, C, D > ";
			cin >> choice;
		}

		if (choice == 'A' || choice == 'a')
		{
			employee.Enter_Data(employeeList, SIZE);
		}

		else if (choice == 'B' || choice == 'b')
		{
			employee.Display_Data(employeeList, SIZE);
		}

		else if (choice == 'c' || choice == 'C')
		{
			int value;
			cout << "\n\n";
			cout << "|------------[SEARCH]---------------------------|\n";
			cout << "| Enter ID number to locate: > ";
			cin >> value;

			bool ifFound;
			ifFound = employee.Search(employeeList, SIZE, value);		//call member search function

				if (ifFound)
				{
					int index = 0;
					bool found = false;

					int sz = SIZE;

					while (index < SIZE && !found)
					{
						if (employeeList[index].Get_ID() == value)
						{
							found = true;
							cout << "\n\n";
							cout << "|-----------------------------------------------|\n";
							cout << "|   Employee Found:\n";
							cout << "|\tName: " << employeeList[index].Get_Name() << endl;
							cout << "|\tID: " << employeeList[index].Get_ID() << endl;
							cout << "|\tDepartment: " << employeeList[index].Get_Dept() << endl;
							cout << "|\tPosition: " << employeeList[index].Get_Posit() << endl;
							cout << "|-----------------------------------------------|\n";
						}

						index++;
					}

				}

				else
				{
					cout << "\n\n";
					cout << "|-----------------------------------|\n";
					cout << "|   Employee not found.             |\n";
					cout << "|-----------------------------------|\n";
					cout << "\n";

				}

		}

		else if (choice == 'd' || choice == 'D')
		{
			exit(EXIT_FAILURE);
		}

	} while (!cin.fail());

	system("pause");
    return 0;
}

void menu()
{
	cout << "\n\n";
	cout << "\t|-------------[Menu:]--------------|\n";
	cout << "\t| A : Enter data for an employee.  |\n";
	cout << "\t| B : Display data for an employee.|\n";
	cout << "\t| C : Search for an employee.      |\n";
	cout << "\t| D : End program.                 |\n";
	cout << "\t|----------------------------------|\n\n";
}