#ifndef FDP_H
#define FDP_H
#include "resource.h"
#include <iostream>

using namespace std;

class FDP : public Resource
{
private:
    string idstudent;
public:
    //Constructors
    FDP();
    FDP(string _name, string _status, string _ID, string _idstudent);
    ~FDP();
    //Get and set of the student SIN
    string Getidstudent();
    void Setidstudent(string _idstudent);
    //To print the atributes of the resource
    string toString();

    //To save the atributes of the resource on a text file
    void datasaving( ofstream &);

    //To read the data on a text file that corresponds to one resource
    FDP *readTxt(ifstream &);
    //Modify the attributes of the fdp
    void ModifyResource();

};

#endif // FDP_H
