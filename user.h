#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class User
{
protected:
    string IDCode;
    string password;
    string name;

public:
    //Constructors
    User();
    User(string _name, string _IDCode){IDCode=_IDCode;name=_name;}
    User(string _IDCode, string _password, string _name);
    virtual ~User();
    //Setters & getters
    void SetIDCode(string _IDCode){IDCode=_IDCode;}
    void SetPassword(string _password){password=_password;}
    void SetName(string _name){name=_name; }
    string GetIDCode(){return (IDCode);}
    string GetPassword(){ return (password); }
    string GetName(){return (name);}




};

#endif // USER_H
