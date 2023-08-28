#ifndef READCMD_H_
#define READCMD_H_

#include <iostream>
#include "./../classes/contact.h"
#include "./../classes/person.h"
#include "./../classes/date.h"
#include "./../util/util.h"
#include "./../util/messages.h"

int readOptionCmd();
std::string readFnameCmd();
std::string readLnameCmd();
char readGenderCmd();
std::string readPhoneNumberCmd();
std::string readEmailCmd();
Date readDateCmd();
Person readPersonCmd();
Contact readContactCmd();

#endif