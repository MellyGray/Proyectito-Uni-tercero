#include <iostream>
#include "virtualcampus.h"


using namespace std;

int main()
{

    cout<<"MILESTONE 1.Test of constructors, getters and setters and administrator funcionalities."<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
        cout<<"Course Class"<<endl;
    Course c1("Computing Systems I","created", "KDMFKEU",6,"Mohammed","Jorge"),c2;
            cout<<"The course "<<c1.GetName()<<" has the status "<<c1.Getstatus()<<", its number of credits is "<<c1.Getcredits()<<endl;
            cout<<" ,its ID is "<<c1.GetID()<<" and the proffesors are "<<c1.Getprofessor1id()<<" and "<<c1.Getprofessor2id()<<endl;
    c2.Setcredits(3);
    c2.Setprofessor1id("Fulanito");
    c2.Setprofessor2id("Menganito");
        cout<<"---------------------------------------------------------------------------------------"<<endl;
       cout<<"Student Class"<<endl;
    Student s1;
    s1.SetIDCode("2049503");
    s1.SetPassword("sfsSFFG9");
    s1.SetName("Melina");
    cout<<"The student "<<s1.GetName()<<" has the SIN "<<s1.GetIDCode()<<" and the password "<<s1.GetPassword()<<endl;


    return 0;
}
