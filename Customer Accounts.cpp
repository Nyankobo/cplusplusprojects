// Tanya_Landreth_
//Chapter 11-Customer Accounts
//June 19th, 2016

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

		struct Address_S				//Customer Address Structure
		{
			string streetAdd;
			string city;
			string state;
			long int zip;
		};

		struct Phone_S					//Customer phone #
		{
			int areaCode;
			long int phNumber;
		};

		struct LastPmt_S				//Customer date of last payment
		{
			int mm, dd, yyyy;
		};

		struct CustomerAccount_S		//Customer Account
		{
			string name;
			double acctBal;
			Address_S custAdd;
			Phone_S custPh;
			LastPmt_S custPmt;
		};

enum Choice { QUIT_CHOICE, ENTER_CHOICE, CHANGE_CHOICE, VIEW_CHOICE}; //menu choices
enum CustomerChanges {NAME, ACCTBAL, ADDRESS, PHONE, LASTPMT};


Choice Show_Menu();												//FUNCTION prototype to show menu
void Enter_Data(CustomerAccount_S[],int);		//FUNCTION prototype to take structure array, and enter data into acct
void Change_Data(CustomerAccount_S[], int);						//FUNCTION prototype to take structure array, and change data in it
void View_Data(CustomerAccount_S[], int);						//FUNCTION prototype ot take strcture array, and vew data in it

int main()
{
	int menuSelection;
	do {	

	 menuSelection = Show_Menu();							//call MENU function & return choice
	
		const int SIZE = 10;

		CustomerAccount_S customerInfo[SIZE];					//array of 10 structures
//			
		if (menuSelection == ENTER_CHOICE)					//if menu choice is 1. Enter data
			Enter_Data(customerInfo, SIZE);

		else if (menuSelection == CHANGE_CHOICE)								//if menu choice is 2. Change data in customer array
			Change_Data(customerInfo, SIZE);							//pass structure array into function

		else if (menuSelection == VIEW_CHOICE)								//if menu choice is 3. View data in customer array
			View_Data(customerInfo, SIZE);								//pass structure array into function


	} while (menuSelection < ENTER_CHOICE || menuSelection > QUIT_CHOICE);

	system("pause");
    return 0;
}

//FUNCTION ---------------------------------------------------------------------------------------
//MENU
Choice Show_Menu()
{
	int choice;

	do {
		cout << "Customer Accounts\n";
		cout << "Menu  :  Enter the number for your menu choice.\n";
		cout << "\t1. Enter data for a new customer\n";
		cout << "\t2. Change data for a current customer\n";
		cout << "\t3. View data for a current customer\n";
		cout << "\t0. Quit program" << endl;

		cout << "Enter your choice: > ";
		cin >> choice;
		
		if (choice != QUIT_CHOICE)
		{
			if (choice == ENTER_CHOICE)
			{
				return ENTER_CHOICE;
			}

			else if (choice == CHANGE_CHOICE)
			{
				return CHANGE_CHOICE;
			}

			else if (choice == VIEW_CHOICE)
			{
				return VIEW_CHOICE;
			}
		}

		else //((choice < QUIT_CHOICE) || (choice > VIEW_CHOICE))			//how to validate against special characters...? it freaks out!!
		{
			cout << "Please enter a value: > ";
			cin >> choice;
		}

	} while (choice != QUIT_CHOICE);	
	
}

//FUNCTION ---------------------------------------------------------------------------------------
//Enter data into strucure array:

void Enter_Data(CustomerAccount_S structureArray[], const int SIZE)
{
	cout << "\n\t[You are in the Enter Data Menu]:\n\n";

	for (int index = 0; index < SIZE; )
	{
		structureArray[index].acctBal = 0.0;

		cout << "\nEnter data for a customer: \n(enter Q after NAME to return to menu)\n\n";
		cin.ignore();

//NAME
		cout << "Customer Number 00" << index << ": \n";
		cout << "Name: ";
		getline(cin, structureArray[index].name);

		while (structureArray[index].name.empty())
		{
			cout << "Enter a Name: ";
			getline(cin, structureArray[index].name);
		}

		if (structureArray[index].name == "Q" || structureArray[index].name == "q")
		{
			cout << "\n\n....Return to menu: \n\n";
			main();
		}

//ACCOUNT BALANCE
		cin.clear();
	cout << "Account Balance: > $";
	cin.ignore();
	cin >> structureArray[index].acctBal;
	
do
{
	cout << "Enter Account Balance (a positive amount or $0.00):";
	cin >> structureArray[index].acctBal;
} while (structureArray[index].acctBal < 0);

/*		Attempt to validate against empty entry for numbers. I don't know how to do this.
bool entryFail = false;
entryFail = cin.fail();
if (entryFail == true)
{	
	cin.clear();
	cin.ignore();
	cout << "Enter Account Balance (a positive amount or $0.00):";
	cin >> structureArray[index].acctBal;
} */

//ADDRESS
		cout << "Address: >\n";
		cin.ignore();
		cout << "Street Address: ";
		getline(cin, structureArray[index].custAdd.streetAdd);

	while (structureArray[index].custAdd.streetAdd.empty())
		{
			cout << "Enter a Street Address: ";
			getline(cin, structureArray[index].custAdd.streetAdd);
		}

	cin.clear();

//CITY		
	cout << "City: ";
		cin.ignore();
		getline(cin, structureArray[index].custAdd.city);

	while (structureArray[index].custAdd.city.empty())
		{
			cout << "Enter a City: ";
			getline(cin, structureArray[index].custAdd.city);
		}


	cin.clear();

//STATE
		cout << "State: ";
		cin.ignore();
		getline(cin, structureArray[index].custAdd.state);

	while (structureArray[index].custAdd.state.empty())
		{
			cout << "Enter a State: ";
			getline(cin, structureArray[index].custAdd.state);
		}


	cin.clear();

//ZIP
		cout << "Zip Code: ";
		cin.ignore();
		cin >> structureArray[index].custAdd.zip;

//PHONE #
		cout << "Phone Number: >\n";
		cout << "Area Code: ";
		cin >> structureArray[index].custPh.areaCode;

		cout << "6-Digit Number: ";
		cin >> structureArray[index].custPh.phNumber;
//DATE OF
		cout << "Date of Last Payment: >\n";
		cout << "Month (MM): ";
		cin >> structureArray[index].custPmt.mm;

		cout << "Day (DD): ";
		cin >> structureArray[index].custPmt.dd;

		cout << "Year (YYYY): ";
		cin >> structureArray[index].custPmt.yyyy;

//NEXT CUSTOMER OR QUIT
	char nextEntry;
		cout << "\n\nWould you like to enter data for another customer? Y or N: ";
		cin.ignore();
		cin.get(nextEntry);

		if (nextEntry == 'n' || nextEntry == 'N')
		{
			main();
		}

		else if (nextEntry == 'y' || nextEntry == 'Y')
		{
			index++;
		}

		else  //BEGIN if not N or Y, keep asking
		{			
			do {
				cout << "\n\nWould you like to enter data for another customer? Y or N: ";
				cin.clear();
				cin.ignore();
				cin.get(nextEntry);
			} while (nextEntry != 'Y' || nextEntry != 'y' || nextEntry != 'n' || nextEntry != 'N');
			
		} //END if not N or Y, keep asking

} //END FOR LOOP
	
main();


 } //end function


//FUNCTION ---------------------------------------------------------------------------------------
void Change_Data(CustomerAccount_S structureArray[], const int size)
{
	//enum CustomerChanges {NAME, 1 ACCTBAL, 2 ADDRESS, 3 PHONE, 4 LASTPMT};

	cout << "\t[You are in the Change Data menu.]\n\n";

	string nameOf;
	cin.ignore();
	cout << "Enter the full name of the customer you want to edit (firstname lastname): ";
	getline(cin, nameOf);


for (int index = 0; index < size; index++)
{
	if ((structureArray[index].name).compare(nameOf))
	{
			char done;
			do
			{
				int changeSelection;

				cout << "Found: " << structureArray[index].name << endl;
				cout << "What would you like to edit?\n";
				cout << "1 = Account Balance\n"
					<< "2 = Address\n"
					<< "3 = Phone Number\n"
					<< "4 = Date of last payment\n";
				cin >> changeSelection;

//IF select ACCTBAL field
				if (changeSelection == ACCTBAL)
				{
					cout << "Current Account Balance: > $" << structureArray[index].acctBal << endl;
					cout << "Enter New Account Balance: >";
						cin >> structureArray[index].acctBal;
					cout << "Account Balance Updated to: ";
					cout << structureArray[index].acctBal;

					cout << "\n\nUpdates finished? Y or N";
					cin >> done;

					if (done == 'Y' || done == 'Y')
					{
						break;
					}
					else
					{
						cout << "What would you like to edit?\n\tPress Q to quit.\n";
						cout << "Change Selection: ";
						cin >> changeSelection;

					}


				}

//IF select ADDRESS FIELD
				if (changeSelection == ADDRESS)
				{
					cout << "Current Address: "
						<< structureArray[index].custAdd.streetAdd << ", "
						<< structureArray[index].custAdd.city << ", "
						<< structureArray[index].custAdd.state<< ", "
						<< structureArray[index].custAdd.zip << endl;

					cout << "Enter New Address:\n";
					cout << "Street Address: >";
					cin.ignore();
					getline(cin, structureArray[index].custAdd.streetAdd);
					cout << "City: >";
					cin.ignore();
					getline(cin, structureArray[index].custAdd.city);
					cout << "State: >";
					cin.ignore();
					getline(cin, structureArray[index].custAdd.state);
					cout << "Zip Code: >";
					cin >> structureArray[index].custAdd.zip;

					cout << "\n\nUpdated Address: \n";
					cout << structureArray[index].custAdd.streetAdd << ", "
						<< structureArray[index].custAdd.city << ", "
						<< structureArray[index].custAdd.state << ", "
						<< structureArray[index].custAdd.zip << endl;

					cout << "\n\nUpdates finished? Y or N";
					cin >> done;

					if (done == 'Y' || done == 'Y')
					{
						break;
					}

					else
					{
						cout << "What would you like to edit?\n\tPress Q to quit.";
						cin >> changeSelection;

					}
				}


//IF select PHONE field
				if (changeSelection == PHONE)
				{
					cout << "Current Phone Number: "
						<< "(" << structureArray[index].custPh.areaCode << ")"
						<< " " << structureArray[index].custPh.phNumber << endl;

					cout << "Enter new phone number: ";
					cout << "Area Code: ";
					cin >> structureArray[index].custPh.areaCode;
					cout << "Six Digit Number: ";
					cin >> structureArray[index].custPh.phNumber;

					cout << "\nUpdated phone number:\n";
					cout << "(" << structureArray[index].custPh.areaCode << ")"
						<< " " << structureArray[index].custPh.phNumber << endl;


					cout << "\n\nUpdates finished? Y or N";
					cin >> done;

					if (done == 'Y' || done == 'Y')
					{
						break;
					}

					else
					{
						cout << "What would you like to edit?\n\tPress Q to quit.";
						cin >> changeSelection;

					}
				}


//IF select LASTPMT field
				if (changeSelection == LASTPMT)
				{
					cout << "Date of Last Payment: "
						<< structureArray[index].custPmt.mm << "/"
						<< structureArray[index].custPmt.dd << "/"
						<< structureArray[index].custPmt.yyyy << endl;

					cout << "Enter new date:\n";
					cout << "Month (MM): ";
					cin >> structureArray[index].custPmt.mm;
					cout << "Day (DD): ";
					cin >> structureArray[index].custPmt.dd;
					cout << "Year (YYYY): ";
					cin >> structureArray[index].custPmt.yyyy;

					cout << "\nNew Date: " 
						<< structureArray[index].custPmt.mm << "/"
						<< structureArray[index].custPmt.dd << "/"
						<< structureArray[index].custPmt.yyyy << endl;

					cout << "\n\nUpdates finished? Y or N";
					cin >> done;

					if (done == 'Y' || done == 'Y')
					{
						break;
					}

					else
					{
						cout << "What would you like to edit?\n\tPress Q to quit.";
						cin >> changeSelection;

					}
				}

		} while (done == 'Y' || done != 'y');	//end the "update" process while done != quit
												//doesn't work


	if (done != 'y' || done != 'y')
		{
			main();
		}

} //end IF "comparison"

	else 
	{ 
	cin.ignore();
	cout << "Not found. Try again: ";
	getline(cin, nameOf);
		
	}

} //end FOR loop


} //end function



	//FUNCTION ---------------------------------------------------------------------------------------
	//View data in strucure array:
	void View_Data(CustomerAccount_S structureArray[], const int size)

	{
		cout << "[You are in the View Data menu.]\n\n";

		for (int index = 0; index < size; index++)
		{
			cout << "\n---- Customer Number 00" << index + 1 << ": ----------\n";
			cout << "Name: " << structureArray[index].name << endl;
			cout << "Account Balance: > $" << structureArray[index].acctBal << endl;
			cout << "Address: "
				<< structureArray[index].custAdd.streetAdd << ", "
				<< structureArray[index].custAdd.city << ", "
				<< structureArray[index].custAdd.state << ", "
				<< structureArray[index].custAdd.zip << endl;

			cout << "Phone Number: "
				<< "(" << structureArray[index].custPh.areaCode << ")"
				<< " " << structureArray[index].custPh.phNumber << endl;

			cout << "Date of Last Payment: "
				<< structureArray[index].custPmt.mm << "/"
				<< structureArray[index].custPmt.dd << "/"
				<< structureArray[index].custPmt.yyyy << endl;
			cout << "----------------------------------------------------\n" << endl;

		}
	}

	


