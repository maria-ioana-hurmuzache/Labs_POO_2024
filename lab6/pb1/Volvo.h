#pragma once
#include "Car.h"

class Volvo : public Car
{
public:
	Volvo();
	float GetRaceTime(unsigned int circuitLength, Weather condition);
	void printSpecs();
};