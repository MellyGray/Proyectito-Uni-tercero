#ifndef LISTUSERS_H
#define LISTUSERS_H
#include "nodousers.h"
#include "student.h"
#include "professor.h"
#include <iostream>
using namespace std;

class Administrator;
class ListUsers
{
public:
    //Constructor and destructor
    ListUsers();
    ~ListUsers();
    //Method to add a new object user to the list
    void AddUser(User *);
    //Method to display the list
    string toString();
    //Method to keep the user info on the text file
    void KeepUsers();
    //Method to charge the users on the text file
    void ChargeUsers();
    //Method to search for a User on a list, typing the ID
    User *UsersOnList(string);
    //Method to search for a User on a list, matching the password and the ID.
    User *Logging(string,string);
    //Method to delete an object from the list
    User *DeleteUser(string);
    //Method to delete a node from the list
    void DeleteNodoUser(NodoUsers *,NodoUsers *);
    //Method to insert a new element to the list on a selected position
    void InsertNodeSelPosition(User *,int position);
    //Gettes & Setters
    int GetNum_admin(){return(num_admin);}
    int GetNum_stu(){return(num_stu);}
    int GetNum_prof(){return(num_prof);}
    void SetNum_admin(int _num_admin){num_admin=_num_admin;}
    void SetNum_stu(int _num_stu){num_stu=_num_stu;}
    void SetNum_prof(int _num_prof){num_prof=_num_prof;}

private:
    NodoUsers *actual;
    int num_admin; //Number of administrators on list
    int num_stu; //Number of students on list
    int num_prof; //Number of professors on list
};

#endif // LISTUSERS_H
