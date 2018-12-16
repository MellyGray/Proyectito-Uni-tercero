#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "user.h"
#include <iostream>
#include "listares.h"

#include <cstdlib> //To clean console
using namespace std;

class ListUsers;
class Administrator : public User
{
private:
    //List of resources that the administrator can control
    Listares *listres;
    ListUsers *listusers;
public:
    //Constructors
    Administrator();
    Administrator(string _name, string _IDCode): User(_name,_IDCode){}
    Administrator(string _IDCode, string _password, string _name): User(_IDCode,_password,_name){}
    ~Administrator();

    //Menu of the administrator options
    int MainMenu();
    int UserMenu();
    int MenuResources();
    int MenuUsers();

    //Checks if the typed ID has the format LLLNNNN
    bool CheckResourceID(string _ID);
    //Checks if the typed SIN has 7 digits
    bool CheckSIN(string _IDCode);
    //Checks if the typed ID has 7 letters
    bool CheckUserID(string _IDCode);

    //Menu function to display all the resources in the file
    void DisplayResources();
    void DisplayUsers();
    //Menu function to create a new resource
    void CreateResource();
    void CreateUser();
    //Menu function to delete an existing resource
    int DeleteResource();
    int DeleteUser();
    //Menu function to modify an existing resource
    void ModifyResource();
    void ModifyUsers();

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
