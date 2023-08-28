#include <iostream>
#include "contact.h"

Contact::Contact(){}
Contact::Contact(Person p, std::string code, std::string country, std::string phone, std::string email){
    this->person = p;
    this->phone_number = phone;
    this->email = email;
    this->createdAt = Date::getAtualDate() + " - " +  Date::getAtualTime();
    this->lastUpdate = Date::getAtualDate() + " - " + Date::getAtualTime();
}

// ############### GETTERS ###############
Person Contact::getPerson(){return this->person;}
std::string Contact::getCodeArea(){return this->codeArea;}
std::string Contact::getPhoneNumber(){return this->codeArea + " " + this->phone_number;}
std::string Contact::getEmail(){return this->email;}
std::string Contact::getCountry(){return this->country;}
std::string Contact::getCreatedDate(){return this->createdAt;}
std::string Contact::getLasUpdate(){return this->lastUpdate;}

// ############### SETTERS ###############
void Contact::setPerson(Person p){this->person = p;}
void Contact::setCodeArea(std::string codeArea){this->codeArea = codeArea;}
void Contact::setPhone(std::string phone){this->phone_number = phone;}
void Contact::setEmail(std::string email){this->email = email;}
void Contact::setCountry(std::string country){this->country = country;}
void Contact::lastUpdateContact(){this->lastUpdate = Date::getAtualDate() + " - " + Date::getAtualTime();}
void Contact::setAllData(Person p, std::string phone_code, std::string phone, std::string email, std::string country){
    this->person = p;
    this->setPhone(phone);
    this->setEmail(email);
}
