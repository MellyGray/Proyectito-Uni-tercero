#include "course.h"
#include <iostream>
using namespace std;

Course::Course(){}

Course::Course(string _name, string _status, string _ID, int _credits,string _professor1id,string _professor2id):Resource(_name,_status,_ID)
{
    credits=_credits;
    professor1id=_professor1id;
    professor2id=_professor2id;
};
Course::Course(string _name, int _num_users):Resource( _name, _num_users){} //Constructor lista
Course::~Course()
{
    name="";
    status="";
    credits=0;
    professor1id="";
    professor2id="";
   }
string Course::toString(){
    stringstream s;
    s<< "Name____________"<<name<<endl;
    s<< "Status__________"<< status<<endl;
    s<< "ID______________"<<ID<<endl;
    s<< "Credits_________"<<credits<<endl;
    s<< "Professor 1 ID__"<<professor1id<<endl;
    s<< "Professor 2 ID__"<<professor2id<<endl;
    return s.str();
};

string Course::toStringList(){
    stringstream s;
    s<<"Name-------------------"<<name<<endl;
    s<<"Number of students----"<<num_users<<endl;
    s<<"List of students:"<<endl;
    for(int i=0; i<num_users; i++){
        s<<lirray[i]<<endl;
    };
    return s.str();
}

//NUevo writee para listas
void Course::
datasaving( ofstream &write){
   write<<professor2id<<"\n";
   write<<professor1id<<"\n";
   write<<credits<<"\n";
   write<<ID<<"\n";
   write<<status<<"\n";
   write<<name<<"\n";
};

void Course::
datasavinglist(ofstream &writel){
    writel<<name<<"\n";
    writel<<num_users<<"\n";
    for(int i=num_users-1;i>=0;i--){
        writel<<lirray[i]<<"\n";
    };
};

//Nuevo read para listas
Course *Course::readTxt(ifstream &readl){
    string _name, _status,_ID,_professor1id,_professor2id;
    int _credits;
    readl>>_professor2id;
    readl>>_professor1id;
    readl>>_credits;
    readl>>_ID;
    readl>>_status;
    readl>>_name;
    return (new Course(_name, _status,_ID,_credits,_professor1id,_professor2id));
};

Course *Course::readTXTList(ifstream &read){
    string _name, _array;
    int _num_users,i;
    read>>_name;
    read>>_num_users;//NECESARIA UNA CONDICION PARA CUANDO NUM USER SEA 0, LO MIMSO EN SEMINAR
    Course *d1=new Course(_name, _num_users);
    i=_num_users-1;
    for(i=_num_users-1;i>=0;i--){
        read>>d1->lirray[i];
        };
    return (d1);
};



//Modify una lista?
void Course::ModifyResource(){
    cout<<"Please, enter the new name for the course: ";
    cin>>name;
    cout<<"\n";
    cout<<"Please, enter the new status for the course: ";
    cin>>status;
    cout<<"\n";
    cout<<"Please, enter the new ID for the course: ";  // Se tiene que modificar la lista de estudiantes
    cin>>ID;
    cout<<"\n";
    cout<<"Please, enter the new number of credits for the course: ";
    cin>>credits;
    cout<<"\n";
    cout<<"Please, enter the new proffesor 1 for the course: ";
    cin>>professor1id;
    cout<<"\n";
    cout<<"Please, enter the new proffesor 2 for the course: ";
    cin>>professor2id;
    cout<<"\n";
}

void Course::searchinlist(string _id){//listo tiene que funcionar
    int i=num_users-1;
    for(int k=0; k<=i;k++){
        if (lirray[k]==_id){
            cout<<name<<endl;
        }
    }
}
bool Course::checking(){
    return true;
}
