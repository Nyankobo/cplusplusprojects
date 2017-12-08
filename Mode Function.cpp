// Tanya Landreth Ch 9 Mode Function.cpp : Defines the entry point for the console application.

/*Tanya Landreth
06-04-16
Ch 9. Mode Function*/

/*Function 1 Intent:  Get values for the array.

Function 2 Intent: Compare each single element value in the array of ints to each of the other
element values, to see how many times the same element value appears in the array. While loops
are used to  compare and accumulate the number of times an element value appears. The counts
are then input into a parallel array.

Once the while loops are completed, the array of counted totals is searched for the highest
value. The highest value in the counted total array would correspond to the value in the
array of ints, and would be the mode value.

The 2nd function would return the element in the array of ints that corresponds to the mode,
and return the elementin the counts array that corresponds to the number of times that number
exists.

If no mode is found, return -1 and display not found message.

*/

#include "stdafx.h"
#include <iostream>
using namespace std;

//_________________________________________________________________________________________________________________________
void fillArray(int [], const int);		//prototype function to fill array
int *findMode(int [], const int);		//prototype function to find mode and return it and how many occurences - return value is a pointer ***
//_________________________________________________________________________________________________________________________


int main()
{
//-------------------------------------------------------------------------------------------------------------------------
	const int SIZE = 20;				//size of array
	int arrayOfIntegers[SIZE];			//array of 20 int
//-------------------------------------------------------------------------------------------------------------------------

	fillArray(arrayOfIntegers, SIZE);				//FILL ARRAY

	int *mode = nullptr;							//TO HOLD the MODE 
													//(mode is a pointer to an int)
	
	mode = findMode(arrayOfIntegers, SIZE);			//LOCATE MODE, RETURN IT				-> USE DIFFERENT FUNCTION TO RETURN HOW MANY, NOT SURE HOW TO RETURN MUTLIPLE VALUES??
														//findMode takes the array, and size
//-------------------------------------------------------------------------------------------------------------------------

	if (*mode == -1)										//if value of returned pointer mode is = -1
			{
				cout << "\n\nNo mode was found. Return value: " << *mode << "\n" << endl;		//*mode displays THE VALUE
			}

															//otherwise:
	else
			{
				cout << "\n\nThe mode is " << *mode << "\n" << endl;							//*mode displays THE VALUE

			}
	
	system("pause");
	return 0;
}
// ==============================================================================================================================
//FUNCTIONS ==================================================================
// ==============================================================================================================================
void fillArray(int arrayToFill[], int size)		//function to fill array
{
	cout << "Enter 20 integers -  0 or greater and less than 1000: \n";

	for (int count = 0; count < size; count++)
	{
		cout << (count + 1) << ": ";
		cin >> *(arrayToFill + count);

		if (arrayToFill[count] < 0 || arrayToFill[count] > 1000)
		{
			cout << "Please enter a number from 0 to 999: ";
			cout << "\n" << (count + 1) << ": ";
			cin >> *(arrayToFill + count);
		}
	}
}
// ==============================================================================================================================
//
//Note:
//I had trouble designing a function that could figure out the mode in an array.  Maybe I over complicated it?
// --> I think if I could figure out this part, the rest of the function might actually return mode... <------
//
//

int *findMode(int arrayToSearch[], int size)		//function to find mode and return value, uses int array, and const int size
{
//-------------------------------------------------------------------------------------------------------------------------
	int index = 0,									//initialize counters & flags
		next = index + 1,
		total = 0;

	bool found = false;
//-------------------------------------------------------------------------------------------------------------------------

	int *counterArray = nullptr;
	counterArray = new int[size];										//prepare an array of size size
	
	for (index; index < size && !found; index++)						//for index < size & flag true, loop the contents, then increment index
	{																//looping while index < 20

		for (next; next < size && !found; next++)						//for next < size & flag true, loop the contents, then increment next
		{																//looping while next < 20

			if (*(arrayToSearch + index) == *(arrayToSearch + next))	//if array element in index = element in next
			{
				int addOne = 1;
				found = true;											//flag TRUE
				total += addOne;										//accumulate total

//				cout << "Total: " << total << endl;					//(test to show what's being created...)
			}


			else { found = false; }										//otherwise flag FALSE

			*(counterArray + index) = total;							//add accumulated total to counterArray @ index element
		}		//why does this not accumulate....

//		cout << "View contents of counterArray: " << endl;			//(test to show what's being created...)
//		for (index; index < size; index++)
//		{			cout << "\tcounterArray: " << *(counterArray + index) << endl;
//		}
	}
					


//use counterArray data: find highest value in counterArray, return the corresponding element in arrayToSearch
//-------------------------------------------------------------------------------------------------------------------------
int counting, highest;											//to hold highest value in the counted array
highest = *(counterArray + 0);									//initialize highest starting with first element of counted array
//-------------------------------------------------------------------------------------------------------------------------

		for (counting = 1; counting < size; counting++)			//FIND HIGHEST VALUE [pg 401]
			{
				if ( *(counterArray + counting) > highest)
					
				highest = *(counterArray + counting);				//HIGHEST is the largest number of times mode exists
																	//counting = the corresponding element in arrayToSearch that shows the mode
																	//this would pick only 1 mode, if there were more than one...
			}


		if (highest == 1)											//if highest = 1 (aka nothing appears more than once)
				{
					int position = -1;
					return &position;								//return location of position (contents of which are -1) if no mode found
				}

		else														//otherwise return data from highest:
				{
					return *(&arrayToSearch + counting);			//return pointer to array element (contents of which are the mode)

					cout << "The mode was found " << highest
						<< "times.\n" << endl;						//show how many times the mode was found
				}
																	//can't get the search for the mode to work, so I can't see if the return value would work...
		

		delete[] counterArray;

}
// ==============================================================================================================================

/*INSTRUCTIONS:
xxxxxx The program will declare an array of 20 integers in main.

xxxxxx This program will have two functions:
xxxxxx -the first function will have the user fill the integer array with 20 values (see data below). Validate that all 20 values are zero or greater, and less than 1000.

x?X?X?X?X?X -the second function should determine the mode of the array. That is, it should determine which value in the array occurs most often. 
The mode is the value the function should return. 

x?X?X?X?X?X If the array has no mode (none of the values occurs more than once), the function should return -1.

x?X?X?X?X?X  This function should return to main the mode or -1 using a reference variable   <---------------------
x?X?X?X?X?X  and return to main the number of occurrences of the mode using a pointer.  <==========================

x?X?X?X?X?X  The mode (or -1), along with the appropriate message, 

and the number of occurrences, should both be displayed in main.

Use pointer notation for the array in both functions;   <==========================
also note that the array may not be sorted.

Provide two screen prints:
1) use values: 3, 0, 123, 89, 6, 0, 3, 521, 4, 123, 678, 5, 0, 3, 21, 902, 3, 123, 6, 999
2) use values: 3, 0, 123, 89, 6, 7, 32, 521, 4, 129, 678, 5, 10, 73, 21, 902, 303, 153, 60, 999


*/

