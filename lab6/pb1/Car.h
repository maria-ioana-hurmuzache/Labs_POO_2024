#pragma once
#include "Weather.h"

class Car
{
public:
	float fuelCapacity;
	float fuelConsumption;
	float avgSpeed[3]; //pentru 0-sunny, 1-rain, 2-snow

	//puteam face si un constructor aici
	//Car() : fuelCapacity(40), fuelConsumption(12), avgSpeed{ 120,80,70 } {};

	//functie pur virtuala prin care obligam implementarea acestei functii in orice clasa derivata
	virtual float GetRaceTime(unsigned int circuitLength, Weather condition) =0;
	virtual void printSpecs() =0;
};