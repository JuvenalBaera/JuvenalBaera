#include "writecmd.h"

void printDate(Date d){
    std::cout << "Date: " << d.getFullDate() << std::endl;
}

void printPerson(Person p){
    greenColor();
    std::cout << NAME_OUTPUT_MSG << p.getFullName() << std::endl;
    std::cout << "Birth Day: " << p.getBirthdate().getFullDate() << std::endl;
    std::cout << "Gender...: " << p.getGender() << std::endl;
    resetColor();
}

void printContact(Contact c){
    greenColor();
    printPerson(c.getPerson());
    std::cout << PHONE_OUTPUT_MSG << c.getPhoneFormated() << std::endl;
    std::cout << EMAIL_OUTPUT_MSG << c.getEmail() << std::endl;
    resetColor();
}