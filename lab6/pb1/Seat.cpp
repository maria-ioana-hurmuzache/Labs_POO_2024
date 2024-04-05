#include "Seat.h"
#include "Weather.h"
#include <iostream>
Seat::Seat()
{
	fuelCapacity = 75; //litri
	fuelConsumption = 15; //litri consumati la suta de km
	avgSpeed[Weather::SUNNY] = 110;
	avgSpeed[Weather::RAIN] = 60;
	avgSpeed[Weather::SNOW] = 50;
}

float Seat::GetRaceTime(unsigned int circuitLength, Weather condition)
{
	if ((circuitLength / 100 * fuelConsumption) <= fuelCapacity)
		return circuitLength / avgSpeed[condition];
	else
		return 0;
}

void Seat::printSpecs()
{
	std::cout << "Seat " << this->fuelCapacity << ' ' << this->fuelConsumption;
}