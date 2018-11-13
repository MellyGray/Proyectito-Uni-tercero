#include "seminar.h"

Seminar::Seminar()
{
    name="";
    status="";
    ID="";
    maxSeats=0;
};
Seminar::Seminar(string _name, string _status, string _ID, int _maxSeats, Date *_date):Resource (_name,_status,_ID)
{
    maxSeats=_maxSeats;
    date=_date;

};
Seminar::~Seminar(){};
int Seminar::GetmaxSeats(){
    return(maxSeats);
};
Date Seminar::Getdate(){
    return(*date);
};
void Seminar::Setdate(Date *_date){
    date=_date;
};
void Seminar::SetmaxSeats(int _maxSeats){
    maxSeats=_maxSeats;
};
void Seminar::DisplayDate(){
    date->DisplayDate();
}
