#include "professor.h"
#include <iostream>
using namespace std;

Professor::Professor():User(){
}
Professor::~Professor(){}

string Professor::toString(){
    stringstream s;
    s<< "Name____________"<<name<<endl;
    s<< "SIN______________"<<IDCode<<endl;
    return s.str();
};
void Professor::datasaving( ofstream &write){
    write<<password<<"\n";
   write<<IDCode<<"\n";
   write<<name<<"\n";


};
Professor *Professor::readTxt(ifstream &read){
    string _name, _IDCode,_password;
    read>>_password;
    read>>_IDCode;
    read>>_name;
    return (new Professor(_IDCode, _password,_name));
};

void Professor::ModifyUser(){
    cout<<"Please, enter the new name for the professor: ";
    cin>>name;
    cout<<"\n";
    cout<<"Please, enter the new ID for the professor: ";
    cin>>IDCode;
    cout<<"\n";
}

int Professor::UserMenu(){
    listares= new Listares;
    listares->chargeresource();
    MainMenu();
    listares->keepresource();

    return 0;
}
int Professor::MainMenu(){
    int op=1;//Gets the number typed by the user
    string _ID;
    Resource *aux;
    do{
        system ("cls");
        if(cin.fail()){
            cin.clear();
            cin.ignore(1024, '\n'); //Cleaning cin. from 1024 to NUll
            cout<<" Only numerical values"<<endl;
        };
        if (op!=1&&op!=2&&op!=3){
            cout<<"Select a possible option"<<endl;
            cout<<"\n";
        };
        cout<<"--------WELCOME PROFESSOR "<<name<<"!---------"<<endl;
        cout<<"1). Show Info"<<endl;
        cout<<"2). Modify Resource"<<endl;
        cout<<"3). Exit"<<endl;
        cout<<"Type the number of the option"<<endl;
        cin>>op;
        switch (op) {
        case 1:
            system("cls");
            cout<<"USER INFO"<<endl;
            cout<< "Name____________"<<name<<endl;
            cout<< "SIN_____________"<<IDCode<<endl;
             cout<<"\n";
            cout<<"RESOURCES INVOLVED IN"<<endl;
            listares->UserOnList(IDCode);
            system("pause");
            break;
        case 2:
            system("cls");
            cout<<"These are the resources you are involved in: "<<endl;
            listares->UserOnList(IDCode);
            cout<<"Type the ID of the resource you want to modify: "<<endl;
            cin>>_ID;
            aux=listares->ResourcesOnList(_ID);//Checks if the resource is on the list
            if(aux!=NULL){
               aux->ModifyResource();
            }else{
                cout<<"The resource does not exist"<<endl;
                system("pause");
            }
            break;
        }
    }while(op!=3);

    return op;

}
