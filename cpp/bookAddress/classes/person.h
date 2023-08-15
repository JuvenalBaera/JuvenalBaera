#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include "date.h"

class Person{
    private:
        std::string fname;
        std::string lname;
        char gender;
        Date birthdate;
    public:
        void setFirstName(std::string fname);
        void setLastName(std::string lname);
        void setGender(char gender);
        void setBirthdate(Date d);

        std::string getFullName();
        char getGender();
        Date getBirthdate();
};

#endif