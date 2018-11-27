#include "fdp.h"
#include <iostream>
using namespace std;

FDP::FDP()
{
    name="";
    status="";
    ID="_ID";
    idstudent="_idstudent";
}
FDP::~FDP(){};
string FDP::toString(){
    stringstream s;
    s<< "Name____________"<<name<<endl;
    s<< "Status__________"<< status<<endl;
    s<< "ID______________"<<ID<<endl;
    s<< "Student_________"<<idstudent<<endl;
    s<< "Tutor___________"<<nametutor<<endl;
    return s.str();
}
string FDP::toStringList(){
    stringstream s;
    s<< "Name____________"<<name<<endl;
    s<< "Status__________"<< status<<endl;
    s<< "ID______________"<<ID<<endl;
    s<< "Student_________"<<idstudent<<endl;
    s<<"Tutor____________"<<nametutor<<endl;
    return s.str();
}
void FDP::datasaving( ofstream &write){
     write<<nametutor<<"\n";
    write<<idstudent<<"\n";
   write<<ID<<"\n";
   write<<status<<"\n";
   write<<name<<"\n";


}
void FDP::datasavinglist( ofstream &writel){//Arreglo por virtual resource se puede arreglar 3 milestone
    writel<<name<<"\n";
    writel<<status<<"\n";
    writel<<ID<<"\n";
    writel<<idstudent<<"\n";
   writel<<nametutor<<"\n";




};
FDP *FDP::readTxt(ifstream &read){
    string _name, _status,_ID,_idstudent,_nametutor;
    read>>_nametutor;
    read>>_idstudent;
    read>>_ID;
    read>>_status;
    read>>_name;
    return (new FDP(_name, _status,_ID,_idstudent,_nametutor));
}
FDP *FDP::readTxtList(ifstream &readl){//tutor
    string _name, _status,_ID,_idstudent,_nametutor;
    readl>>_name;
    readl>>_status;
    readl>>_ID;
    readl>>_idstudent;
    readl>>_nametutor;

    return (new FDP(_name, _status,_ID,_idstudent,_nametutor));
}

void FDP::ModifyResource(){
    cout<<"Please, enter the new name for the FDP: ";
    cin>>name;
    cout<<"\n";
    cout<<"Please, enter the new status for the FDP: ";
    cin>>status;
    cout<<"\n";
    cout<<"Please, enter the new ID for the FDP: ";
    cin>>ID;
    cout<<"\n";
    cout<<"Please, enter the new student for the FDP: ";
    cin>>idstudent;
    cout<<"\n";
}
void FDP::searchinlist(string _id){//listo tiene que funcionar
        if (idstudent==_id){
            cout<<name<<endl;
        }//PASAR TODO A ID
    }
bool FDP::checking(){
    if(idstudent==""){
        return true;
    }else
        cout<<"This FDP is assigned to another student"<<endl;
        return false;
}
