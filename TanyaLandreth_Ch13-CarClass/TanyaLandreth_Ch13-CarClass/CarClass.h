#pragma once
#ifndef CARCLASS_H
#define CARCLASS_H	
#include <string>
class CarClass
{

private:
	int yearModel;
	string make;
	int speed;

public:
	CarClass(int, string);	//constructor
	~CarClass();		//destructor

	//accessor to get values for yearModel, make, speed
	
	int getYearModel();	
	string getMake();
	int getSpeed();

	void accelerate(int);	//add 5 to speed member variable
	void brake(int);
};

#endif