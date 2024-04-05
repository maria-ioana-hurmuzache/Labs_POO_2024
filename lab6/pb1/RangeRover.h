#pragma once
#include "Car.h"
#include "Weather.h"
class RangeRover : public Car
{
public:
	RangeRover();
	float GetRaceTime(unsigned int circuitLength, Weather condition);
	void printSpecs();
};