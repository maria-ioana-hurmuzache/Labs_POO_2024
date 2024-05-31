#pragma once
#include <iostream>
#include "Contact.h"
#include "Friend.h"
#include "Acquaintance.h"
#include "Colleague.h"
#include <list>
using namespace std;

class AdressBook
{

private:
	list<Contact> Contacts;

public:
	AdressBook();

	Contact* NameSearch(string name);

	list<Friend> SearchFriends();

	void Delete(string name);

	void Add(Contact contact);
};
