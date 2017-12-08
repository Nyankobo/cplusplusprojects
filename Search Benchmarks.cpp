// TanyaLandreth_Chapter 8-Search Benchmarks.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
/*----------------------------------
Tanya Landreth
5/26/16
Chapter 8-Search Benchmarks
----------------------------------*/

#include <iostream>

using namespace std;

//================================ function prototypes ======= //
int Linear_Search(int[], int, int);		//LINEAR SEARCH FUNCTION
void Display_Array(int[], int);			//DISPLAY ARRAY
void Binary_Sort(int[], int);			//SORT to prep for BINARY SEARCH
int Binary_Search(int[], int, int);		//BINARY SEARCH FUNCTION
//============================================================ //


int main() 
{
	
	const int SIZE = 20;			//const int for SIZE of array
	int arrayOfTwenty[SIZE] = { 101, 89, 305, 6, 17, 56, 3, 44, 689, 450, 
								21, 67, 43, 33, 617, 68, 708, 65, 677, 200 };	//array with SIZE elements
	int getValue;					//value to search for
	int linearResults;				//to hold the value if found in linear search
	int binaryResults;				//to hold the value if found in binary search
									//...could have maybe used the same variable for these...

//###### instructions : ######
//Asks the user for a single integer value which will be used in two functions. 

		cout << "-->> Enter a value (0 - 1000) to search for: ";
		cin >> getValue;
		cout << endl;

		//###### instructions : ######
		//Validate that the integers which are input by the user are greater than zero and less then 1000.
		while (getValue < 0 || getValue > 1000)
		{
			cout << "* Please enter a value from 0 to 1000: ";	
			cin >> getValue;
			cout << endl;
		} 


			//###### instructions : ######
			//call Linear Search function and pass contents of ARRAY, SIZE, and SEARCH VALUE
			linearResults = Linear_Search(arrayOfTwenty, SIZE, getValue);

			//###### instructions : ######
			//display results of linear search:
			if (linearResults == -1)
			{
				cout << "\n....Linear search completed....:\n x x Value was not found.\n\n\n" << endl;		//(if not found)
			}
			else {

				cout << "\n....Linear search completed....:\no o The number " << getValue << " was found in array position " << (linearResults + 1) << "\n\n" << endl; //(if found and where)
				cout << endl;
			}

			//###### instructions : ######		
			//The program should then call a second function which uses the binary search algorithm(you must write the algorithm).to locate the same value.

				//###### instructions : ######
				//Also display the array immediately before the Binary search.
			Display_Array(arrayOfTwenty, SIZE);
			cout << endl;

			//sort array for binary sort
			Binary_Sort(arrayOfTwenty, SIZE);

			//displaying array after sort... curious if it works
			cout << "\nAfter sorting... ";
			Display_Array(arrayOfTwenty, SIZE);
			cout << endl;

			//SEARCH ARRAY :
			binaryResults = Binary_Search(arrayOfTwenty, SIZE, getValue);

			//display results
			if (binaryResults == -1)
			{
				cout << "\n....Binary search completed....:\n x x Value was not found.\n\n\n" << endl;		//(if not found)
			}
			else {

				cout << "\n....Binary search completed....\no o The number " << getValue << " was found in array position " << (binaryResults + 1) << "\n\n" << endl; //(if found and where)
				cout << endl;
			}


		system("pause");
    return 0;
}

//============== FUNCTION DEFINITIONS =====================================//

/*fffffffffffffffff[[LINEAR SEARCH FUNCION]] fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
//###### instructions : ######
The program should call the first function which uses the linear search
algorithm (you must write the algorithm) to locate the integer entered by the user.*/

int Linear_Search(int incomingArray[], int sizeOfArray, int searchForValue)
{
	cout << "\t.............................\n";
	cout << "\t....Linear search running....\n";
	cout << "\t.............................\n\n";

	int count = 0,				//counter & search
		position = -1;			//record position of value if found, -1 otherwise [return value]
	bool ifFound = false;		//flag if value found
	int clockCount = 0;			//counter for how many time search iterates
	
	while (count < sizeOfArray && !ifFound) //WHILE count is < number of elements in array and flag isn't raised
	{
		clockCount++;		//counter for number of comparisons
		
			if (incomingArray[count] == searchForValue)		//if the value is found
			{

				ifFound = true;		//flag raised
				position = count;	//record the position of the value found

			}
			count++;				//increment counter & searched element
		
		//The function should keep a count of the number of comparisons it makes until the value is found.
	}

	cout << "\t[The Linear Search made " << clockCount << " comparisons.]\n";		//shows how many comparisons the search made

	return position;			//return position of found value, or -1 if not found
}

//fffffffffffffffff[[DISPLAY ARRAY]] fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
void Display_Array(int theArray[], int sizeOfArray)
{
	cout << "The values in the array are: ";

	for (int count = 0; count < sizeOfArray; count++)
	{
		cout << theArray[count] << " ";
	}
	cout << endl;

}
//fffffffffffffffff[[SORT ARRAY, for BINARY SEARCH]] fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
void Binary_Sort(int arrayToBeSorted[], int sizeOfArray)		//function to sort the array, prior to binary search
															//copied from book; steps are a hard to follow!
{
	cout << "\t.............................\n";
	cout << "\t....Array being sorted.......\n";
	cout << "\t.............................\n\n";

			bool swap;			//flag
			int temp;			//variable to place temporary values

			do                 //do these steps
			{
				swap = false;															//set flag to FALSE
				for (int count = 0; count < (sizeOfArray - 1); count++)					//loop while count is < the penultimate element, then increment count
				{
					if (arrayToBeSorted[count] > arrayToBeSorted[count + 1])			//if value in COUNT element of array is > COUNT+1 element
					{
						temp = arrayToBeSorted[count];									//set temp = value of the COUNT element
						arrayToBeSorted[count] = arrayToBeSorted[count + 1];			//set COUNT element in ARRAY = COUNT+1 element in ARRAY
						arrayToBeSorted[count + 1] = temp;								//set COUNT+1 element in ARRAY = temp
						swap = true;													//set flag to TRUE
					}
				}
			} while (swap);		//while flag is TRUE

}

//fffffffffffffffff[[BINARY SEARCH]] fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
//###### instructions : ######		
/*The program should then call a second function which uses the 
binary search algoithm (you must write the algorithm). to locate the same value.*/
int Binary_Search(int incomingArray[], int sizeOfArray, int searchForValue)	//function to perform the binary search
{
	cout << "\t................................\n";
	cout << "\t....Binary Search running.......\n";
	cout << "\t................................\n\n";

	int first = 0,					//first array element
		last = sizeOfArray - 1,		//last array element
		middle,						//midpoint of search
		position = -1;				//position of search value
	bool found = false;				//flag
	int clockCounter = 0;			//count number of comparisons

	while (!found && first <= last)
	{
		
		middle = (first + last) / 2;						//calculate midpoint
		if (incomingArray[middle] == searchForValue)		//if value found at middle point
		{
			found = true;
			position = middle;
			clockCounter++;									//count as 1 comparison [done after this]
		}
		else if (incomingArray[middle] > searchForValue)	//if value is in lower half
		{
			last = middle - 1;
			clockCounter++;									//count as 1 comparison, per iteration
		}
		else 
		{ 
			first = middle + 1; 							//if value is in upper half
			clockCounter++;									//count as 1 comparison, per iteration
		}	
		
		
	}

	//display number of comparisons made by Binary Search
	cout << "\n\t[The Binary Search made " << clockCounter << " comparisons.]\n";
	cout << endl;

	return position;
	
}































/*PLAN_________________________________________________________________________________________________
(much more organized than last time)

[DONE] 1. Write a program which declares an array of 20 integers (see array values below)
arrayOfTwenty[20] = {101, 89, 305, 6, 17, 56, 3, 44, 689, 450, 21, 67, 43, 33, 617, 68, 708, 65, 677, 200};

[DONE] 2. Asks the user for a single integer value which will be used in two functions.
int getValue;
(validate that the integers which are input by the user are greater than zero and less then 1000).
if (getValue < 0 }|| getValue > 1000)
error message and retry

[DONE] 3. The program should call the first function which uses the linear search algorithm (you must write the algorithm) to locate the integer entered by the user.
create linearSearch function prototype (takes array, and size arguments)
create linearSearch function (pg 459)
call linearSearch function to locate value	-	 no sort required

[DONE] 4. The function should keep a count of the number of comparisons it makes until the value is found.
keep a counter for the number of times the comparison loop iterates

[DONE] 5. The program should then call a second function which uses the binary search algoithm (you must write the algorithm). to locate the same value.
SORT ARRAY:
create binarySort function prototype (takes array, size)
create binarySorty function
call binarySort

[DONE] SEARCH ARRAY:
create binarySearch function prototype (takes array, and size arguments)
create binarySearch (pg 460)
call binarySearch

[DONE] 6. Also display the array immediately before the Binary search.
loop COUT to show array BEFORE SORTING

[DONE] 7. It should also keep count of the number of comparisons.
keep a counter for the number of times the comparison loop iterates

[DONE] 8. Display the number of comparisons for the two searches in main <<---- displayed in MAIN via function :D
[DONE]	8a.  as-well-as the "position in the array" in which the entered number was found
IF FOUND;
cout linearSearch Counter
cout element location

IF FOUND;
cout binarySearch Counter
cout element location

[DONE] 9. If the integer entered was not found, display a message to the user in lieu of the other two messages.
ELSE;
cout NOT FOUND MESSAGE

10. Provide three screen prints, having the user enter:
6; 100; then 200*/