#include "administrator.h"
#include <iostream>
using namespace std;

Administrator::Administrator()
{
  list= new Listares;

};
Administrator::Administrator(string _IDCode, string _password, string _name)
{
    IDCode=_IDCode;
    password=_password;
    name=_name;
}

Administrator::~Administrator(){}

int Administrator::menu(){
    int op=1;
    do{
        system ("cls"); //Could produce troubles, Cleans console.
        if(cin.fail()){
            cin.clear();//Si se cambia esto abajo cambiando el orden no daría nugún problema
            cin.ignore(1024, '\n'); //Cleaning cin. from 1024 to NUll
            cout<<" Only numerical values"<<endl;
        };
        if (op!=1&&op!=2&&op!=3&&op!=4){
            cout<<"Select a possible option"<<endl;
        };
        cout<<" Create, Modify or Delete"<<endl;
        cout<<"1). Create"<<endl;
        cout<<"2). Modify"<<endl;
        cout<<"3). Delete"<<endl;
        cout<<"4). Exit"<<endl;
        cout<<"Insert the number of the option"<<endl;
        cin>>op;
    }while(op!=4);

    return op;

};
void Administrator::administrate(){
    list->chargeresource();
    menu();
    list->keepresource();
}
