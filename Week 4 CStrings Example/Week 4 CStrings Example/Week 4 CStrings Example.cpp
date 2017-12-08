// Week 4 CStrings Example.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#define _CRT_SECURE_NO_WARNINGS  //ADD THIS TO THE STDAFX.CPP to compile (before stdafx.h header preprocessor directive



#include <cstring>
#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>


using namespace std;

void combineNames(char [], char [], char[]);

int main()
{
	const int SIZE = 50;
	char lastName[SIZE], firstName[SIZE], fullName[SIZE], matchName[SIZE];

	cout << "Enter your FIRST NAME: ";
	cin.getline(firstName, SIZE);

	cout << "Enter your LAST NAME: ";
	cin.getline(lastName, SIZE);

combineNames(firstName, lastName, fullName);

cout << "full name is: " << fullName << endl << endl;

cout << "enter full name: ";
cin.getline(matchName, SIZE);
cout << endl;

if (strcmp(matchName, fullName) == 0)
{
	cout << "  MATCHES  " << endl;
}
else
{
	cout << "  DOES  NOT  MATCH  " << endl;
}




	system("pause");
    return 0;
}

void combineNames(char first[], char last[], char combined[])
{
	strcpy(combined, first);	//copy first in the the combined c-string
	strcat(combined, " ");
	strcat(combined, last);

}

/*

1. Declare three C-strings, each of size 50, named lastName, firstName and fullName. 

Enter your first name and last name into the corresponding C-Strings, 

then in a function combine them into the fullName C-String with a space separating the two names, 

and display the fullName C-String in main.


2. Then declare another C_String of size 50, and enter your full name including your middle initial 
(if you have one). 

Compare the fullName C-String from above to the new C-String, 

and display a message as to whether they match or not.

Then declare a size 10 C-String and enter a decimal number into it (13.659). 

Validate that all characters entered are either numeric or a single period. 

Then in a function convert the C-String to a double, add the double to itself, 
and display the answer (27.318). 

Convert the answer to a string object and display the string object in main 
using a reference variable. 
*/