#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;

class User
{
private:
    string IDCode;
    string password;
    string name;

public:
    User();
    User(string _IDCode, string _password, string _name);
    ~User();
    void SetIDCode(string _IDCode);
    void SetPassword(string _password);
    void SetName(string _name);
    string GetIDCode(string _IDCode);
    string GetPassword(string _password);
    string GetName(string _name);
};

#endif // USER_H
