#include "write.h"

void printContact(Contact c){
    greenColor();
    std::cout << NAME_OUTPUT_MSG << c.getFullName() << std::endl;
    std::cout << PHONE_OUTPUT_MSG << c.getPhoneFormated() << std::endl;
    std::cout << EMAIL_OUTPUT_MSG << c.getEmail() << std::endl;
    resetColor();
}