#include <iostream>
#include "util.h"

void newLine(){std::cout << "\n";}
void greenColor(){std::cout << GREEN_COLOR;}
void redColor(){std::cout << RED_COLOR;}
void yellowColor(){std::cout << YELLOW_COLOR;}
void blueColor(){std::cout << BLUE_COLOR;}
void resetColor(){std::cout << RESET_COLOR;}

void showMessageSuccess(std::string msg){
    yellowColor();
    std::cout << msg;
    resetColor();
}
void showMessageError(std::string msg){
    redColor();
    std::cout << msg;
    resetColor();
}