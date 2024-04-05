#include "RangeRover.h"
#include <iostream>
#include <iomanip>

RangeRover::RangeRover()
{
	fuelCapacity = 90; //litri
	fuelConsumption = 15; //litri consumati la suta de km
	avgSpeed[Weather::SUNNY] = 130;
	avgSpeed[Weather::RAIN] = 80;
	avgSpeed[Weather::SNOW] = 70;
}

float RangeRover::GetRaceTime(unsigned int circuitLength, Weather condition)
{
	if (((circuitLength / 100) * fuelConsumption) <= fuelCapacity)
		return circuitLength / avgSpeed[condition];
	else
		return 0;
}

void RangeRover::printSpecs()
{
	std::cout << std::fixed << std::setprecision(2) << "RangeRover" << ' ' << this->fuelCapacity << ' ' << this->fuelConsumption;
}