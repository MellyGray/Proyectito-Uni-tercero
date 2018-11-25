#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "user.h"


#include <iostream>
using namespace std;

class Professor : public User
{
private:


public:
    Professor();
    Professor(string _name, string _IDCode): User(_name,_IDCode){}
    Professor (string _IDCode, string _password, string _name): User(_IDCode,_password,_name){}
    ~Professor();
    //To print the atributes of professor
    string toString();

    //To save the atributes of the professor on a text file
    void datasaving( ofstream &);

    //To read the data on a text file that corresponds to one professor
    Professor *readTxt(ifstream &);

    //Modify the attributes of the professor
    void ModifyUser();

    //Professor Menu
    int UserMenu();
};

#endif // PROFESSOR_H
