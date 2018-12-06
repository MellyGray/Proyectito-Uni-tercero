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

public:
    //Constructors
    FDP();
    FDP(string _name, string _status, string _ID, string _idstudent,string _nametutor):Resource (_name,_status,_ID){idstudent=_idstudent;nametutor=_nametutor;}
    ~FDP();
    //Get and set of the student SIN
    string Getidstudent(){return(idstudent);}
    void Setidstudent(string _idstudent){idstudent=_idstudent;}
    //To print the atributes of the resource
    string toString();

    //To print atributes list
    string toStringList();

    //To save the atributes of the resource on a text file
    void datasaving( ofstream &);

    void datasavinglist( ofstream &);


    //To read the data on a text file that corresponds to one resource
    FDP *readTxt(ifstream &);

    FDP *readTxtList(ifstream &);

    //Modify the attributes of the fdp
    void ModifyResource();

    void searchinlist(string _id);

    //Checks if it is posible to enroll in resources
    bool checking();

};

#endif // FDP_H
