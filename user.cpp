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
void User::SetIDCode(string _IDCode){
    IDCode=_IDCode;
}
void User::SetPassword(string _password){
    password=_password;
}
void User::SetName(string _name){
    name=_name;
}
string User::GetIDCode(){
    return (IDCode);
}
string User::GetPassword(){
    return (password);
}
string User::GetName(){
    return (name);
}
