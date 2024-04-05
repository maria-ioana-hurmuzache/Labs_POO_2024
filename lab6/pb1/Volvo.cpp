#include "Volvo.h"
#include "Weather.h"
#include <iostream>
#include <iomanip>

Volvo::Volvo()
{
	fuelCapacity = 60; //litri
	fuelConsumption = 12; //litri consumati la suta de km
	avgSpeed[Weather::SUNNY] = 130;
	avgSpeed[Weather::RAIN] = 80;
	avgSpeed[Weather::SNOW] = 70;
}

float Volvo::GetRaceTime(unsigned int circuitLength, Weather condition)
{
	if ((circuitLength / 100 * fuelConsumption) <= fuelCapacity)
		return circuitLength / avgSpeed[condition];
	else
		return 0;
}

void Volvo::printSpecs()
{
	std::cout << std::fixed << std::setprecision(2) << "Volvo " << this->fuelCapacity << ' ' << this->fuelConsumption;
}