#include "Student.h"
#include <cstring>

bool Student::SetName(const char nume[])
{
	if (strlen(nume) > 40)
		return false;
	strcpy_s(this->Name, nume);
}

char* Student::GetName()
{
	return this->Name;
}

bool Student::SetMathematics(float value)
{
	if (value > 10 || value < 1)
		return false;
	this->Mathematics = value;
}

float Student::GetMathematics()
{
	return this->Mathematics;
}

bool Student::SetEnglish(float value)
{
	if (value > 10 || value < 1)
		return false;
	this->English = value;
}

float Student::GetEnglish()
{
	return this->English;
}

bool Student::SetHistory(float value)
{
	if (value > 10 || value < 1)
		return false;
	this->History = value;
}

float Student::GetHistory()
{
	return this->History;
}

float Student::GetAverage()
{
	return (this->Mathematics + this->English + this->History) / 3;
}