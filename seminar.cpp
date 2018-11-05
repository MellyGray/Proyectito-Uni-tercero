#include "seminar.h"

Seminar::Seminar()
{
    name="";
    status="";
    ID="";
    maxSeats=0;
    //date=_date; Como se haría?
};
Seminar::Seminar(string _name, string _status, string _ID, /*ListOFIds *_tutors,*/ int _maxSeats, Date *_date,/* ListOfIdS * _listofidstudents*/)
{
    name=_name;
    status=_status;
    ID=_ID;
   // *tutors=*_tutors;
    maxSeats=_maxSeats;
    date=_date;
    //*listofidstudents=*_listofidstudents;
};
Seminar::~Seminar(){};
int Seminar::GetmaxSEats(){
    return(maxSeats);
};
Date Seminar::Getdate(){
    return(*date);
};
void Seminar::Setdate(Date *_date){
    *date=*_date;
};
void Seminar::SetmaxSeats(int _maxSeats){
    maxSeats=_maxSeats;
};
