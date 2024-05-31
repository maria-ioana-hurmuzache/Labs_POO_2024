#pragma once
#include <iostream>
#include "Contact.h"
#include <string>
using namespace std;

class Colleague : public Contact
{
private:
	string PhoneNumber;
	string Company;
	string Adress;

public:
	Colleague(string name, string phone, string adress, string company);

	string GetPhoneNumber();

	string GetAdress();

	string GetCompany();
};