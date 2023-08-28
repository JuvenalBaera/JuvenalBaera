#include "addressbook.h"

unsigned int AddressBook::total_contact = 0;

bool AddressBook::insertContact(Contact c){
    if(myContacts.count(c.getPhoneNumber()) > 0)
        return false;
    myContacts[c.getPhoneNumber()] = c;
    AddressBook::total_contact++;
    return true;
}

std::vector<Contact> AddressBook::getAllContacts(){
    std::vector<Contact> contacts;
    for(auto &pair : this->myContacts){
        contacts.push_back(pair.second);
    }
    return contacts;
}

Contact* AddressBook::searchContactByPhone(std::string phone){
    if(myContacts.count(phone) > 0)
        return &myContacts[phone];
    return NULL;
}

void AddressBook::deleteContact(std::string phone){
    myContacts.erase(phone);
    AddressBook::total_contact--;
}

unsigned int AddressBook::getTotalContact() {
    return AddressBook::total_contact;
}
