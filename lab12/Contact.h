#pragma once
#include <iostream>
#include <string>
using namespace std;

class Contact
{
private:
	string name;
public:
	Contact(string name);

	string GetName();
};
