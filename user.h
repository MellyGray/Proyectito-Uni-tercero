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


    //To print the atributes of the user
    virtual string toString()=0;

    //To save the atributes of the user on a text file
    virtual void datasaving( ofstream &)=0;

    //Modify the attributes of the user
    virtual void ModifyUser()=0;

    //Menu depending on the type of User
    virtual int UserMenu()=0;


};

#endif // USER_H
