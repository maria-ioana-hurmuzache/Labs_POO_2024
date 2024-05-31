#include "Friend.h"

Friend::Friend(string name, string date, string adress, string phone)
{
	this->name = name;
	dateOfBirth=date;
	this->adress=adress;
	PhoneNumber=phone;
}

string Friend::GetDateOfBirth()
{
	return dateOfBirth;
}

string Friend::GetAdress()
{
	return adress;
}

string Friend::GetPhoneNumber()
{
	return PhoneNumber;
}
