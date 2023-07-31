#ifndef CONTACT_H_
#define CONTACT_H_

#include <iostream>

class Contact{
    private:
        std::string fname;
        std::string lname;
        std::string phone;
        std::string email;

    public:
        Contact();
        Contact(std::string fnname, std::string lname, std::string phone, std::string email);

        // ############### GETTERS ###############
        std::string getFirstName();
        std::string getLastName();
        std::string getPhone();
        std::string getPhoneFormated();
        std::string getEmail();
        std::string getFullName();


        // ############### SETTERS ###############
        void setFirstName(std::string fname);
        void setLastName(std::string lname);
        void setFullName(std::string fname, std::string lname);
        void setPhone(std::string phone);
        void setEmail(std::string email);
};

#endif