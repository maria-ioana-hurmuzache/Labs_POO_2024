#pragma once
#include "Car.h"

class Seat : public Car
{
public:
	Seat();
	float GetRaceTime(unsigned int circuitLength, Weather condition);
	void printSpecs();
};