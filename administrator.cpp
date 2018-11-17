#include "administrator.h"
#include <iostream>
using namespace std;

Administrator::Administrator()
{
  list= new Listares;

};
Administrator::Administrator(string _IDCode, string _password, string _name):User(_IDCode,_password,_name)
{

}

Administrator::~Administrator(){}

int Administrator::menu(){
    int op=1;//Gets the number typed by the user
    do{
        system ("cls");
        if(cin.fail()){
            cin.clear();
            cin.ignore(1024, '\n'); //Cleaning cin. from 1024 to NUll
            cout<<" Only numerical values"<<endl;
        };
        if (op!=0&&op!=1&&op!=2&&op!=3&&op!=4){
            cout<<"Select a possible option"<<endl;
            cout<<"\n";
        };
        cout<<"--------ADMINISTRATOR FUNCIONALITIES---------"<<endl;
        cout<<" Create, Modify or Delete resources."<<endl;
        cout<<"0). See Resources"<<endl;
        cout<<"1). Create"<<endl;
        cout<<"2). Modify"<<endl;
        cout<<"3). Delete"<<endl;
        cout<<"4). Exit"<<endl;
        cout<<"Type the number of the option"<<endl;
        cin>>op;
        switch (op) {
        case 0: DisplayResources();
            break;
        case 1: CreateResource();
            break;
        case 2: ModifyResource();
            break;
        case 3: DeleteResource();
            break;
        }
    }while(op!=4);
    return op;
};

void Administrator::CreateResource(){
    string _name,_status,_ID,_professor1id,_professor2id,_idstudent;
    int _credits,op=1,_maxSeats;
    Resource *res;
    Course cour;
    FDP fdp;
    Seminar sem;
    do{
        system("cls");
        if(cin.fail()){
            cin.clear();
            cin.ignore(1024, '\n'); //Cleaning cin. from 1024 to NUll
            cout<<" Only numerical values"<<endl;
        }
        if (op!=1&&op!=2&&op!=3){
            cout<<"Select a possible option"<<endl;
            cout<<"\n";
        }

        cout<<"-----------RESOURCES--------------"<<endl;
        cout<<"1). Course"<<endl;
        cout<<"2). FDP"<<endl;
        cout<<"3). Seminar"<<endl;
        cout<<"Type the number of the option"<<endl;
        cin>>op;
        switch (op) {
        case 1:
            res=&cour;
            cout<<"Type the name: ";
            cin>>_name;
            cout<<"Type the status: ";
            cin>>_status;
            cout<<"Type the ID: ";
            cin>>_ID;
            cout<<"Type the number of credits: ";
            cin>>_credits;
            cout<<"Type the Professor 1 ID: ";
            cin>>_professor1id;
            cout<<"Type the Professor 2 ID: ";
            cin>>_professor2id;
            res=list->ResourcesOnList(_ID); //Checks if the resource ID is already on the list
            if(res==NULL){
                list->selectresource(new Course(_name,_status,_ID,_credits,_professor1id,_professor2id));//Adds the resource to the list
                list->IncrementCour();
            }else{
                cout<<"\n";
                cout<<"The resource already exists. INVALID OPTION."<<endl;
            system("pause");
            }
            break;
        case 2:
            res=&fdp;
            cout<<"Type the name: ";
            cin>>_name;
            cout<<"Type the status: ";
            cin>>_status;
            cout<<"Type the ID: ";
            cin>>_ID;
            cout<<"Type the student SIN: ";
            cin>>_idstudent;
            res=list->ResourcesOnList(_ID); //Checks if the resource ID is already on the list
            if(res==NULL){
                list->selectresource(new FDP(_name,_status,_ID,_idstudent));//Adds the resource to the list
                list->IncrementFDP();
            }else{
                cout<<"\n";
                cout<<"The resource already exists. INVALID OPTION."<<endl;
            system("pause");
            }
            break;
        case 3:
            res=&sem;
            cout<<"Type the name: ";
            cin>>_name;
            cout<<"Type the status: ";
            cin>>_status;
            cout<<"Type the ID: ";
            cin>>_ID;
            cout<<"Type the maximum number of seats: ";
            cin>>_maxSeats;
            res=list->ResourcesOnList(_ID); //Checks if the resource ID is already on the list
            if(res==NULL){
                list->selectresource(new Seminar(_name,_status,_ID,_maxSeats));//Adds the resource to the list
                list->IncrementSeminar();
            }else{
                cout<<"\n";
                cout<<"The resource already exists. INVALID OPTION."<<endl;
            system("pause");
            }

            break;
        }
    }while(op!=4);


}
void Administrator::DeleteResource(){
    system("cls");
    string _ID;
    Resource *res;
    cout<<list->toString();
    cout<<"Please, type the ID of the resource you want to delete."<<endl;
    cin>>_ID;
    res=list->DeleteResource(_ID);
    if (res!=NULL){
        delete res;
        cout<<"The resource was deleted succesfuly."<<endl;
        system("pause");
    }else{
        cout<<"The resource does not exists."<<endl;
        system("pause");
    }
}
void Administrator::DisplayResources(){
    system("cls");
    cout<<"------RESOURCES-------"<<endl;
    cout<<list->toString()<<endl;
    system("pause");
}
void Administrator::ModifyResource(){
    system("cls");
    Resource *aux;
    cout<<"-------MODIFY RESOURCE-------"<<endl;
    string _name,_status,_ID;
    cout<<list->toString();
    cout<<"Type the ID of the resource you want to modify: "<<endl;
    cin>>_ID;
    aux=list->ResourcesOnList(_ID);//Checks if the resource is on the list
    if(aux!=NULL){
        cout<<"Please, enter the new name for the resource: ";
        cin>>_name;
        aux->SetName(_name);
        cout<<"\n";
        cout<<"Please, enter the new status for the resource: ";
        cin>>_status;
        aux->SetStatus(_status);
        cout<<"\n";
        cout<<"Please, enter the new ID for the resource: ";
        cin>>_ID;
        aux->SetID(_ID);
        cout<<"\n";
    }else{
        cout<<"The resource does not exist"<<endl;
        system("pause");
    }


}
void Administrator::administrate(){
    list->chargeresource();//Charge the list from the txt
    menu();
    list->keepresource();//Save the changes on the text
}
