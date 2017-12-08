/* Tanya Landreth
	6/10/16
	CH. 10 Homework
	Password Verifier
*/

#define _CRT_SECURE_NO_WARNINGS  //ADD THIS TO THE STDAFX.CPP to compile (before stdafx.h header preprocessor directive)
#include "stdafx.h"
#include <cstring>
#include <iostream>

using namespace std;

//FUNCTION PROTOTYPES:
char *Get_Psswd(char *, const int);				//function prototype to get password
void Verify_Password(char *, int);				//function prototype to validate password

//-------------------------------------------------------------------------------------------------
// <begin main>------------------------------------------------------------------------------------
int main()
{
		const int SIZE = 31;					//size of c-string
		char psswdInput[SIZE];					//c-string to hold password
		char *psswdPointer = psswdInput;		//pointer to c-string
	
		//PASSWORD CRITERIA:
		cout << "--PASSWORD CRITERIA:----------------\n";
		cout << "\t- Greater than 6 characters\n";
		cout << "\t- No more than 30 characters long\n";
		cout << "\t- At least 1 uppercase letter\n";
		cout << "\t- At least 1 lowercase letter\n";
		cout << "\t- At least 1 digit\n" << endl;
		
		psswdPointer = Get_Psswd(psswdPointer, SIZE);								//call function to get password & return it to main

		Verify_Password(psswdPointer, SIZE);										//call function to verify password

	system("pause");
    return 0;
}
// <end main>------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

//FUNCTION: GET PASSWORD ///////////////////////////////////////////////////////////////////////////////////////////
	char *Get_Psswd(char *passwordArray, int SIZE)
	{
		cout << "[ Enter your password ]:";
				
		cin.getline(passwordArray, SIZE);
		cin.ignore();
		cin.clear();
		cout << "\nPassword: " << passwordArray << "\n" << endl;			//data passed into the array was truncated at one point.... 1st value, and last value if over 30 characters..... 
																			//cin.clear / cin.ignore combo seemed to help
		return passwordArray;
	}

//FUNCTION: VERIFY PASSWORD ///////////////////////////////////////////////////////////////////////////////////////////
	void Verify_Password(char *Input, int const size)
	{
		int passwordLength;
		passwordLength = strlen(Input);							//variable for length of the c-string

					//.......................TESTING DATA VISUALLY.........:
					//cout << "Length of password: " << passwordLength << " characters." << endl;
					//cout << "Password in Validate function: " << Input << "\n" << endl;					//why was the first value truncated earlier... sheesh....
					//.....................................................:
		
		int counting = 0, count = 1;							//accumulator for final decision

//[VALIDATE]: PASSWORD LENGTH > 30
		if (passwordLength > size)								//? ? ? ? ? ? ? ? ? ? ? ? ? THIS VALIDATION DOESN'T WORK..... ????????? at least it's not necessary...
		{
			cout << "*** Password is greater than 30 characters.\n";
			counting += count;
		}

//[VALIDATE]: PASSWORD LENGTH < 6
		if (passwordLength < 6)
		{
			cout << "*** Password is less than 6 characters.\n";
			counting += count;
		}

//[VALIDATE]: UPPERCASE CHECK:

		int index1 = 0;
		bool found1 = false;

		for (index1 = 0; index1 < passwordLength; index1++)
		{
			int uppercaseCheck = isupper(Input[index1]);			//beginning marker for UPPERCASE search

									//.......................TESTING DATA VISUALLY.........:
									//cout << "isupper value at element" << index1 << ": " << uppercaseCheck << endl;	//test dialog
									//.....................................................:

			if (uppercaseCheck != 0)								//if UPPERCASE FOUND
				{
					found1 = false;
					break;

				}
			else
				{
					found1 = true;									//IF NOT FOUND
				}
		}
			if (found1 == true)
				{
				cout << "*** Password does not contain an uppercase letter.\n";
				counting += count;
				}


//[VALIDATE]: LOWERCASE CHECK:
			int index2 = 0;
			bool found2 = false;

			for (index2 = 0; index2 < passwordLength; index2++)
			{
				int lowercaseCheck = islower(Input[index2]);				//beginning marker for LOWERCASE search
																	//.......................TESTING DATA VISUALLY.........:
																	//cout << "isupper value at element" << index1 << ": " << uppercaseCheck << endl;	//test dialog
																	//.....................................................:
				if (lowercaseCheck != 0)									//if LOWERCASE FOUND
				{
					found2 = false;
					break;

				}
				else
				{
					found2 = true;											//IF NOT FOUND
				}
			}
			if (found2 == true)
			{
				cout << "*** Password does not contain a lowercase letter.\n";
				counting += count;
			}


//[VALIDATE]: DIGIT CHECK:
			int index3 = 0;
			bool found3 = false;

			for (index3 = 0; index3 < passwordLength; index3++)
			{
				int digitCheck = isdigit(Input[index3]);				//beginning marker for DIGIT search
																	//.......................TESTING DATA VISUALLY.........:
																	//cout << "isupper value at element" << index1 << ": " << uppercaseCheck << endl;	//test dialog
																	//.....................................................:
				if (digitCheck != 0)									//if DIGIT FOUND
				{
					found3 = false;
					break;

				}
				else
				{
					found3 = true;										//IF NOT FOUND
				}
			}
			if (found3 == true)
			{
				cout << "*** Password does not contain at least one digit.\n";
				counting += count;
			}


//________ FINAL DECISION __________:

		if (counting > 0)
		{
			cout << "\nPassword is invalid. Please restart the program and try again.\n" << endl;
		}

		else
		{
			cout << "\nPassword accepted.\n" << endl;
		}
	}