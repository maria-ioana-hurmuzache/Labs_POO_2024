#include "Circuit.h"
#include <iostream>
#include <iomanip>

Circuit::Circuit(unsigned int nrDesiredCars)
{
	cars = new Car * [nrDesiredCars];
	this->length = 100;
	this->weather = (Weather::SUNNY);
}

void Circuit::SetLength(unsigned int length)
{
	this->length = length;
}
void Circuit::SetWeather(Weather weather)
{
	this->weather = weather;
}
void Circuit::AddCar(Car* car)
{
	cars[nrCars++] = car;
}
void Circuit::Race()
{
	unsigned int i;
	for(i=0; i<nrCars; i++)
	{
		cars[i]->printSpecs();
		if (cars[i]->GetRaceTime(length, weather)>0)
			std::cout << ' ' << (int)cars[i]->GetRaceTime(length, weather) << " ore si " << (int)((cars[i]->GetRaceTime(length, weather)-(int)cars[i]->GetRaceTime(length, weather))*60) << " minute\n";
		else
			std::cout << " a ramas fara combustibil\n";
	}
}

void Circuit::ShowFinalRanks()
{
	int i, j;
	Car* temp;
	for (i=1; i<nrCars; i++)
	{
		j = i - 1;
		temp = cars[i];
		while (j >= 0 && (cars[j]->GetRaceTime(length, weather) > temp->GetRaceTime(length, weather) || cars[j]->GetRaceTime(length, weather)==0) && temp->GetRaceTime(length, weather)!=0)
		{
			cars[j + 1] = cars[j];
			j--;
		}
		if (cars[j+1] != temp)
			cars[j + 1] = temp;
	}
	std::cout << "Clasamentul final este:\n";
	this->Race();
}

void Circuit::ShowWhoDidNotFinish()
{
	unsigned int i;
	std::cout << "Nu au terminat cursa:\n";
	for (i = 0; i < nrCars; i++)
	{
		if (cars[i]->GetRaceTime(length, weather)==0)
			cars[i]->printSpecs(), std::cout << " nu a terminat cursa" << '\n';
	}
}