#include "Contact.h"

Contact::Contact(string name)
{
	this->name = name;
}

string Contact::GetName()
{
	return this->name;
}
