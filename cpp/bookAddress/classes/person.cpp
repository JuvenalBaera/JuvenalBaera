#include "person.h"

void Person::setFirstName(std::string fname){this->fname = fname;}
void Person::setLastName(std::string lname){this->lname = lname;}
void Person::setBirthdate(Date d){this->birthdate = d;}

void Person::setGender(char gender){
    switch(gender){
        case 'm': case 'M':
        case 'f': case 'F':
            this->gender = gender;
            break;
    }
}

std::string Person::getFullName(){return this->fname + " " + this->lname;}
char Person::getGender(){return this->gender;}
Date Person::getBirthdate(){return this->birthdate;}
