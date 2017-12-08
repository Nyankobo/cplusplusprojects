// Week 3 Pointers Ex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>


	using namespace std;


	int main()

	{

		int total, num1 = 3, num2 = 8;

		int* num1_p;

		int* num2_p;

		// what is int*? what is num1_p?


		num1_p = &num1;

		num2_p = &num2;

		// what does num2_p contain?


		/* What will be printed for each set of statements? */

		cout << "#1" << endl;

		cout << &num1 << endl;

		cout << &num2 << endl;


		cout << "#2" << endl;

		cout << num1 << endl;

		cout << num2 << endl;


		cout << "#3" << endl;

		cout << num1_p << endl;

		cout << num2_p << endl;


		cout << "#4" << endl;

		cout << &num1_p << endl;

		cout << &num2_p << endl;


		cout << "#5" << endl;

		cout << &(*num1_p) << endl;

		cout << &(*num2_p) << endl;


		cout << "#6" << endl;

		cout << *num1_p << endl;

		cout << *num2_p << endl;


		cout << "#7" << endl;

		total = num1 + num2;

		cout << total << endl;


		cout << "#8" << endl;

		total = *num1_p + *num2_p;

		cout << total << endl;



		system("pause");

		return (0);

	}






