#include "student.h"
#include <iostream>
using namespace std;

Student::Student() : User(){
}

Student::~Student(){

}

string Student::toString(){
    stringstream s;
    s<< "Student___________"<<name<<endl;
    s<< "Degree____________"<<degree<<endl;
    s<< "SIN_______________"<<IDCode<<endl;
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
    read>>_password;
    read>>_degree;
    read>>_IDCode;
    read>>_name;
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
void Student::MainMenu(){
int op=1;
string give;
cout<<name<< "Welcome to your account"<<endl;
do{
    system ("cls");
    if(cin.fail()){
        cin.clear();
        cin.ignore(1024, '\n'); //Cleaning cin. from 1024 to NUll
        cout<<" Only numerical values"<<endl;
    };
    if (op!=0&&op!=1&&op!=3&&op!=4){
        cout<<"Select a possible option"<<endl;
        cout<<"\n";
    };
    cout<<"--------STUDENT FUNCIONALITIES---------"<<endl;
    cout<<"0)Show Seminars,FDP and course enrrolled"<<endl;
    cout<<"1)See my grades."<<endl;
    cout<<"2)Enroll course,seminar or fdp."<<endl;
    cout<<"3) Drop a course, seminar or fdp."<<endl;
    cout<<"4) Log out"<<endl;
    cout<<endl<<"Type the number of the option"<<endl;
    cin>>op;

    switch (op){
    case 0:
        list->UserOnList(IDCode);//toStringCourses();        meter el comparador dentro de la nueva listares
        system("pause");
            break;
    case 1:
        cout<<list->MarksToString(IDCode);
        system("pause");
            break;
    case 2:list->PrintResourcesOnList(degree);
        cout<<"Introduce the name of the Course, Seminar or FDP that you want to enter"<<endl;
        cin>>give;
        list->EnrollResource(give,IDCode);
            break;
    };
   }while(op!=3);
};
