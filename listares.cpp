#include "listares.h"


Listares::Listares()
{
    actual= NULL;
};
void Listares::selectresource(Resource *res){
    actual = new Nodores(res, actual);
};
string Listares::toString(){
    stringstream s;
    Nodores *get=actual;
    Resource *res;
    while (get!= NULL){
        res= get->Getresource();
        s<<res->toString()<<endl;
        get= get->Getnext();
    }
    return s.str();
};
Listares::~Listares(){
    Nodores *get=actual;
    Nodores *aux;
    while (get!=NULL){
        aux=get->Getnext();
        delete get;
        get=aux;
    }
    actual=NULL;
};
void Listares::keepresource(){
    Nodores *get=actual;
    Resource *res;
    ofstream write("Resources.txt", ios::out);
    while (get!=NULL){
        res= get->Getresource();
        res->datasaving(write);
        get= get->Getnext();
}
    write.close();
};
void Listares::chargeresource(){
    ifstream read("Resources.txt", ios::in);
    Resource *res;
    Resource aux;
    res=aux.readTxt(read);
    while(!read.eof()){
        selectresource(res);
        res=aux.readTxt(read);
    }
    read.close();
}
Resource *Listares::ResourcesOnList(string _ID){
    Resource *aux;
    Nodores *get=actual;
    while (get!=NULL){
        aux=get->Getresource();
        if(aux->GetID()==_ID){
            return aux;
        }
        get=get->Getnext();
    }
    return NULL;
}
Resource *Listares::DeleteResource(string _ID){
    Nodores *get=actual;
    Nodores *aux=NULL;
    bool found=false;
    Resource *res;
    while(get!=NULL && !found){
        res=get->Getresource();
        if(res->GetID()==_ID){
            found=true;
            DeleteNodores(aux,get);
            return res;
        }
        aux=get;
        get=get->Getnext();
    }
    return NULL;
}
void Listares::DeleteNodores(Nodores *aux,Nodores *get){
    if (aux==NULL){//If the resource to delete is at the first node.
        actual=get->Getnext();
    }else{
        aux->setnext(get->Getnext());
    }
    delete get;
}
