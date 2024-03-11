#include "Movie.h"
#include <cstring>
//#include <ctime>

//struct tm newtime;
//time_t now = time(0);
//localtime_s(&newtime, &now);

bool Movie::set_name(const char name[])
{
	if (strlen(name) > 256)
		return false;
	strcpy_s(this->name, name);
	return true;
}

const char* Movie::get_name()
{
	return this->name;
}

bool Movie::set_score(double score)
{
	if (score > 10 || score < 1)
		return false;
	this->score = score;
	return true;
}

double Movie::get_score()
{
	return this->score;
}

bool Movie::set_year(int year)
{
	if (year<1841 || year>(2024/*1900 + newtime.tm_year*/)) //nu exista filme mai vechi de 1841
		return false;
	this->year = year;
	return true;
}

int Movie::get_year()
{
	return this->year;
}

bool Movie::set_length(int length)
{
	if (length < 0 || length>5100) //cel mai lung film dureaza 85 ore
		return false;
	this->length = length;
	return true;
}

int Movie::get_length()
{
	return this->length;
}

int Movie::get_passed_years()
{
	return 2024-this->year /*newtime.tm_year*/;
}