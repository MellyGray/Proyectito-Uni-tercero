#include "course.h"
#include <iostream>
using namespace std;

Course::Course(){}

Course::Course(string _name, string _status, string _ID,int _num_users, int _credits,string _professor1id,string _professor2id, string _degree):Resource (_name,_status,_ID,_num_users)
{
    credits=_credits;
    professor1id=_professor1id;
    professor2id=_professor2id;
    degree=_degree;
};

Course::~Course()
{
    name="";
    status="";
    credits=0;
    professor1id="";
    professor2id="";
   }
string Course::toString(){
    stringstream s;
    s<< "Name____________"<<name<<endl;
    s<< "Degree__________"<<degree<<endl;
    s<< "ID______________"<<ID<<endl;
    s<< "Status__________"<< status<<endl;
    s<< "Credits_________"<<credits<<endl;
    s<< "Professor 1 ID__"<<professor1id<<endl;
    s<< "Professor 2 ID__"<<professor2id<<endl;
    return s.str();
}

string Course::toStringList(){
    stringstream s;
    s<<"Name-------------------"<<name<<endl;
    s<<"Number of students----"<<num_users<<endl;
    s<<"List of students:"<<endl;
    for(int i=0; i<num_users; i++){
        s<<lirray[i]<<endl;
    };
    return s.str();
}
void Course::datasaving( ofstream &write){
   write<<degree<<"\n";
   write<<professor2id<<"\n";
   write<<professor1id<<"\n";
   write<<credits<<"\n";
   write<<ID<<"\n";
   write<<status<<"\n";
   write<<name<<"\n";
   write<<num_users<<"\n";
   for(int i=num_users-1;i>=0;i--){
       write<<lirray[i]<<"\n";
   }


}

Course *Course::readTxt(ifstream &read){
    string _name, _status,_ID,_professor1id,_professor2id,_degree,nothing;
    int _credits,_num_users,i;
    read>>_degree;
    read>>_professor2id;
    read>>_professor1id;
    read>>_credits;
    read>>_ID;
    read>>_status;
    read>>_name;
    read>>_num_users;
    Course *c1=new Course(_name, _status,_ID,_num_users,_credits,_professor1id,_professor2id,_degree);
    for(i=_num_users-1;i>=0;i--){
        read>>c1->lirray[i];
        };
    return (c1);
}

void Course::ModifyResource(){
    int b;
    cout<<"Please, enter the new name for the course: ";
    cin>>name;
    cout<<"\n";
    cout<<"Please, Select the new status for the course: "<<endl;
    cout<<"1.-Created"<<endl;
    cout<<"2.-In progress"<<endl;
    cout<<"3.-Completed"<<endl;
    cin>>b;
    switch (b) {
    case 1: status="created";
        break;
    case 2: status="in_progress";
        break;
    case 3: status="completed";
        break;
    }
    cout<<"Please, enter the new degree for the course: ";
    cin>>degree;
    cout<<"\n";
    cout<<"Please, enter the new number of credits for the course: ";
    cin>>credits;
    cout<<"\n";
    cout<<"Please, enter the new professor 1 ID for the course: ";
    cin>>professor1id;
    cout<<"\n";
    cout<<"Please, enter the new professor 2 ID for the course: ";
    cin>>professor2id;
    cout<<"\n";
}
void Course::searchinlist(string _id, int x){
int t=x;
    int i=num_users-1;
    for(int k=0; k<=i;k++){
        if (lirray[k]==_id){
            cout<<name<<endl;
            cout<<ID<<endl;
            cout<<endl;
        }
    }
    if (professor1id==_id){
        cout<<name<<endl;
        cout<<ID<<endl;
        cout<<endl;
    }
    if (professor2id==_id){
        cout<<name<<endl;
        cout<<ID<<endl;
        cout<<endl;
    }
}
bool Course::checking(string _deg){
    if(degree==_deg){
    return true;
    }else{
        return false;
    }
}

void Course::IntroduceUserinResource(string _id){//Meter Id en la lista.
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

void Course::DeleteUserinResource(string _id){
    string aux[num_users-1];
    int k=0;
    int ok=0;
    cout<<"jbhll"<<endl;
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
        cout<<"Something worng happened, try again"<<endl;
    }
}
