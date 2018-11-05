#include "fdp.h"
#include <iostream>
using namespace std;

FDP::FDP()
{
    name="";
    status="";
    ID="_ID";
    idstudent="_idstudent";
};
FDP::FDP(string _name, string _status, string _ID, string _idstudent /*ListOFIds *_listofidprofessors /*ReadTxtString *_work(future upgrade)*/)
{
    name=_name;
    status=_status;
    ID=_ID;
    idstudent=_idstudent;
    //*listofidprofessors=*_listofidprofessors;
};
FDP::~FDP(){};
string FDP::Getidstudent(){
    return(idstudent);
};
void FDP::Setidstudent(string _idstudent){
    idstudent=_idstudent;
};
