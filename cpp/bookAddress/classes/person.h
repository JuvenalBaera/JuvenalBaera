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
        void setAllData(std::string fn, std::string ln, char g, Date d);
        void setFirstName(std::string fname);
        void setLastName(std::string lname);
        void setGender(char gender);
        void setBirthdate(Date d);
        
        std::string getFirstName();
        std::string getLastName();
        std::string getFullName();
        char getGender();
        Date getBirthdate();
};

#endif