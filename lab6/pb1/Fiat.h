#pragma once
#include "Car.h"

class Fiat : public Car
{
public:
	Fiat();
	float GetRaceTime(unsigned int circuitLength, Weather condition);
	void printSpecs();
};