#ifndef CONTACT_H_
#define CONTACT_H_

#include <iostream>

#include "person.h"
#include "date.h"

class Contact{
    private:
        Person person;
        std::string codeArea;
        std::string phone_number;
        std::string country;
        std::string email;
        std::string createdAt;
        std::string lastUpdate;

    public:
        Contact();
        Contact(Person p, std::string code, std::string country, std::string phone, std::string email);

        // ############### GETTERS ###############
        Person getPerson();
        std::string getCodeArea();
        std::string getPhoneNumber();
        std::string getEmail();
        std::string getCountry();
        std::string getCreatedDate();
        std::string getLasUpdate();


        // ############### SETTERS ###############
        void setPerson(Person p);
        void setCodeArea(std::string codeArea);
        void setPhone(std::string phone);
        void setEmail(std::string email);
        void setCountry(std::string country);
        void lastUpdateContact();
        void setAllData(Person p, std::string phone_code, std::string phone, std::string email, std::string country);
};

#endif
