#pragma once
#include "Weather.h"
#include "Car.h"

class Circuit
{
private:
	float length;
	Weather weather;
	//Car* cars[20];
	Car** cars;
	unsigned int nrCars = 0;
public:
	Circuit(unsigned int nrDesiredCars);
	void SetLength(unsigned int length);
	void SetWeather(Weather weather);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};