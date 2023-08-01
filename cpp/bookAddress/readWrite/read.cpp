#include "read.h"

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
    std::string lname;
    std::cout << EMAIL_INPUT_MSG;
    lname = readString();
    return lname;
}

std::string readPhoneNumber(){
    std::string phone;
    int sizeLen;
    std::cout << PHONE_INPUT_MSG;
    phone = readString();

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