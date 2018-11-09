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
};

#endif // FDP_H
