#include <iostream>
#include "Volvo.h"
#include "BMW.h"
#include "Fiat.h"
#include "Seat.h"
#include "RangeRover.h"
#include "Circuit.h"

int main()
{
    Volvo masina;
    masina.printSpecs();
    std::cout << '\n';
    std::cout << '\n';
    Circuit c(5);
    c.SetLength(600);
    c.SetWeather(Weather::SUNNY);
    c.AddCar(new Volvo());
    c.AddCar(new BMW());
    c.AddCar(new Fiat());
    c.AddCar(new Seat());
    c.AddCar(new RangeRover());
    c.Race();
    std::cout << '\n';
    c.ShowFinalRanks();
    std::cout << '\n';
    c.ShowWhoDidNotFinish();
    return 0;

}
