#include "student.h"
#include <iostream>
using namespace std;

Student::Student() : User(){
    list= new Listares;
}

Student::~Student(){

}
string Student::toString(){
    stringstream s;
    s<< "Name____________"<<name<<endl;
    s<< "SIN_____________"<<IDCode<<endl;
    return s.str();
}
void Student::datasaving( ofstream &write){
   write<<name<<"\n";
   write<<IDCode<<"\n";
}
void Student::menu(){
int op;
string give;
cout<<name<< "Welcome to your account"<<endl;
do{
    system ("cls");
    if(cin.fail()){
        cin.clear();  //Reentender esto
        cin.ignore(1024, '\n'); //Cleaning cin. from 1024 to NUll
        cout<<" Only numerical values"<<endl;
    };
    if (op!=0&&op!=1&&op!=2){
        cout<<"Select a possible option"<<endl;
        cout<<"\n";
    };
    cout<<"--------STUDENT FUNCIONALITIES---------"<<endl;
    cout<<"0)Show Seminars,FDP or cursed enrrolled"<<endl;
    cout<<"1)Enroll course,seminar,fdp"<<endl;//Un coñazo, busca si el maximo numero no esta lleno,
    cout<<"2) Drop a course"<<endl;
    cout<<"3) Log out"<<endl;
    cout<<endl<<"Type the number of the option"<<endl;
    cin>>op;

    switch (op){
    case 0: list->UserOnList(IDCode);//toStringCourses();        meter el comparador dentro de la nueva listares
            break;
    case 1:list->PrintResourcesOnList();
        cout<<"Introduce the name of the Course, Seminar or FDP that you want to enter"<<endl;
        cin>>give;
        list->EnrollResource(give,IDCode);
            break;
    case 2://Quitarse de la lista
    };
   }while(op!=2);
};


void Student::studentate(){
    list->chargeresourcelist();//Charge the list from the txt
    menu();
    list->keepsourcelist();//Save the changes on the text
}






