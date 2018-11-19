#include "seminar.h"

Seminar::Seminar()
{
    name="";
    status="";
    ID="";
    maxSeats=0;
};
Seminar::~Seminar(){};

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
void Seminar::ModifyResource(){
    cout<<"Please, enter the new name for the seminar: ";
    cin>>name;
    cout<<"\n";
    cout<<"Please, enter the new status for the seminar: ";
    cin>>status;
    cout<<"\n";
    cout<<"Please, enter the new ID for the seminar: ";
    cin>>ID;
    cout<<"\n";
    cout<<"Please, enter the new maximum number of seats for the seminar: ";
    cin>>maxSeats;
    cout<<"\n";

}
