#ifndef FDP_H
#define FDP_H
#include "resource.h"
#include <iostream>

using namespace std;

class FDP : public Resource
{
private:
    string idstudent;
    string nametutor;
    string idcotutor;

public:
    //Constructors
    FDP();
    FDP(string _name, string _status, string _ID,int _num_users, string _idstudent,string _nametutor,string _degree,string _idcotutor):Resource (_name,_status,_ID,_num_users){idstudent=_idstudent;nametutor=_nametutor;degree=_degree;idcotutor=_idcotutor;}
    ~FDP();
    //Get and set of the student SIN
    string Getidstudent(){return(idstudent);}
    void Setidstudent(string _idstudent){idstudent=_idstudent;}
    string GetDegree(){return degree;}
    //To print the atributes of the resource
    string toString();

    //To print atributes list
    string toStringList();

    //To save the atributes of the resource on a text file
    void datasaving( ofstream &);


    //To read the data on a text file that corresponds to one resource
    FDP *readTxt(ifstream &);

    //Modify the attributes of the fdp
    void ModifyResource();

    void searchinlist(string _id, int x);

    //Checks if it is posible to enroll in resources
    bool checking(string);

    //To introduce a user in the seminar
    void IntroduceUserinResource(string _id);//Falta el cpp

    //To clean a user form course
    void DeleteUserinResource(string _id);


};

#endif // FDP_H
