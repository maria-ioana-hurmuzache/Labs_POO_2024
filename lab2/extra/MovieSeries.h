#pragma once
#include "Movie.h"
#include "GlobalFunctions.h"

class MovieSeries 
{
private:
	int count;
	Movie* series[16];
public:
	void init();
	bool add(Movie* m);
	void sort();
	void print();
};