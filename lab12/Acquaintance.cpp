#include "Acquaintance.h"

Acquaintance::Acquaintance(string name, string phone)
{
	this->name = name;
	this->PhoneNumber = phone;
}

string Acquaintance::GetPhoneNumber()
{
	return PhoneNumber;
}
