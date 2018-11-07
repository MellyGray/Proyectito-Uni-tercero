#include "listares.h"


Listares::Listares()
{
    actual= NULL;
};
void Listares::selectresource(Resource *_res){
    actual = new Nodores(_res, actual);
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
    ofstream writte("Resources.txt", ios::out);
    while (get!=NULL){
        res= get->Getresource();
        res->datasaving(writte);
        get= get->Getnext();
}
    writte.close();
};
void Listares::chargeresource(){
    ifstream read("Resources.txt", ios::in);
    Resource *res;
    Resource aux;
    res=aux.readTxt(read);
    while(!read.eof()){
        selectresource(res);//creo que hay que poner este no so sure
        res=aux.readTxt(read);
    }
    read.close();
}
