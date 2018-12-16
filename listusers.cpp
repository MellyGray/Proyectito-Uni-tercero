#include "listusers.h"
#include "administrator.h"
#include "string.h"
#include <stdio.h>

ListUsers::ListUsers()
{
    actual= NULL;
};
void ListUsers::AddUser(User *user){
    actual = new NodoUsers(user, actual);
};
string ListUsers::toString(){
    stringstream s;
    NodoUsers *get=actual;
    User *user;
    while (get!= NULL){
        user= get->GetUser();
        s<<user->toString()<<endl;
        get= get->Getnext();
    }
    return s.str();
};
ListUsers::~ListUsers(){
    NodoUsers *get=actual;
    NodoUsers *aux;
    while (get!=NULL){
        aux=get->Getnext();
        delete get;
        get=aux;
    }
    actual=NULL;
};
void ListUsers::KeepUsers(){
    NodoUsers *get=actual, *aux =actual;
    int position_admin=((num_stu+num_prof)+2);
    User *user;
    ofstream write("Users.txt", ios::out);
    write<<num_stu<<endl;
    write<<num_prof<<endl;
    write<<num_admin<<endl;
    for(int i=0;i<position_admin;i++){
        get= get->Getnext();
}
    for(int j=0;j<(num_admin+1);j++){
        user= get->GetUser();
        user->datasaving(write);
        get=get->Getnext();
    }
    get=aux;
    for(int k=0;k<(num_stu+1);k++){
        get= get->Getnext();
}
    for(int l=0;l<(num_prof+1);l++){
        user= get->GetUser();
        user->datasaving(write);
        get=get->Getnext();
    }
    get=aux;
    for(int h=0;h<(num_stu+1);h++){
        user= get->GetUser();
        user->datasaving(write);
        get=get->Getnext();
    }
    write.close();
};
void ListUsers::ChargeUsers(){
    ifstream read("Users.txt", ios::in);
    Student stu;
    Professor prof;
    Administrator admin;
    string nothing;
    User *user;
    read>>num_stu;
    read>>num_prof;
    read>>num_admin;
    user=&admin;
    user=admin.readTxt(read);
        for (int k=0;k<num_admin;k++)
        {
                AddUser(user);
                user=admin.readTxt(read);
            }
        AddUser(user);
    user=&prof;
    user=prof.readTxt(read);
        for (int j=0;j<num_prof;j++)
        {
                    AddUser(user);
                    user=prof.readTxt(read);
                }
        AddUser(user);

    user=&stu;
    user=stu.readTxt(read);
    for (int i=0;i<num_stu;i++){
                    AddUser(user);
                    user=stu.readTxt(read);
               }
        AddUser(user);

    read.close();
}
User *ListUsers::UsersOnList(string _IDCode){
    User *aux;
    NodoUsers *get=actual;
    while (get!=NULL){
        aux=get->GetUser();
        if(aux->GetIDCode()==_IDCode){
            return aux;
        }
        get=get->Getnext();
    }
    return NULL;
}
User *ListUsers::Logging(string _IDCode,string _password){
    User *aux;
    NodoUsers *get=actual;
    string s,p;
    int x, ok,i;
    while (get!=NULL){
        //ok=1;
        aux=get->GetUser();
        //s=aux->GetIDCode();
       // p=aux->GetPassword();
       // x=_IDCode.size();
        //i=_password.size();
        /*for (int k=0;k<x&ok==1;k++){
            ok=0;
            if(s[k]==_IDCode[k]){
                ok=1;
            }
        }
        if(ok==0){
            get=get->Getnext();
        }else{
            for (int t=0;t<i&ok==1;t++){
                ok=0;
                if(p[t]==_password[t]){
                    ok=1;
                }
            }
            if(ok==1){
                return aux;
            }else {
                get=get->Getnext();
            }
        }*/
        if((aux->GetIDCode()==_IDCode)&(aux->GetPassword()==_password)){
            return aux;
        }
        get=get->Getnext();
    }
    return NULL;
}
User *ListUsers::DeleteUser(string _IDCode){
    NodoUsers *get=actual;
    NodoUsers *aux=NULL;
    bool found=false;
    User *user;
    while(get!=NULL && !found){
        user=get->GetUser();
        if(user->GetIDCode()==_IDCode){
            found=true;
            DeleteNodoUser(aux,get);
            return user;
        }
        aux=get;
        get=get->Getnext();
    }
    return NULL;
}
void ListUsers::DeleteNodoUser(NodoUsers *aux,NodoUsers *get){
    if (aux==NULL){//If the user to delete is at the first node.
        actual=get->Getnext();
    }else{
        aux->SetNext(get->Getnext());
    }
    delete get;
}
void ListUsers::InsertNodeSelPosition(User *user,int position){
    NodoUsers *get=actual;
    for(int i=0;i<position;i++){
        get=get->Getnext();
    }
     get->SetNext(new NodoUsers(user,get->Getnext()));
}

