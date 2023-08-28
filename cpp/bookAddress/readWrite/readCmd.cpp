#include "readcmd.h"

int readOptionCmd(){
    int option;
    option = readInteger(CHOOSE_OPTION_MSG);
    return option;
}

std::string readFnameCmd(){
    std::string fname;
    std::cout << FNAME_INPUT_MSG;
    fname = readString();
    return fname;
}

std::string readLnameCmd(){
    std::string lname;
    std::cout << LNAME_INPUT_MSG;
    lname = readString();
    return lname;
}

char readGenderCmd(){
    char gender;
    do{
        std::cout << "\tGender: ";
        std::cin >> gender;
    }while(gender != 'm' && gender != 'M' &&
           gender != 'f' && gender != 'F');
    return gender;
}

std::string readEmailCmd(){
    std::string email;
    do{
        std::cout << EMAIL_INPUT_MSG;
        email = readString();
        if(email.find('@') == -1 || email.find('.') == -1)
            std::cout << INVALID_EMAIL;
        else
            break;
    }while(true);
    return email;
}

std::string readPhoneNumberCmd(){
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

Date readDateCmd(){
    int day, month, year;
    Date date;

    std::cout << FOLLOWING_INFO_MSG;
    do{
        day = readInteger("\tDay..: ");
        month = readInteger("\tMonth: ");
        year = readInteger("\tYear.: ");
    }while(!Date::checkDate(day, month, year));

    date.setDate(day, month, year);
    return date;
}

Person readPersonCmd(){
    Person person;
    std::string fname, lname;
    char gender;
    Date birth;

    fname = readFnameCmd();
    lname = readLnameCmd();
    gender = readGenderCmd();
    birth = readDateCmd();

    person.setAllData(fname, lname, gender, birth);
    return person;
}

Contact readContactCmd(){
    Contact c;
    Person p;
    std::string phone, email;

    std::cout << FOLLOWING_INFO_MSG;
    p = readPersonCmd();
    phone = readPhoneNumberCmd();
    email = readEmailCmd();
    
    c.setPhone(phone);
    c.setEmail(email);

    return c;
}