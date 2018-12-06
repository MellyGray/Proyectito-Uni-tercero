#include "administrator.h"
#include <iostream>
#include "listusers.h"

Administrator::Administrator()
{
  listres= new Listares;
  listusers=new ListUsers;
  password="_";

}
Administrator::~Administrator(){}


string Administrator::toString(){
    stringstream s;
    s<< "Name____________"<<name<<endl;
    s<< "ID______________"<<IDCode<<endl;
    return s.str();
};
void Administrator::datasaving( ofstream &write){
    write<<password<<"\n";
   write<<IDCode<<"\n";
   write<<name<<"\n";


};
Administrator *Administrator::readTxt(ifstream &read){
    string _name, _IDCode,_password;
    read>>_password;
    read>>_IDCode; 
    read>>_name;
    return (new Administrator(_IDCode, _password,_name));
};

void Administrator::ModifyUser(){
    cout<<"Please, enter the new name for the administrator: ";
    cin>>name;
    cout<<"\n";
    cout<<"Please, enter the new ID for the administrator: ";
    cin>>IDCode;
    cout<<"\n";
}
int Administrator::UserMenu(){
    listres= new Listares;
    listusers=new ListUsers;
    listres->chargeresource();
    listusers->ChargeUsers();

    MainMenu();
    listres->keepresource();
    listusers->KeepUsers();
    return 0;
}
int Administrator::MainMenu(){

    int op=1;//Gets the number typed by the user
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
        cout<<"--------ADMINISTRATOR FUNCIONALITIES---------"<<endl;
        cout<<"1). Resources"<<endl;
        cout<<"2). Users"<<endl;
        cout<<"3). Exit"<<endl;
        cout<<"Type the number of the option"<<endl;
        cin>>op;
        switch (op) {
        case 1: MenuResources();
            break;
        case 2: MenuUsers();
            break;
        }
    }while(op!=3);

    return op;

}

int Administrator::MenuResources(){
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
int Administrator::MenuUsers(){
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
        cout<<" Create, Modify or Delete users."<<endl;
        cout<<"0). See Users"<<endl;
        cout<<"1). Create"<<endl;
        cout<<"2). Modify"<<endl;
        cout<<"3). Delete"<<endl;
        cout<<"4). Exit"<<endl;
        cout<<"Type the number of the option"<<endl;
        cin>>op;
        switch (op) {
        case 0: DisplayUsers();
            break;
        case 1: CreateUser();
            break;
        case 2: ModifyUsers();
            break;
        case 3: DeleteUser();
            break;
        }
    }while(op!=4);
    return op;
};

void Administrator::CreateResource(){
    string _name,_status,_ID,_professor1id,_professor2id,_idstudent,_nametutor,_SpeakerID;
    int _credits,op=1,_maxSeats;
    Resource *res;
    do{
        system("cls");
        if(cin.fail()){
            cin.clear();
            cin.ignore(1024, '\n'); //Cleaning cin. from 1024 to NUll
            cout<<" Only numerical values"<<endl;
        }
        if (op!=1&&op!=2&&op!=3&&op!=4){
            cout<<"Select a possible option"<<endl;
            cout<<"\n";
        }

        cout<<"-----------RESOURCES--------------"<<endl;
        cout<<"1). Course"<<endl;
        cout<<"2). FDP"<<endl;
        cout<<"3). Seminar"<<endl;
        cout<<"4). Back"<<endl;
        cout<<"Type the number of the option"<<endl;
        cin>>op;
        switch (op) {
        case 1:
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
            res=listres->ResourcesOnList(_ID); //Checks if the resource ID is already on the list
            if(res==NULL){
                listres->InsertNodeSelPosition(new Course(_name,_status,_ID,_credits,_professor1id,_professor2id),listres->GetNum_cour());
                listres->SetNum_cour((listres->GetNum_cour()+1));
                 system("pause");

            }else{
                cout<<"\n";
                cout<<"The resource already exists. INVALID OPTION."<<endl;
            system("pause");
            }
            break;
        case 2:
            cout<<"Type the name: ";
            cin>>_name;
            cout<<"Type the status: ";
            cin>>_status;
            cout<<"Type the ID: ";
            cin>>_ID;
            cout<<"Type the student SIN: ";
            cin>>_idstudent;
            cout<<"Type the name of the tutor: ";
            cin>>_nametutor;
            res=listres->ResourcesOnList(_ID); //Checks if the resource ID is already on the list
            if(res==NULL){
                int position=((listres->GetNum_cour()+listres->GetNum_fdp())+1);
                listres->InsertNodeSelPosition(new FDP(_name,_status,_ID,_idstudent,_nametutor),position);
                listres->SetNum_fdp((listres->GetNum_fdp()+1));
                system("pause");
            }else{
                cout<<"\n";
                cout<<"The resource already exists. INVALID OPTION."<<endl;
            system("pause");
            }
            break;
        case 3:
            cout<<"Type the name: ";
            cin>>_name;
            cout<<"Type the status: ";
            cin>>_status;
            cout<<"Type the ID: ";
            cin>>_ID;
            cout<<"Type the maximum number of seats: ";
            cin>>_maxSeats;
            cout<<"Type the ID of the Speaker: ";
            cin>>_SpeakerID;
            res=listres->ResourcesOnList(_ID); //Checks if the resource ID is already on the list
            if(res==NULL){
                int position=((listres->GetNum_cour()+listres->GetNum_fdp()+listres->GetNum_sem())+2);
                listres->InsertNodeSelPosition(new Seminar(_name,_status,_ID,_maxSeats,_SpeakerID),position);//Adds the resource to the list
                listres->SetNum_sem((listres->GetNum_sem()+1));
                system("pause");
            }else{
                cout<<"\n";
                cout<<"The resource already exists. INVALID OPTION."<<endl;
            system("pause");
            }
        }
    }while(op!=4);


}
int Administrator::DeleteResource(){
    int op=1;//Gets the number typed by the user
    string _ID;
    Resource *res;
    do{
        system ("cls");
        if(cin.fail()){
            cin.clear();
            cin.ignore(1024, '\n'); //Cleaning cin. from 1024 to NUll
            cout<<" Only numerical values"<<endl;
        };
        if (op!=1&&op!=2&&op!=3&&op!=4){
            cout<<"Select a possible option"<<endl;
            cout<<"\n";
        };
        cout<<"--------DELETE RESOURCE---------"<<endl;
        cout<<listres->toString();
        cout<<"1). Delete Course"<<endl;
        cout<<"2). Delete FDP"<<endl;
        cout<<"3). Delete Seminar"<<endl;
        cout<<"4). Back"<<endl;
        cout<<"Type the number of the option"<<endl;
        cin>>op;
        switch (op) {
        case 1:
            cout<<"Please, type the ID of the course you want to delete."<<endl;
            cin>>_ID;
            res=listres->DeleteResource(_ID);
            if (res!=NULL){
                delete res;
                cout<<"The course was deleted succesfuly."<<endl;
                listres->SetNum_cour(listres->GetNum_cour()-1);
                system("pause");
            }else{
                cout<<"The resource does not exists."<<endl;
                system("pause");
            }
            break;
        case 2:
            cout<<"Please, type the ID of the FDP you want to delete."<<endl;
            cin>>_ID;
            res=listres->DeleteResource(_ID);
            if (res!=NULL){
                delete res;
                cout<<"The FDP was deleted succesfuly."<<endl;
                listres->SetNum_fdp(listres->GetNum_fdp()-1);
                system("pause");
            }else{
                cout<<"The resource does not exists."<<endl;
                system("pause");
            }
            break;
        case 3:
            cout<<"Please, type the ID of the seminar you want to delete."<<endl;
            cin>>_ID;
            res=listres->DeleteResource(_ID);
            if (res!=NULL){
                delete res;
                cout<<"The seminar was deleted succesfuly."<<endl;
                listres->SetNum_sem(listres->GetNum_sem()-1);
                system("pause");
            }else{
                cout<<"The resource does not exists."<<endl;
                system("pause");
            }
            break;
        }
    }while(op!=4);
    return op;

}
void Administrator::DisplayResources(){
    system("cls");
    cout<<"------RESOURCES-------"<<endl;
    cout<<listres->toString()<<endl;
    system("pause");
}
void Administrator::ModifyResource(){
    system("cls");
       Resource *aux;
       cout<<"-------MODIFY RESOURCE-------"<<endl;
       string _ID;
       cout<<listres->toString();
       cout<<"Type the ID of the resource you want to modify: "<<endl;
       cin>>_ID;
       aux=listres->ResourcesOnList(_ID);//Checks if the resource is on the list
       if(aux!=NULL){
          aux->ModifyResource();
       }else{
           cout<<"The resource does not exist"<<endl;
           system("pause");
       }

}

void Administrator::DisplayUsers(){
    system("cls");
    cout<<"------USERS-------"<<endl;
    cout<<listusers->toString()<<endl;
    system("pause");
}

void Administrator::CreateUser(){
    string _name,_IDCode;
    int op=1;
    User *user;
    do{
        system("cls");
        if(cin.fail()){
            cin.clear();
            cin.ignore(1024, '\n'); //Cleaning cin. from 1024 to NUll
            cout<<" Only numerical values"<<endl;
        }
        if (op!=1&&op!=2&&op!=3&&op!=4){
            cout<<"Select a possible option"<<endl;
            cout<<"\n";
        }

        cout<<"-----------USERS--------------"<<endl;
        cout<<"1). Student"<<endl;
        cout<<"2). Professor"<<endl;
        cout<<"3). Administrator"<<endl;
        cout<<"4). Back"<<endl;
        cout<<"Type the number of the option"<<endl;
        cin>>op;
        switch (op) {
        case 1:
            cout<<"Type the name: ";
            cin>>_name;
            cout<<"Type the SIN: ";
            cin>>_IDCode;
            user=listusers->UsersOnList(_IDCode); //Checks if the resource ID is already on the list
            if(user==NULL){
                listusers->InsertNodeSelPosition(new Student(_name,_IDCode),listusers->GetNum_stu());
                listusers->SetNum_stu((listusers->GetNum_stu()+1));
                 system("pause");

            }else{
                cout<<"\n";
                cout<<"The user already exists. INVALID OPTION."<<endl;
            system("pause");
            }
            break;
        case 2:
            cout<<"Type the name: ";
            cin>>_name;
            cout<<"Type the ID: ";
            cin>>_IDCode;
            user=listusers->UsersOnList(_IDCode); //Checks if the resource ID is already on the list
            if(user==NULL){
                int position=((listusers->GetNum_stu()+listusers->GetNum_prof())+1);
                listusers->InsertNodeSelPosition(new Professor(_name,_IDCode),position);
                listusers->SetNum_prof((listusers->GetNum_prof()+1));
                system("pause");
            }else{
                cout<<"\n";
                cout<<"The user already exists. INVALID OPTION."<<endl;
            system("pause");
            }
            break;
        case 3:
            cout<<"Type the name: ";
            cin>>_name;
            cout<<"Type the ID: ";
            cin>>_IDCode;
            user=listusers->UsersOnList(_IDCode); //Checks if the resource ID is already on the list
            if(user==NULL){
                int position=((listusers->GetNum_stu()+listusers->GetNum_prof()+listusers->GetNum_admin())+2);
                listusers->InsertNodeSelPosition(new Administrator(_name,_IDCode),position);//Adds the resource to the list
                listusers->SetNum_admin((listusers->GetNum_admin()+1));
                system("pause");
            }else{
                cout<<"\n";
                cout<<"The user already exists. INVALID OPTION."<<endl;
            system("pause");
            }
        }
    }while(op!=4);


}
void Administrator::ModifyUsers(){
    system("cls");
       User *aux;
       cout<<"-------MODIFY USER-------"<<endl;
       string _IDCode;
       cout<<listusers->toString();
       cout<<"Type the ID of the user you want to modify: "<<endl;
       cin>>_IDCode;
       aux=listusers->UsersOnList(_IDCode);//Checks if the user is on the list
       if(aux!=NULL){
          aux->ModifyUser();
       }else{
           cout<<"The user does not exist"<<endl;
           system("pause");
       }

}
int Administrator::DeleteUser(){
    int op=1;//Gets the number typed by the user
    string _IDCode;
    User *user;
    do{
        system ("cls");
        if(cin.fail()){
            cin.clear();
            cin.ignore(1024, '\n'); //Cleaning cin. from 1024 to NUll
            cout<<" Only numerical values"<<endl;
        };
        if (op!=1&&op!=2&&op!=3&&op!=4){
            cout<<"Select a possible option"<<endl;
            cout<<"\n";
        };
        cout<<"--------DELETE USER---------"<<endl;
        cout<<listusers->toString();
        cout<<"1). Delete Student"<<endl;
        cout<<"2). Delete Professor"<<endl;
        cout<<"3). Delete Administrator"<<endl;
        cout<<"4). Back"<<endl;
        cout<<"Type the number of the option"<<endl;
        cin>>op;
        switch (op) {
        case 1:
            cout<<"Please, type the ID of the student you want to delete."<<endl;
            cin>>_IDCode;
            user=listusers->DeleteUser(_IDCode);
            if (user!=NULL){
                delete user;
                cout<<"The student was deleted succesfuly."<<endl;
                listusers->SetNum_stu(listusers->GetNum_stu()-1);
                system("pause");
            }else{
                cout<<"The resource does not exists."<<endl;
                system("pause");
            }
            break;
        case 2:
            cout<<"Please, type the ID of the professor you want to delete."<<endl;
            cin>>_IDCode;
            user=listusers->DeleteUser(_IDCode);
            if (user!=NULL){
                delete user;
                cout<<"The professor was deleted succesfuly."<<endl;
                listusers->SetNum_prof(listusers->GetNum_prof()-1);
                system("pause");
            }else{
                cout<<"The resource does not exists."<<endl;
                system("pause");
            }
            break;
        case 3:
            cout<<"Please, type the ID of the administrator you want to delete."<<endl;
            cin>>_IDCode;
            user=listusers->DeleteUser(_IDCode);
            if (user!=NULL){
                delete user;
                cout<<"The administrator was deleted succesfuly."<<endl;
                listusers->SetNum_admin(listusers->GetNum_admin()-1);
                system("pause");
            }else{
                cout<<"The resource does not exists."<<endl;
                system("pause");
            }
            break;
        }
    }while(op!=4);
    return op;
}
