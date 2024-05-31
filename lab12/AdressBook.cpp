#include "AdressBook.h"

AdressBook::AdressBook()
{
	Contacts = nullptr;
}

Contact* AdressBook::NameSearch(string name)
{
	for (auto& contact : Contacts)
	{
		if (contact->GetName() == name)
		{
			return *contact;
		}
	}
	return nullptr;
}

list<Friend> AdressBook::SearchFriends()
{
	list<Friend> friends;
	for (auto& contact : Contacts)
	{
		Friend friend = dynamic_cast<Friend>(contact);
		if (friend)
		{
			friends.push_back(*friend);
		}
	}
	return friends;
}

void AdressBook::Delete(string name)
{
	Contacts.remove_if([name](Contact contact)
	{
		bool del = contact->getName() == name;
		if (del)
		{
			delete contact;
		}
		return del;
	});
}

void AdressBook::Add(Contact contact)
{
	Contacts.push_back(contact);
}
