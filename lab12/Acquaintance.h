#pragma once
#include <iostream>
#include "Contact.h"
#include <string>
using namespace std;

class Acquaintance : public Contact
{
private:
	string PhoneNumber;

public:
	Acquaintance(string name, string phone);
	string GetPhoneNumber();
};
