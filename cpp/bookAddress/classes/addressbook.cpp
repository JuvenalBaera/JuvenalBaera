#include "addressbook.h"

unsigned int AddressBook::total_contact = 0;

bool AddressBook::insertContact(Contact c){
    if(myContacts.count(c.getPhone()) > 0)
        return false;
    myContacts[c.getPhone()] = c;
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
}

unsigned int AddressBook::getTotalContact() {
    return AddressBook::total_contact;
}
