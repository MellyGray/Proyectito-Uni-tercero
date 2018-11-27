#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "user.h"
#include <iostream>
#include "listares.h"
#include <cstdlib> //To clean console
using namespace std;

class Administrator : public User
{
private:
    //List of resources that the administrator can control
    Listares *list;
public:
    //Constructors
    Administrator();
    Administrator(string _name, string _IDCode): User(_name,_IDCode){}
    Administrator(string _IDCode, string _password, string _name): User(_IDCode,_password,_name){}
    ~Administrator();

    //Menu of the administrator options
    int  menu();
    //Menu with file reading
    void administrate();
    //Menu function to display all the resources in the file
    void DisplayResources();
    //Menu function to create a new resource
    void CreateResource();
    //Menu function to delete an existing resource
    void DeleteResource();
    //Menu function to modify an existing resource
    void ModifyResource();

    //To print the atributes of the administrator
    string toString();

    //To save the atributes of the administrator on a text file
    void datasaving( ofstream &);

    //To read the data on a text file that corresponds to one administrator
    Administrator *readTxt(ifstream &);

    //Modify the attributes of the administrator
    void ModifyUser();
};



#endif // ADMINISTRATOR_H
