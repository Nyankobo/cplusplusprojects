// TanyaLandreth
// Wk11_Median Tedium Template
// 26 July 2016

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;

//Function Templates:
//User enters numbers, and numbers are stored using function;
template <class T1>
	void Fill_Vector(vector<T1> &vect, T1 numba)
	{
		if (numba < 0)
		{
			string exceptionString = "Please enter a positive number: > ";
			throw exceptionString;
		}

		else
			vect.push_back(numba);
	}

//Sort the vector;
template <class T2>
	void Sort_Vector(vector<T2> &vect)
		{
			sort(vect.begin(), vect.end());
		}

//Find the median;
template <class T3>
	double Find_Median(vector<T3> &vect)
		{
			vector<T3>::iterator iter;	//"pointer" to element in array 

			//1. determine how many elements are in the vector ; save count to variable
			int numElem = vect.size();

			//2. if count is EVEN, locate values & average
			if (numElem % 2 == 0)
			{
				iter = vect.begin() + (vect.size() / 2);	//this value will be HALF of the # of elements in the vector; not the exact subscript

				//at HALFWAY through the vector, use avg of the last value in first half + the first value in the next half

				T3 median = *iter;	//median = value at HALF of the # of elements
				iter--;				//decrement the pointer
				median += *iter;	//add the value at the new pointer location to median
				median /= 2;		//average median

				return median;
			}

			else //if ODD, locate value @ middle
			{
				vector<T3>::iterator iter2;

				iter2 = vect.begin() + (vect.size() / 2);	//this value will be HALF of the # of elements in the vector
				T3 median = *iter2;							//set median to the value in the middle of the vector

				return median;
			}
		}


int main()
{
	//declare vector(s) to hold set of numbers
	vector<double> doubleNums;			

	char yrn;
	double n = 0.0;

	//Enter numbers/Fill Vector:
	cout << "Enter positive numbers:  >> ";

				do {
						cout << "\nNumber: >> ";
						cin >> n;

						try
							{
								Fill_Vector(doubleNums, n);			//fill vector function
							}
						catch (string exceptionString)
							{
								cout << exceptionString;
								cin >> n;
								Fill_Vector(doubleNums, n);
							}

							cout << "\n\tEnter another number?  Y = Yes, N = No > ";
							cin >> yrn;

					} while (yrn == 'Y' || yrn == 'y');

	//Sort Vector:
	Sort_Vector(doubleNums);

	//Display vector:
	vector<double>::iterator it;

		cout << "\nSorted Vector: \t" << endl;
		for (it = doubleNums.begin(); it != doubleNums.end(); it++)
			{
				cout << setprecision(1) << fixed << showpoint
					<< *it << "  ";
			}

	//Display Median:
	cout << "\nThe median is: \t" << Find_Median(doubleNums) << ".\n" << endl;

	system("pause");
    return 0;
}

