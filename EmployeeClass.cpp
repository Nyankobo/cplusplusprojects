// TanyaLandreth
//FinalProject-EmployeeClass
//August 1st, 2016

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Employee_C.h"

using namespace std;

void Fill_Vector(vector<Employee_C> &);
void Extract_ID(vector<Employee_C> &, vector<int> &);
bool Find_Employee(vector<int>, int);


int main()
{
	//Declare two vectors:
	vector<Employee_C> employees;		//class obj
	vector<int> idNums;					//ints


		//Enter data:
		cout << "\n~~~~~~~~~~[ ENTER EMPLOYEE DATA: ]~~~~~~~~~~\n";

		Fill_Vector(employees);

		//Extract ID from employees vector & input into idNums vector:
		Extract_ID(employees, idNums);

		char done;

		//Search for ID number:
do {
		cout << "\n~~~~~~~~~~[ FIND EMPLOYEE DATA: ]~~~~~~~~~~\n";
		
		int id;
		cout << "\nEnter Employee I.D. to search: ";
		cin >> id;

		if (Find_Employee(idNums, id))
			{
					int size = employees.size();					
					bool found = false;

					for (int count = 0 ; count < size ; count++)
					{
						int idLocated = employees[count].Get_EmpID();

						if (idLocated == id)
							{
								cout << "<<<  Employee number "<< id << " found: >>>\n";
								cout << "\tEmployee Name: " << employees[count].Get_EmpFullName() << endl;
								cout << "\tEmployee I.D.: " << employees[count].Get_EmpID() << endl;
								cout << "\tEmployee Gender: " << employees[count].Get_EmpGender() << endl;
								cout << setprecision(2) << fixed << showpoint << "\tEmployee Salary: $" << employees[count].Get_EmpSalary() << endl;

								cout << "\n\tTotal of all salaries: " << Employee_C::Get_AllSalary() << endl;

								found = true;
							} 
					}
			}

		else
			{
				cout << ">>> Employee number " << id << " was not found. <<< \n";			

			}

		cout << "\nSearch for another I.D.? (Y or N) ";
		cin >> done;


} while (done == 'y' || done == 'Y');

	system("pause");
    return 0;
}

//3 FUNCTIONS:--------------------------------------------------------------------------------------
void Fill_Vector(vector<Employee_C> &fillVector)
{
	string name;
	int IDNum;
	double salary;
	char gender;

	Employee_C object;

	char oneMore;
	do
	{		
		cout << "\n> Employee Full Name: ";
		getline(cin, name);
		object.Set_EmpFullName(name);

		cout << "> Employee I.D. Number: ";
		cin >> IDNum;
			while ((to_string(IDNum)).size() != 6)
			{
				cout << "\tPlease enter a 6 digit ID number: ";
				cin >> IDNum;				
			}

		object.Set_EmpID(IDNum);

		cout << "> Employee Salary: $";
		cin >> salary;
		object.Set_EmpSalary(salary);

		cout << "> Employee Gender: (M or F): ";
		cin >> gender;
		object.Set_EmpGender(toupper(gender));

		fillVector.push_back(object);		//add object to Employee_C vector

		Employee_C::Set_AllSalary(salary);	//add salary to static variable
		

			cout << "\n\tWould you like to enter data for another employee?  (Y or N) ";
			cin >> oneMore;
			cin.ignore();
			

	} while (oneMore == 'y' || oneMore == 'Y');

}

void Extract_ID(vector<Employee_C> &elems, vector<int> &minedElements)
{
	int size = elems.size();

	for (int count = 0; count < size; count++)
	{
		minedElements.push_back(elems[count].Get_EmpID());
	}
}

bool Find_Employee(vector<int> idList, int num)
{
	vector<int>::iterator iterBegin = idList.begin(), iterEnd = idList.end();

	sort(iterBegin, iterEnd);	//sort list

	if (binary_search(iterBegin, iterEnd, num))
	{
		return true;
	}

	else
		return false;
}