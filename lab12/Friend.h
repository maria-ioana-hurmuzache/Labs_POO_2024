#pragma once
#include "Contact.h"
#include <iostream>
#include <string>

using namespace std;

class Friend : public Contact
{

private:
	string dateOfBirth;
	string adress;
	string PhoneNumber;

public:
	Friend(const string& name, const string& date, const string& adress, const string& phone);

	string GetDateOfBirth();

	string GetAdress();

	string GetPhoneNumber();
};
