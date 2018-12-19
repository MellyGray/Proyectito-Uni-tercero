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
    s<< "SIN______________"<<IDCode<<endl;
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
int Student::MainMenu(){
int op=1;
string give;
Resource *aux;
char c;
cout<<name<< "Welcome to your account"<<endl;
do{
    cout<<"\033[2J\033[1;1H";
    if(cin.fail()){
        cin.clear();
        cin.ignore(1024, '\n'); //Cleaning cin. from 1024 to NUll
        cout<<" Only numerical values"<<endl;
    };
    if (op!=0&&op!=1&&op!=3&&op!=4){
        cout<<"Select a possible option"<<endl;
        cout<<"\n";
    };
    cout<<"--------WELCOME STUDENT "<<name<<"!---------"<<endl;
    cout<<"1)Show Seminars,FDP and course enrrolled"<<endl;
    cout<<"2)See my grades."<<endl;
    cout<<"3)Enroll course,seminar or fdp."<<endl;
    cout<<"4) Drop a course, seminar or fdp."<<endl;
    cout<<"0) Log out & Save changes"<<endl;
    cout<<endl<<"Type the number of the option"<<endl;
    cin>>op;
    switch (op){
    case 1:
        cout<<"\033[2J\033[1;1H";
        cout << ""<<endl;
        cin.get();
        list->UserOnList(IDCode,1);
        cout << "Press enter to continue ..."<<endl;
        cin.get();
            break;

    case 2:
        cout<<"\033[2J\033[1;1H";
        cout << ""<<endl;
        cin.get();
        cout<<list->MarksToString(IDCode);
        cout << "Press enter to continue ..."<<endl;
        cin.get();
            break;
    case 3:
        cout<<"\033[2J\033[1;1H";
        cout << ""<<endl;
        cin.get();
        list->PrintResourcesOnList(degree);
        cout<<"Introduce the name of the Course, Seminar or FDP that you want to enter"<<endl;
        cin>>give;
        list->EnrollResource(give,IDCode,degree);
        cin.get();
        cout << "Press enter to continue ..."<<endl;
        cin.get();
            break;
    case 4:
        cout<<"\033[2J\033[1;1H";
        cout << ""<<endl;
        cin.get();
        list->UserOnList(IDCode,1);
        cout<<"Those are your resources"<<endl<<"Please, introduce the ID of the Resource that you want to drop"<<endl;
        cin>>give;
        aux=list->ResourcesOnList(give);
        if(aux!=NULL){
        aux->DeleteUserinResource(IDCode);
        cout << "Press enter to continue ..."<<endl;
        cin.get();
        }else{
            cout<<"The resource does not exist."<<endl<<endl;
            cin.get();
            cout << "Press enter to continue ..."<<endl;
            cin.get();
           }
        break;

    }
   }while(op!=0);
return op;
};
