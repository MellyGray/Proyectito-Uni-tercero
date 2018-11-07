#include "seminar.h"

Seminar::Seminar()
{
    name="";
    status="";
    ID="";
    maxSeats=0;
    //date=_date; Como se haría?
};
Seminar::Seminar(string _name, string _status, string _ID, int _maxSeats, Date _date)
{
    name=_name;
    status=_status;
    ID=_ID;
    maxSeats=_maxSeats;

};
Seminar::~Seminar(){};
int Seminar::GetmaxSeats(){
    return(maxSeats);
};
Date Seminar::Getdate(){
    return(date);
};
void Seminar::Setdate(Date _date){
    date=_date;
};
void Seminar::SetmaxSeats(int _maxSeats){
    maxSeats=_maxSeats;
};
