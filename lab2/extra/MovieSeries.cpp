#include "MovieSeries.h"
#include "Movie.h"
#include "GlobalFunctions.h"
#include <iostream>

using namespace std;

void MovieSeries::init()
{
	this->count = 0;
}

bool MovieSeries::add(Movie* m)
{
	if (this->count == 16)
		return false;
	this->series[this->count++] = m;
	return true;
}

void MovieSeries::sort()
{
	for (int i=0; i+1<this->count; i++)
		for (int j=i+1; j<this->count; j++)
			if (this->series[i]->get_passed_years() > this->series[j]->get_passed_years())
			{
				Movie* a = this->series[i];
				this->series[i] = this->series[j];
				this->series[j] = a;
			}
}

void MovieSeries::print()
{
	for (int i = 0; i < this->count; i++)
	{
		cout << this->series[i]->get_name() << ' ';
		cout << this->series[i]->get_score() << ' ';
		cout << this->series[i]->get_year() << ' ';
		cout << this->series[i]->get_length() << ' ';
		cout << this->series[i]->get_passed_years() << '\n';
	}
}