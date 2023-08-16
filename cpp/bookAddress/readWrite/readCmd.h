#ifndef READCMD_H_
#define READCMD_H_

#include <iostream>
#include "./../classes/contact.h"
#include "./../classes/person.h"
#include "./../classes/date.h"
#include "./../util/util.h"
#include "./../util/messages.h"

int readOption();
std::string readFname();
std::string readLname();
std::string readPhoneNumber();
std::string readEmail();
Date readDateCmd();
Person readPersonCmd();
Contact readContactCmd();

#endif