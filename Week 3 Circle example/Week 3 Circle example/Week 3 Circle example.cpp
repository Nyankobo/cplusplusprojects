// Week 3 Circle example.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

double getRadius();			//prototype to get radius from user

double circleDiameter(double);	//prototype to return DIAMETER ((use REFERENCE VARIABLE?))
							//takes RADIUS
double circleCircum(double, double);	//prototype to return circumference back to main ((use POINTERS))
							//takes RAIDUS & PI
double circleArea(double, double);		//prototype to return area back to main
							//takes RADIUS & PI




int main()
{
	double PI = 3.1416;

	double Radius = getRadius();		//get radius from user and return radius to variable

	

		cout << "The RADIUS is " << Radius << endl;

	double Diameter = circleDiameter(Radius);	//returns DIAMETER

		cout << "The DIAMETER is " << Diameter << endl;

	double Circumference = circleCircum(Radius, PI);	//returns CIRCUMFERENCE

		cout << "The CIRCUMFERENCE is " << Circumference << endl;

	double Area = circleArea(Radius, PI);	//returns AREA

		cout << "The AREA is " << Area << endl;

	system("pause");
    return 0;
}

double getRadius()			//definition to get radius from user
{
	double radiusEnter;
	cout << "Enter the radius of the circle: > ";
	getline(cin, radiusEnter);

	return radiusEnter;
}


double circleDiameter(double Radius)	//definition to calculate & return DIAMETER
{
	double Diameter = 2.00 * Radius;

	return Diameter;


}


double circleCircum(double Radius, double pi)			//definition to calculate & return CIRCUMFERENCE
{
	double circumference = 2.00 * pi * Radius;

	return circumference;

}