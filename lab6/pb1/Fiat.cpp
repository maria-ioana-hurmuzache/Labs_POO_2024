#include "Fiat.h"
#include "Weather.h"
#include <iostream>
#include <iomanip>

Fiat::Fiat()
{
	fuelCapacity = 70; //litri
	fuelConsumption = 10; //litri consumati la suta de km
	avgSpeed[Weather::SUNNY] = 120;
	avgSpeed[Weather::RAIN] = 60;
	avgSpeed[Weather::SNOW] = 60;
}

float Fiat::GetRaceTime(unsigned int circuitLength, Weather condition)
{
	if ((circuitLength / 100 * fuelConsumption) <= fuelCapacity)
		return circuitLength / avgSpeed[condition];
	else
		return 0;
}

void Fiat::printSpecs()
{
	std::cout << std::fixed << std::setprecision(2) << "Fiat " << this->fuelCapacity << ' ' << this->fuelConsumption;
}