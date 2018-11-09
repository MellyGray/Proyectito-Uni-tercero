#ifndef USER_H
#define USER_H
#include <iostream>
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
    User(string _IDCode, string _password, string _name);
    ~User();
    //Setters & getters
    void SetIDCode(string _IDCode);
    void SetPassword(string _password);
    void SetName(string _name);
    string GetIDCode();
    string GetPassword();
    string GetName();

};

#endif // USER_H
