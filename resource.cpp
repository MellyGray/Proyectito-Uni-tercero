#include "resource.h"
#include <iostream>

using namespace std;

Resource::Resource()
{
    name="";
    status="";
    ID="";
    num_users=0;
    lirray=NULL;
}
Resource::Resource(string _name, string _status, string _ID,int _num_users)
{
    name=_name;
    status=_status;
    ID=_ID;
    num_users=_num_users;
    lirray=new string[num_users];
}

Resource::~Resource(){}

string Resource::getlirrayvalue(int x){
    string s;
    lirray[x]=s;
    return s;
}

void Resource::IntroduceUserinResource(string _id){//Meter Id en la lista.
    string aux[num_users];
    for(int i=0; i<num_users;i++){
        aux[i]=lirray[i];
    }
    num_users=num_users+1;
    lirray=new string[num_users];
    int t=num_users-1;
    for (int k=0;k<t;k++){
        lirray[k]=aux[k];
    }
    lirray[t]=_id;
}

void Resource::DeleteUserinResource(string _id){
    string aux[num_users-1];
    int k=0;
    int ok=0;
    for(int i=0; i<num_users;i++){
        if(lirray[i]!=_id){
           aux[k]=lirray[i];
           k++;
        }if (lirray[i]==_id){
            ok=1;
        }
}
    if(ok==1){
        num_users=num_users-1;
        lirray=new string[num_users];
        for(int t=0; t<num_users;t++){
            lirray[t]=aux[t];
}
    }if(ok==0){
        cout<<"ERROR 402"<<endl;
        cout<<"We are in program update, SERVER DOWN, try later"<<endl;
    }
}

