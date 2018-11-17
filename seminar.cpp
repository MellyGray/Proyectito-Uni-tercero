#include "seminar.h"

Seminar::Seminar()
{
    name="";
    status="";
    ID="";
    maxSeats=0;
};
Seminar::Seminar(string _name, string _status, string _ID, int _maxSeats):Resource (_name,_status,_ID)
{
    maxSeats=_maxSeats;

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
string Seminar::toString(){
    stringstream s;
    s<< "Name__________________"<<name<<endl;
    s<< "Status________________"<< status<<endl;
    s<< "ID____________________"<<ID<<endl;
    s<< "Maximum seats_________"<<maxSeats<<endl;
    return s.str();
};
void Seminar::datasaving( ofstream &write){
    write<<maxSeats<<"\n";
   write<<ID<<"\n";
   write<<status<<"\n";
   write<<name<<"\n";


};
Seminar *Seminar::readTxt(ifstream &read){
    string _name, _status,_ID;
    int _maxSeats;
    read>>_maxSeats;
    read>>_ID;
    read>>_status;
    read>>_name;
    return (new Seminar(_name, _status,_ID,_maxSeats));
};
