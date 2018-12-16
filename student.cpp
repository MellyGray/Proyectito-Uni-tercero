#include "student.h"
#include <iostream>
using namespace std;

Student::Student() : User(){
}

Student::~Student(){

}

string Student::toString(){
    stringstream s;
    s<< "Name____________"<<name<<endl;
    s<< "Degree____________"<<degree<<endl;
    s<< "SIN______________"<<IDCode<<endl;
    s<<"password----------"<<password<<endl;
    return s.str();
};
void Student::datasaving( ofstream &write){
    write<<password<<"\n";
    write<<degree<<"\n";
   write<<IDCode<<"\n";
   write<<name<<"\n";


};
Student *Student::readTxt(ifstream &read){
    string _name, _IDCode,_password,_degree;
    getline(read,_password);
    getline(read,_degree);
    getline(read,_IDCode);
    getline(read,_name);
    return (new Student(_IDCode, _password,_name,_degree));
};

void Student::ModifyUser(){
    cout<<"Please, enter the new name for the student: ";
    cin>>name;
    cout<<"\n";
    cout<<"Please, enter the new degree for the student: ";
    cin>>degree;
    cout<<"\n";
}

int Student::UserMenu(){
    list->chargeresource();//Charge the list from the txt
    MainMenu();
    list->keepresource();//Save the changes on the text
}
int Student::MainMenu(){
int op=1;
string give;
Resource *aux;
cout<<name<< "Welcome to your account"<<endl;
do{
    cout<<"\033[2J\033[1;1H";
    if(cin.fail()){
        cin.clear();
        cin.ignore(1024, '\n'); //Cleaning cin. from 1024 to NUll
        cout<<" Only numerical values"<<endl;
    };
    if (op!=0&&op!=1&&op!=3){
        cout<<"Select a possible option"<<endl;
        cout<<"\n";
    };
    cout<<"--------STUDENT FUNCIONALITIES---------"<<endl;
    cout<<"0)Show Seminars,FDP or cursed enrrolled"<<endl;
    cout<<"1)Enroll course,seminar,fdp"<<endl;
    cout<<"2) Drop a course"<<endl;
    cout<<"3) Log out"<<endl;
    cout<<endl<<"Type the number of the option"<<endl;
    cin>>op;
    switch (op){
    case 0:
        list->UserOnList(IDCode,1);//toStringCourses();        meter el comparador dentro de la nueva listares
        system("pause");
            break;
    case 1:list->PrintResourcesOnList(degree);
        cout<<"Introduce the name of the Course, Seminar or FDP that you want to enter"<<endl;
        cin>>give;
        list->EnrollResource(give,IDCode,degree);
            break;
    case 2:
        list->UserOnList(IDCode,1);
        cout<<"Those are your resources"<<endl<<"Please, introduce the name of the Resource that you want to drop"<<endl;
        cin>>give;
        aux=list->ResourcesOnList(give);
        aux->DeleteUserinResource(IDCode);
            break;

    }
   }while(op!=3);
return op;
};
