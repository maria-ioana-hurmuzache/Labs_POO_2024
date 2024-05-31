#include "Colleague.h"

Colleague::Colleague(string name, string phone, string adress, string company)
{
	this->name = name;
	PhoneNumber = phone;
	Adress = adress;
	Company = company;
}

string Colleague::GetPhoneNumber()
{
	return PhoneNumber;
}

string Colleague::GetAdress()
{
	return Adress;
}

string Colleague::GetCompany()
{
	return Company;
}
