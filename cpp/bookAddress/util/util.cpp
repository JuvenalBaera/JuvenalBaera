#include <iostream>
#include <string.h>

#include "util.h"
#include "messages.h"

void newLine(){std::cout << "\n";}

std::string readString(){
    std::string str;
    std::getline(std::cin >> std::ws, str);
    return str;
}

int readInteger(std::string msg){
    int num;
    char* read = (char*) malloc(sizeof(char) * 30);
    bool yesNo = false;
    do{
        std::cout << msg;
        fgets(read, 30, stdin);
        read[strlen(read)-1] = '\0';
        for(int i = 0; i < strlen(read); i++){
            if(read[i] < '0' || read[i] > '9'){
                redColor();
                std::cout << NUMBER_ALLOW;
                read[0] = '\0';
                resetColor();
                yesNo = true;
                break;
            }
        }
    }while(yesNo == true);
    num = atoi(read);
    free(read);
    return num;
}
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

bool isInRange(int num, int min, int max){
    return num >= min && num <= max ? true : false;
}
