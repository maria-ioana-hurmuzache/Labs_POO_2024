#include "BMW.h"
#include "Weather.h"
#include <iostream>
#include <iomanip>

BMW::BMW()
{
	fuelCapacity = 100; //litri
	fuelConsumption = 20; //litri consumati la suta de km
	avgSpeed[Weather::SUNNY] = 180;
	avgSpeed[Weather::RAIN] = 90;
	avgSpeed[Weather::SNOW] = 70;
}

float BMW::GetRaceTime(unsigned int circuitLength, Weather condition)
{
	if ((circuitLength / 100 * fuelConsumption) <= fuelCapacity)
		return circuitLength / avgSpeed[condition];
	else
		return 0;
}

void BMW::printSpecs()
{
	std::cout << std::fixed << std::setprecision(2) << "BMW " << this->fuelCapacity << ' ' << this->fuelConsumption;
}