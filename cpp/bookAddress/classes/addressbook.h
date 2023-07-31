#ifndef ADDRESSBOOK_H_
#define ADDRESSBOOK_H_

#include <unordered_map>
#include <vector>
#include "contact.h"

class AddressBook{
    private:
        std::unordered_map<std::string, Contact> myContacts;
        static unsigned int total_contact;

    public:
        bool insertContact(Contact c);
        std::vector<Contact> getAllContacts();
        Contact* searchContactByPhone(std::string phone);
        void deleteContact(std::string phone);
        static unsigned int getTotalContact();
};

#endif
