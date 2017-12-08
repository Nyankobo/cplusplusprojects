// Week 2 practice 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//Use the first row of numbers only, i.e., declare a size 6 integer array and initialize it with the first row of numbers.

//Then use a function to do a binary search instead of a linear search(requires the array to be sorted...use a separate function).

//Display in main whether the account number is valid or not.

//Note: see binary search on pages 460 - 463

/*----------------------------------
Tanya Landreth
5/24/2016
Practice (WEEK 2, 1st exercise)
----------------------------------*/

#include <iostream>
#include <string>

using namespace std;

//_____________FUNCTION PROTOTYPES________________________________________________________
void sortArray(long int[], const int);		//function to sort array; accepts int array & int size
int searchArray(long int[], const int, long);	//function to search array; accepts SORTED** int array & int size
void showArray(long int[], const int);		//function to show sorted array

int main()	//BEGIN MAIN
{





		const int SIZE = 6;			//const int for SIZE of array
		long int integerArray[SIZE] = { 5658845, 4520125, 7895122, 8777541, 8451277, 1302850 };	//array with SIZE elements
		long forValue;				//value to search for
		int results;				//to hold the value found in the search

		sortArray(integerArray, SIZE);	//call function and pass contents of ARRAY and SIZE of array to SORT the array

		do {
		cout << "Enter account number, or enter 0 to quit: ";
		cin >> forValue;


		if (forValue != 0)
		{
			{
				results = searchArray(integerArray, SIZE, forValue);	//call function and pass ARRAY, SIZE, and VALUE to search for
															// return the results of the search
															// if results contain -1, number not found
				if (results == -1)
					cout << "That account number does not exist.\n\n";

				else
				{
					cout << "Account number was found.\t" << forValue << endl;	//display account number if found
				}


				showArray(integerArray, SIZE);			//call function to show all possible account numbers
			}
		}
		} while (forValue != 0);

	system("pause");
    return 0;
} //END MAIN

  //_____________FUNCTIONS________________________________________________________

void sortArray(long int array[], const int size)		//function to sort the array
		{
			bool swap;			//flag
			int temp;			//variable to place temporary values

			do                                                      //do these steps
			{
				swap = false;										//set flag to FALSE
				for (int count = 0; count < (size - 1); count++)	//loop while count is less than the penultimate element, increment count
				{
					if (array[count] > array[count +1])			//if value in COUNT element of array is > COUNT+1 element
					{
						temp = array[count];						//set temp to equal the value of the COUNT element
						array[count] = array[count + 1];			//set COUNT element in ARRAY to equal the COUNT+1 element in ARRAY
						array[count + 1] = temp;					//set COUNT+1 element in ARRAY = temp
						swap = true;								//set flag to TRUE
					}
				}
			} while (swap);											//while flag is TRUE

			} //end SORTARRAY function

int searchArray(long int array[], const int size, long value)		//function to search the array
		{
			//binary search

			int first = 0,						//first array element
				last = size - 1,				//last array element
				middle,							//midpoint of search
				position = -1;					//position of search value
			bool found = false;					//flag

			while (!found && first <= last)
			{
				middle = (first + last) / 2;	//calculate midpoint
				if (array[middle] == value)		//if value found at middle point
				{
					found = true;
					position = middle;
				}
				else if (array[middle] > value)	//if value is in lower half
				{
					last = middle - 1;
				}
				else { first = middle + 1; }	//if value is in upper half
			}
			return position;

			} //end search array function

void showArray(long int array[], const int size)

		{
			cout << "The available account numbers are: \n";
			for (int count = 0; count < size; count++)
			{
				cout << array[count] << endl;
			}
	
		}


