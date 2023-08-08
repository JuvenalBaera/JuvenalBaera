#include "readcmd.h"

int readOption(){
    int option;
    option = readInteger(CHOOSE_OPTION_MSG);
    return option;
}

std::string readFname(){
    std::string fname;
    std::cout << FNAME_INPUT_MSG;
    fname = readString();
    return fname;
}

std::string readLname(){
    std::string lname;
    std::cout << LNAME_INPUT_MSG;
    lname = readString();
    return lname;
}

std::string readEmail(){
    std::string email;
    do{
        std::cout << EMAIL_INPUT_MSG;
        email = readString();
        if(email.find('@') == -1 || email.find('.') == -1)
            std::cout << INVALID_EMAIL;
        else
            break;
    }while(1);
    return email;
}

std::string readPhoneNumber(){
    std::string phone;
    int sizeLen = 1;

    do{
        sizeLen = 1;
        std::cout << PHONE_INPUT_MSG;
        phone = readString();
        for(char ch : phone){
            if(!isdigit(ch)){
                std::cout << INVALID_PHONE;
                sizeLen = 0;
                break;
            }
        }
    }while(sizeLen == 0);



    sizeLen = phone.length();
    if(sizeLen != 9){
        for(int i = 0; i < 9 - sizeLen; i++)
            phone.insert(0, "0");
    }
    return phone;
}

Contact readContact(){
    Contact c;
    std::string fname, lname, phone, email;

    std::cout << FOLLOWING_INFO_MSG;
    fname = readFname();
    lname = readLname();
    phone = readPhoneNumber();
    email = readEmail();

    c.setFullName(fname, lname);
    c.setPhone(phone);
    c.setEmail(email);

    return c;
}