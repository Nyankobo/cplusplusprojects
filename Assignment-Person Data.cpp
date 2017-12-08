// TanyaLandreth
// Wk10_Person Data Assignment
// 7/21/16
//
#include "stdafx.h"
#include "PersonData_C.h"
#include "CustomerData_C.h"
#include "PreferredCustomer_C.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void Display_All_Data(const PersonData_C *);

int main()
{
//CUSTOMER 1:
	PreferredCustomer_C customerOne(500.00, 0, 123456, false, "Willingston", "Agatha", 45456);

	cout << "[Initialized Customer:]" << endl;
	Display_All_Data(&customerOne);

	double p1 = 1000.00;
	cout << "\nAfter new purchase -- amount: $" << p1 << endl;

	customerOne.Purchasing(p1);	

	Display_All_Data(&customerOne);
cout << "--------------------------" << endl;

//CUSTOMER 2:
PreferredCustomer_C customerTwo;

string fn, ln;
double iAmt, disc;
int custNum, zip;
char mailing;

cout << "[Initial Customer:]" << endl;
cout << "Enter Last Name: > ";
getline(cin, ln);
	customerTwo.PersonData_C::Set_Last_Name(ln);

cout << "Enter First Name: > ";
getline(cin, fn);
	customerTwo.PersonData_C::Set_First_Name(fn);

cout << "Enter ZipCode: > ";
cin >> zip;
	customerTwo.PersonData_C::Set_Zip(zip);

cout << "Enter Customer Number: > ";
cin >> custNum;
	customerTwo.CustomerData_C::Set_CustomerNum(custNum);

cout << "On Mailing List; Y = yes, N = no: > ";
cin >> mailing;
	if (mailing == 'Y' || mailing == 'y')
	{
		customerTwo.CustomerData_C::Set_MailingList(true);
	}
	if (mailing == 'N'|| mailing == 'n')
	{
		customerTwo.CustomerData_C::Set_MailingList(false);
	}

cout << "Enter Purchase Amount To-Date: > ";
cin >> iAmt;
	customerTwo.Set_PurchaseAmt(iAmt);

cout << "Enter Discount Level: > ";
cin >> disc;
	customerTwo.Set_DiscountLvl(disc);

	cout << "[Initialized Customer:]" << endl;
	Display_All_Data(&customerTwo);


double p2 = 0.0;
cout << "\nEnter new purchase amount: $";
cin >> p2;

customerTwo.Purchasing(p2);

cout << "\nAfter new purchase: " << endl;

Display_All_Data(&customerTwo);

cout << "--------------------------" << endl;

	system("pause");
    return 0;
}

void Display_All_Data(const PersonData_C *customer)
{
	customer->Display_Data();
}