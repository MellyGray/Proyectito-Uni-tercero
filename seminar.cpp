#include "seminar.h"

Seminar::Seminar()
{
    name="";
    status="";
    ID="";
    maxSeats=0;
}
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
}

string Seminar::toStringList(){
    stringstream s;
    s<<"Name------------------"<<name<<endl;
    s<<"Number of students----"<<num_users<<endl;
    s<<"Maximum seats----------"<<maxSeats<<endl;
    s<<"List of students:-----"<<endl;
       for(int i=0; i<num_users; i++){
           s<<lirray[i]<<endl;
       };
    return s.str();
}
void Seminar::datasaving( ofstream &write){
    write<<maxSeats<<"\n";
   write<<ID<<"\n";
   write<<status<<"\n";
   write<<name<<"\n";


}
void Seminar::datasavinglist(ofstream &writel){
    writel<<name<<"\n";
    writel<<num_users<<"\n";
    writel<<maxSeats<<"\n";
    for(int i=num_users-1;i>=0;i--){
        writel<<lirray[i]<<"\n";
    };
}
Seminar *Seminar::readTxt(ifstream &read){
    string _name, _status,_ID;
    int _maxSeats;
    read>>_maxSeats;
    read>>_ID;
    read>>_status;
    read>>_name;
    return (new Seminar(_name, _status,_ID,_maxSeats));
}
Seminar *Seminar::readTXTlist(ifstream &readl){//tiene que leer de al reves que en RESOURCESTXT
    string _name;
    int _num_users,i,_maxSeats;

    readl>>_name;
    readl>>_num_users;
    readl>>_maxSeats;
    //string *array=new a[_num_users];OTRA OPCION QUE NECESITA CONSTRUCTOR DIFRENTE CON ARRAY DINAMICO DE PARAMETRIZACIÓN
    Seminar *d1=new Seminar(_name,_num_users,_maxSeats);
    for(i=0;i<_num_users;i++){
        readl>>d1->lirray[i];
    };
    return d1;
}
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

void Seminar::searchinlist(string _id){
    int i=num_users-1;
    for(int k=0; k<=i;k++){
        if (lirray[k]==_id){
            cout<<name<<endl;
        }
    }
}

bool Seminar::checking(){
    if(num_users==maxSeats){//Hay que checkear con el numero máximo cry cry cry cry cry.TA READY YA CRACK A VER SI TIRA JODER
        cout<<"There are no free seats"<<endl;
        return false;
    }
    if(num_users<maxSeats){
        return true;
    }
}
