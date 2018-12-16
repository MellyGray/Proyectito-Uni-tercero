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
        cout<<"\033[2J\033[1;1H";
        if(cin.fail()){
            cin.clear();
            cin.ignore(1024, '\n'); //Cleaning cin. from 1024 to NUll
            cout<<" Only numerical values"<<endl;
        };
        if (op!=1&&op!=2&&op!=3){
            cout<<"Select a possible option"<<endl;
            cout<<"\n";
        };
        cout<<"--------WELCOME ADMINISTRATOR "<<name<<"!---------"<<endl;
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
        cout<<"\033[2J\033[1;1H";
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
        case 0:
            cout << "Press enter to continue ..."<<endl;
            cin.get();
            DisplayResources();
            cout << "Press enter to continue ..."<<endl;
            cin.get();
            break;
        case 1:
            cout << "Press enter to continue ..."<<endl;
            cin.get();
            CreateResource();
            cout << "Press enter to continue ..."<<endl;
            cin.get();
            break;
        case 2:
            cout << "Press enter to continue ..."<<endl;
            cin.get();
            ModifyResource();
            cout << "Press enter to continue ..."<<endl;
            cin.get();
            break;
        case 3:
            cout << "Press enter to continue ..."<<endl;
            cin.get();
            DeleteResource();
            cout << "Press enter to continue ..."<<endl;
            cin.get();
            break;
        }
    }while(op!=4);
    return op;
};
int Administrator::MenuUsers(){
    int op=1;//Gets the number typed by the user
    do{
        cout<<"\033[2J\033[1;1H";
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
        case 0:
            cout << "Press enter to continue ..."<<endl;
            cin.get();
            DisplayUsers();
            cout << "Press enter to continue ..."<<endl;
            cin.get();
            break;
        case 1:
            cout << "Press enter to continue ..."<<endl;
            cin.get();
            CreateUser();
            cout << "Press enter to continue ..."<<endl;
            cin.get();
            break;
        case 2:
            cout << "Press enter to continue ..."<<endl;
            cin.get();
            ModifyUsers();
            cout << "Press enter to continue ..."<<endl;
            cin.get();
            break;
        case 3:
            cout << "Press enter to continue ..."<<endl;
            cin.get();
            DeleteUser();
            cout << "Press enter to continue ..."<<endl;
            cin.get();
            break;
        }
    }while(op!=4);
    return op;
};

void Administrator::CreateResource(){
    string _name,_status,_ID,_professor1id,_professor2id,_idstudent,_nametutor,_SpeakerID,_degree,s,_cotutor,_coordinator,_date;
    char a,c;
    int _credits,op=1,_maxSeats,_num_users,b;
    Resource *res,*aux;
    User *user=NULL;
    do{
       cout<<"\033[2J\033[1;1H";
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
            cout<<"Type the ID: ";
            cin>>_ID;
            res=listres->ResourcesOnList(_ID); //Checks if the resource ID is already on the list
            if(res==NULL){
                cout<<"Type the name: ";
                cin>>_name;
                cout<<"Type the degree: ";
                cin>>_degree;
                cout<<"Select the status: "<<endl;
                cout<<"1.-Created"<<endl;
                cout<<"2.-In progress"<<endl;
                cout<<"3.-Completed"<<endl;
                cin>>b;
                switch (b) {
                case 1: _status="created";
                    break;
                case 2: _status="in_progress";
                    break;
                case 3: _status="completed";
                    break;
                }
                cout<<"Type the number of credits: ";
                cin>>_credits;
                do{
                    cout<<"Type the Professor 1 ID: ";
                    cin>>_professor1id;
                    user=listusers->UsersOnList(_professor1id);
                    if(user==NULL){
                        cout<<"The professor does not exist."<<endl<<endl;
                    }
                }while(user==NULL);
                user=NULL;
                do{
                 cout<<"Type the Professor 2 ID: ";
                 cin>>_professor2id;
                user=listusers->UsersOnList(_professor2id);
                if(user==NULL){
                    cout<<"The professor does not exist."<<endl<<endl;
                }
                }while(user==NULL);
                 user=NULL;
                cout<<"Type the number of students enrolled in the course: ";
                cin>>_num_users;
                aux=new Course(_name,_status,_ID,_num_users,_credits,_professor1id,_professor2id,_degree);
                listres->InsertNodeSelPosition(aux,listres->GetNum_cour());
                listres->SetNum_cour((listres->GetNum_cour()+1));
                for(int i=_num_users-1;i>=0;i--){
                    do{
                     cout<<"Type the ID of the "<<(i+1)<<" student: ";
                     cin>>s;
                    user=listusers->UsersOnList(s);
                    if(user==NULL){
                        cout<<"The student does not exist."<<endl<<endl;
                    }
                    }while(user==NULL);
                     user=NULL;
                    aux->Setlirrayvalue(i,s);
               }
                cout<<"The course was created successfuly."<<endl<<endl;


            }else{
                cout<<"\n";
                cout<<"The resource ID already exists. INVALID OPTION."<<endl<<endl;
            }
            cin.get();
            cout << "Press enter to continue ..."<<endl;
            cin.get();
            break;
        case 2:
            cout<<"Type the ID: ";
            cin>>_ID;
            res=listres->ResourcesOnList(_ID); //Checks if the resource ID is already on the list
            if(res==NULL){
            cout<<"Type the name: ";
            cin>>_name;
            cout<<"Type the degree: ";
            cin>>_degree;
            cout<<"Select the status: "<<endl;
            cout<<"1.-Created"<<endl;
            cout<<"2.-In progress"<<endl;
            cout<<"3.-Completed"<<endl;
            cin>>b;
            switch (b) {
            case 1: _status="created";
                break;
            case 2: _status="in_progress";
                break;
            case 3: _status="completed";
                break;
            }

            do{
                cout<<"Type the ID of the tutor: ";
                cin>>_nametutor;
            user=listusers->UsersOnList(_nametutor);
            if(user==NULL){
                cout<<"The professor does not exist."<<endl<<endl;
            }
            }while(user==NULL);
            user=NULL;
            cout<<"Do you want to assig a co-tutor to this FDP? (Y/N)"<<endl;
            cin>>c;
            if(c==('y'|'Y')){
                do{
                    cout<<"Type the co-tutor ID: ";
                    cin>>_cotutor;
                user=listusers->UsersOnList(_cotutor);
                if(user==NULL){
                    cout<<"The professor does not exist."<<endl<<endl;
                }
                }while(user==NULL);
                user=NULL;

            }else{
                _cotutor="NONE";
            }
            cout<<"Do you want to assig a student to this FDP? (Y/N)"<<endl;
            cin>>a;
            if(a==('y'|'Y')){
                do{
                    cout<<"Type the student SIN: ";
                    cin>>_idstudent;
                user=listusers->UsersOnList(_idstudent);
                if(user==NULL){
                    cout<<"The student does not exist."<<endl<<endl;
                }
                }while(user==NULL);
                user=NULL;

            }else{
                _idstudent="NONE";
            }
                int position=((listres->GetNum_cour()+listres->GetNum_fdp())+1);
                _num_users=0;
                listres->InsertNodeSelPosition(new FDP(_name,_status,_ID,_num_users,_idstudent,_nametutor,_degree,_cotutor),position);
                listres->SetNum_fdp((listres->GetNum_fdp()+1));
                cout<<"The FDP was created successfuly."<<endl<<endl;
            }else{
                cout<<"\n";
                cout<<"The resource ID already exists. INVALID OPTION."<<endl<<endl;
            }
            cin.get();
            cout << "Press enter to continue ..."<<endl;
            cin.get();
            break;
        case 3:
            cout<<"Type the ID: ";
            cin>>_ID;
            res=listres->ResourcesOnList(_ID); //Checks if the resource ID is already on the list
            if(res==NULL){
            cout<<"Type the name: ";
            cin>>_name;
            cout<<"Select the status: "<<endl;
            cout<<"1.-Created"<<endl;
            cout<<"2.-In progress"<<endl;
            cout<<"3.-Completed"<<endl;
            cin>>b;
            switch (b) {
            case 1: _status="created";
                break;
            case 2: _status="in_progress";
                break;
            case 3: _status="completed";
                break;
            }
            cout<<"Type the date of the seminar (dd-mm-year): ";
            cin>>_date;
            cout<<"Type the maximum number of seats: ";
            cin>>_maxSeats;
            do{
                cout<<"Type the ID of the speaker: ";
                cin>>_SpeakerID;
            user=listusers->UsersOnList(_SpeakerID);
            if(user==NULL){
                cout<<"The speaker does not exist."<<endl<<endl;
            }
            }while(user==NULL);
            user=NULL;
            do{
                cout<<"Type the ID of the coordinator: ";
                cin>>_coordinator;
            user=listusers->UsersOnList(_coordinator);
            if(user==NULL){
                cout<<"The professor does not exist."<<endl<<endl;
            }
            }while(user==NULL);
            user=NULL;
            cout<<"Type de number of students enrolled in the seminar:";
            cin>>_num_users;
                int position=((listres->GetNum_cour()+listres->GetNum_fdp()+listres->GetNum_sem())+2);
                aux=new Seminar(_name,_status,_ID,_num_users,_maxSeats,_SpeakerID,_coordinator,_date);
                listres->InsertNodeSelPosition(aux,position);//Adds the resource to the list
                listres->SetNum_sem((listres->GetNum_sem()+1));
                for(int i=_num_users-1;i>=0;i--){
                    do{
                     cout<<"Type the ID of the "<<(i+1)<<" student: ";
                     cin>>s;
                    user=listusers->UsersOnList(s);
                    if(user==NULL){
                        cout<<"The student does not exist."<<endl<<endl;
                    }
                    }while(user==NULL);
                     user=NULL;
                    aux->Setlirrayvalue(i,s);
               }
                cout<<"The seminar was created successfuly."<<endl<<endl;

            }else{
                cout<<"\n";
                cout<<"The resource ID already exists. INVALID OPTION."<<endl<<endl;
            }
            cin.get();
            cout << "Press enter to continue ..."<<endl;
            cin.get();
           break;
        }
    }while(op!=4);


}
int Administrator::DeleteResource(){
    int op=1;//Gets the number typed by the user
    string _ID;
    Resource *res;
    do{
        cout<<"\033[2J\033[1;1H";
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
            cout<<"Please, type the ID of the course you want to delete."<<endl<<endl;
            cin>>_ID;
            res=listres->DeleteResource(_ID);
            if (res!=NULL){
                delete res;
                cout<<"The course was deleted succesfuly."<<endl<<endl;
                listres->SetNum_cour(listres->GetNum_cour()-1);
            }else{
                cout<<"The resource does not exists."<<endl<<endl;
            }
            cin.get();
            cout << "Press enter to continue ..."<<endl<<endl;
            cin.get();
            break;
        case 2:
            cout<<"Please, type the ID of the FDP you want to delete."<<endl<<endl;
            cin>>_ID;
            res=listres->DeleteResource(_ID);
            if (res!=NULL){
                delete res;
                cout<<"The FDP was deleted succesfuly."<<endl<<endl;
                listres->SetNum_fdp(listres->GetNum_fdp()-1);
            }else{
                cout<<"The resource does not exists."<<endl<<endl;
            }
            cin.get();
            cout << "Press enter to continue ..."<<endl<<endl;
            cin.get();
            break;
        case 3:
            cout<<"Please, type the ID of the seminar you want to delete."<<endl<<endl;
            cin>>_ID;
            res=listres->DeleteResource(_ID);
            if (res!=NULL){
                delete res;
                cout<<"The seminar was deleted succesfuly."<<endl<<endl;
                listres->SetNum_sem(listres->GetNum_sem()-1);
            }else{
                cout<<"The resource does not exists."<<endl<<endl;
            }
            cin.get();
            cout << "Press enter to continue ..."<<endl<<endl;
            cin.get();
            break;
        }
    }while(op!=4);
    return op;

}
void Administrator::DisplayResources(){
    cout<<"\033[2J\033[1;1H";
    cout<<"------RESOURCES-------"<<endl;
    cout<<listres->toString()<<endl;
}
void Administrator::ModifyResource(){
    cout<<"\033[2J\033[1;1H";
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
           cout<<"The resource does not exist"<<endl<<endl;
       }

}

void Administrator::DisplayUsers(){
    cout<<"\033[2J\033[1;1H";
    cout<<"------USERS-------"<<endl;
    cout<<listusers->toString()<<endl;
}

void Administrator::CreateUser(){
    string _name,_IDCode,_degree;
    int op=1;
    User *user;
    do{
        cout<<"\033[2J\033[1;1H";
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
            cout<<"Type the degree: ";
            cin>>_degree;
            cout<<"Type the SIN: ";
            cin>>_IDCode;
            user=listusers->UsersOnList(_IDCode); //Checks if the resource ID is already on the list
            if(user==NULL){
                listusers->InsertNodeSelPosition(new Student(_name,_IDCode,_degree),listusers->GetNum_stu());
                listusers->SetNum_stu((listusers->GetNum_stu()+1));
                cout<<"The Student has been created"<<endl<<endl;
            }else{
                cout<<"\n";
                cout<<"The user already exists. INVALID OPTION."<<endl<<endl;

            }
            cin.get();
            cout << "Press enter to continue ..."<<endl<<endl;
            cin.get();

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
                cout<<"The Professor has been created"<<endl<<endl;
            }else{
                cout<<"\n";
                cout<<"The user already exists. INVALID OPTION."<<endl<<endl;

            }
            cin.get();
            cout << "Press enter to continue ..."<<endl;
            cin.get();
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
                cout<<"The Admin0 has been created"<<endl<<endl;

            }else{
                cout<<"\n";
                cout<<"The user already exists. INVALID OPTION."<<endl<<endl;

            }
            cin.get();
            cout << "Press enter to continue ..."<<endl;
            cin.get();
        }
    }while(op!=4);


}
void Administrator::ModifyUsers(){
    cout<<"\033[2J\033[1;1H";
       User *aux;
       cout<<"-------MODIFY USER-------"<<endl;
       string _IDCode;
       cout<<listusers->toString();
       cout<<"Type the ID of the user you want to modify: "<<endl;
       cin>>_IDCode;
       aux=listusers->UsersOnList(_IDCode);//Checks if the user is on the list
       if(aux!=NULL){
          aux->ModifyUser();
          cout<<"Modification suceed"<<endl<<endl;
          cin.get();

       }else{
           cout<<"The user does not exist"<<endl<<endl;
           cin.get();

       }

}
int Administrator::DeleteUser(){
    int op=1;//Gets the number typed by the user
    string _IDCode;
    User *user;
    do{
        cout<<"\033[2J\033[1;1H";
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
                cout<<"The student was deleted succesfuly."<<endl<<endl;
                listusers->SetNum_stu(listusers->GetNum_stu()-1);
                cin.get();
                cout << "Press enter to continue ..."<<endl;
                cin.get();
            }else{
                cout<<"The resource does not exists."<<endl<<endl;
                cin.get();
                cout << "Press enter to continue ..."<<endl;
                cin.get();
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
                cin.get();
                cout << "Press enter to continue ..."<<endl;
                cin.get();
            }else{
                cout<<"The resource does not exists."<<endl<<endl;
                cin.get();
                cout << "Press enter to continue ..."<<endl;
                cin.get();
            }
            break;
        case 3:
            cout<<"Please, type the ID of the administrator you want to delete."<<endl;
            cin>>_IDCode;
            user=listusers->DeleteUser(_IDCode);
            if (user!=NULL){
                delete user;
                cout<<"The administrator was deleted succesfuly."<<endl<<endl;
                listusers->SetNum_admin(listusers->GetNum_admin()-1);
                cin.get();
                cout << "Press enter to continue ..."<<endl;
                cin.get();
            }else{
                cout<<"The resource does not exists."<<endl<<endl;
                cin.get();
                cout << "Press enter to continue ..."<<endl;
                cin.get();
            }
            break;
        }
    }while(op!=4);
    return op;
}
