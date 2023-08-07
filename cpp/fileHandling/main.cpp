#include <iostream>
#include <fstream>
#include <locale.h>

int main(){
    std::fstream myFile;
    std::string write;
    std::string flag;


    myFile.open("file.txt", std::ios::app);

    if(!myFile.is_open()){
        std::cout << "Error on opening file\n";
        return 1;
    }

    std::cout << "Choose any flag: ";
    std::getline(std::cin >> std::ws, flag);

    std::cout << "Enter a text to write on file\n";
    while(true){
        std::getline(std::cin >> std::ws, write);

        if(write == flag) break;
        myFile << write << "\n";
    }

    myFile.close();
    return 0;
}