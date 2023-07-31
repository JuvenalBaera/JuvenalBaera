#include <iostream>
#include "contact.h"

Contact::Contact(){}
Contact::Contact(std::string fnname, std::string lname, std::string phone, std::string email){
    this->fname = fname;
    this->lname = lname;
    this->phone = phone;
    this->email = email;
}

// ############### GETTERS ###############
std::string Contact::getFirstName(){return this->fname;}
std::string Contact::getLastName(){return this->lname;}
std::string Contact::getPhone(){return this->phone;}
std::string Contact::getEmail(){return this->email;}
std::string Contact::getFullName(){return this->fname + " " + this->lname;}
std::string Contact::getPhoneFormated(){
    std::string aux = this->phone;
    aux.insert(3, "-");
    aux.insert(7, "-");
    return aux;
}


// ############### SETTERS ###############
void Contact::setFirstName(std::string fname){this->fname = fname;}
void Contact::setPhone(std::string phone){this->phone = phone;}
void Contact::setEmail(std::string email){this->email = email;}
void Contact::setLastName(std::string lname){this->lname = lname;}
void Contact::setFullName(std::string fname, std::string lname){
    this->setFirstName(fname);
    this->setLastName(lname);
}

