// TanyaLandreth_Ch13-CarClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CarClass.h"
#include <iostream>



int main()
{
	CarClass Car;

	cout << "Current Speed: ";
	Car.accelerate(50);

	cout << "Current Speed: ";
	Car.accelerate(50);

	cout << "Current Speed: ";
	Car.accelerate(50);

	cout << "Current Speed: ";
	Car.accelerate(50);

	cout << "Current Speed: ";
	Car.accelerate(50);

	system("pause");
    return 0;
}

