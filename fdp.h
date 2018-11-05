#ifndef FDP_H
#define FDP_H
#include "resource.h"
#include "student.h"
#include "professor.h"
#include <iostream>
#include "listofstudents.h"
using namespace std;

class FDP : public Resource
{
private:
    string idstudent;//Tambien poner aca la lista de ids
    //ListOFIds *listofidprofessors;//List que lee de txt
    //ReadTxtString *work;



public:
    FDP();
    FDP(string _name, string _status, string _ID, string _idstudent/*ListOFIds *_listofidprofessors, /*ReadTxtString *_work(future upgrade)*/);
    ~FDP();
    string Getidstudent();
    void Setidstudent(string _idstudent);
};

#endif // FDP_H
