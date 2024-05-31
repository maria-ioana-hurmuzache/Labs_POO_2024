#include <iostream>
#include "Contact.h"
#include "Friend.h"
#include "Acquaintance.h"
#include "Colleague.h"
#include "AdressBook.h"
using namespace std;

int main()
{

AdressBook addressBook;

// Adding contacts
addressBook.Add(Friend("Alice", "1990-01-01", "123 Wonderland Ave", "123-456-7890"));
addressBook.Add(Acquaintance("Bob", "987-654-3210"));
addressBook.Add(Colleague("Charlie", "555-555-5555", "456 Tech Park", "Tech Corp"));

// Searching for a contact
Contact* contact = addressBook.NameSearch("Alice");
if (contact)
{
    cout << "Contact found: " << contact->GetName() << endl;
}
else
{
    cout << "Contact not found" << endl;
}

// Getting the list of friends
list<Friend> friends = addressBook.SearchFriends();
cout << "Friends:" << endl;
for (auto& friendContact : friends) {
    cout << "- " << friendContact.GetName() << ", Date of Birth: " << friendContact.GetDateOfBirth()<< ", Phone: " << friendContact.GetPhoneNumber() << ", Address: " << friendContact.GetAdress() << endl;
}

// Deleting a contact
addressBook.Delete("Bob");
cout << "Contact 'Bob' has been deleted" << endl;

return 0;
}
