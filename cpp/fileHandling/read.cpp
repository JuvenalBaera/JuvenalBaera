#include <iostream>
#include <fstream>

int main(){

    std::fstream read;
    std::string str;

    read.open("file.txt", std::ios::in);

    if(read.is_open()){
        while(std::getline(read, str))
            std::cout << str << std::endl;
    }

    return 0;
}