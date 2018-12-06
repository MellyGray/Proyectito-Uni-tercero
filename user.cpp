#include "user.h"
#include <iostream>
using namespace std;

User::User(){
    IDCode="";
    password="";
    name="";
}


User::User(string _IDCode, string _password, string _name)
{
IDCode=_IDCode;
password=_password;
name=_name;
}
User::~User(){

}

