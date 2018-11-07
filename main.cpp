#include <iostream>
#include "virtualcampus.h"


using namespace std;

int main()
{

    cout<<"MILESTONE 1.Test of constructors, getters and setters and administrator funcionalities."<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
        cout<<"Course Class"<<endl;
    Course c1("Computing Systems I","created", "KDMFKEU",6,"Mohammed","Jorge"),c2;
            cout<<"The course "<<c1.GetName()<<" has the status "<<c1.Getstatus()<<", its number of credits is "<<c1.Getcredits()<<","<<endl;
            cout<<"its ID is "<<c1.GetID()<<" and the proffesors are "<<c1.Getprofessor1id()<<" and "<<c1.Getprofessor2id()<<endl;
    c2.SetName("Analog Electronics I");
    c2.SetStatus("created");
    c2.SetID("KSOEHVN");
    c2.Setcredits(6);
    c2.Setprofessor1id("Fulanito");
    c2.Setprofessor2id("Menganito");
    cout<<"The course "<<c2.GetName()<<" has the status "<<c2.Getstatus()<<", its number of credits is "<<c2.Getcredits()<<","<<endl;
    cout<<"its ID is "<<c2.GetID()<<" and the proffesors are "<<c2.Getprofessor1id()<<" and "<<c2.Getprofessor2id()<<endl;

        cout<<"---------------------------------------------------------------------------------------"<<endl;
        cout<<"FDP Class"<<endl;
        FDP f1("Algo super guay","in progress", "KSJFOEI","2049503"),f2;
        f2.SetName("Que rollo poner nombres");
        f2.SetStatus("created");
        f2.SetID("LDJROFH");
        f2.Setidstudent("9462948");
        cout<<"The FDP "<<f1.GetName()<<" had the status "<<f1.Getstatus()<<", the ID "<<f1.GetID()<<endl;
        cout<<"and belongs to the student with the SIN "<<f1.Getidstudent()<<endl;
        cout<<"The FDP "<<f2.GetName()<<" had the status "<<f2.Getstatus()<<", the ID "<<f2.GetID()<<endl;
        cout<<"and belongs to the student with the SIN "<<f2.Getidstudent()<<endl;

        cout<<"---------------------------------------------------------------------------------------"<<endl;
        cout<<"Seminar Class"<<endl;
        Seminar se1,se2;
        cout<<"---------------------------------------------------------------------------------------"<<endl;
       cout<<"Student Class"<<endl;
    Student s2("0392758","lsjfljfe4","Eduardo"),s1;
    s1.SetIDCode("2049503");
    s1.SetPassword("sfsSFFG9");
    s1.SetName("Melina");
    cout<<"The student "<<s2.GetName()<<" has the SIN "<<s2.GetIDCode()<<" and the password "<<s2.GetPassword()<<endl;
    cout<<"The student "<<s1.GetName()<<" has the SIN "<<s1.GetIDCode()<<" and the password "<<s1.GetPassword()<<endl;

    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"Professor Class"<<endl;
    Professor p1,p2;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"Administrator Class"<<endl;
    Administrator admin1,admin2;
    cout<<"---------------------------------------------------------------------------------------"<<endl;

    return 0;
}
