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
    FDP();
    FDP(string _name, string _status, string _ID, string _idstudent);
    ~FDP();
    string Getidstudent();
    void Setidstudent(string _idstudent);
};

#endif // FDP_H
