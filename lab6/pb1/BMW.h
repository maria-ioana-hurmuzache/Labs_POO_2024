#pragma once
#include "Car.h"

class BMW : public Car
{
public:
	BMW();
	float GetRaceTime(unsigned int circuitLength, Weather condition);
	void printSpecs();
};