#include "writecmd.h"

void printDate(Date d){
    std::cout << "Date: " << d.getFullDate(true) << std::endl;
}

void printPerson(Person p){
    std::cout << NAME_OUTPUT_MSG << p.getFullName() << std::endl;
    printDate(p.getBirthdate());
    std::cout << "Gender...: " << p.getGender() << std::endl;
}

void printContact(Contact c){
    greenColor();
    printPerson(c.getPerson());
    std::cout << PHONE_OUTPUT_MSG << c.getPhoneNumber() << std::endl;
    std::cout << EMAIL_OUTPUT_MSG << c.getEmail() << std::endl;
    std::cout << "Country: " << c.getCountry() << std::endl;
    resetColor();
}