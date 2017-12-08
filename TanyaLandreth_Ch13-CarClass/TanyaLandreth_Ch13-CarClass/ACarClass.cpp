#include "stdafx.h"
#include "CarClass.h"
#include <string>

using namespace std;


CarClass::CarClass(int year, string carMake) //constructor
{	yearModel = year;
	make = carMake;
	speed = 0;
}

int CarClass::getYearModel()
{
	return yearModel;

}


string CarClass::getMake()
{
	return make;

}


int CarClass::getSpeed()
{
	return speed;

}

void CarClass::accelerate(int speed)
{
	speed += getSpeed() + 5;


}

void CarClass::brake(int speed)
{

	speed += getSpeed() - 5;
}


CarClass::~CarClass()
{
}
