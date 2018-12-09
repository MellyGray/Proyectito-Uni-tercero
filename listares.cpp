#include "listares.h"


Listares::Listares()
{
    actual= NULL;
}
void Listares::selectresource(Resource *res){
    actual = new Nodores(res, actual);
}

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
}
Listares::~Listares(){
    Nodores *get=actual;
    Nodores *aux;
    while (get!=NULL){
        aux=get->Getnext();
        delete get;
        get=aux;
    }
    actual=NULL;
}
string Listares::toStringList(){
    stringstream s;
    Nodores *get=actual;
    Resource *res;
    while (get!= NULL){
        res= get->Getresource();
        s<<res->toStringList()<<endl;//Tostring de listas de usuarios en las resources
        get= get->Getnext();
    }
    return s.str();
}
void Listares::keepresource(){
    Nodores *get=actual, *aux =actual;
    int position_sem=((num_cour+num_fdp)+2);
    Resource *res;
    ofstream write("Resources.txt", ios::out);
    write<<num_cour<<endl;
    write<<num_fdp<<endl;
    write<<num_sem<<endl;
    for(int i=0;i<position_sem;i++){
        get= get->Getnext();
}
    for(int j=0;j<(num_sem+1);j++){
        res= get->Getresource();
        res->datasaving(write);
        get=get->Getnext();
    }
    get=aux;
    for(int k=0;k<(num_cour+1);k++){
        get= get->Getnext();
}
    for(int l=0;l<(num_fdp+1);l++){
        res= get->Getresource();
        res->datasaving(write);
        get=get->Getnext();
    }
    get=aux;
    for(int h=0;h<(num_cour+1);h++){
        res= get->Getresource();
        res->datasaving(write);
        get=get->Getnext();
    }
    write.close();
}
void Listares::chargeresource(){
    ifstream read("Resources.txt", ios::in);
    Course cour;
    FDP fdp;
    Seminar sem;
    Resource *res;
    read>>num_cour;
    read>>num_fdp;
    read>>num_sem;
    res=&sem;
    res=sem.readTxt(read);
        for (int k=0;k<num_sem;k++)
        {
                selectresource(res);
                res=sem.readTxt(read);
            }
        selectresource(res);
    res=&fdp;
    res=fdp.readTxt(read);
        for (int j=0;j<num_fdp;j++)
        {
                    selectresource(res);
                    res=fdp.readTxt(read);
                }
        selectresource(res);

    res=&cour;
    res=cour.readTxt(read);
    for (int i=0;i<num_cour;i++){
                    selectresource(res);
                    res=cour.readTxt(read);
               }
        selectresource(res);

    read.close();
}
void Listares::PrintResourcesOnList(string _degree){//Printea los nombres de los resources en la lista
    Resource *aux;
    string saux="NONE";
    Nodores *get=actual;
    while(get!=NULL){
    aux=get->Getresource();
    if((aux->GetDegree()==_degree)|(aux->GetDegree()==saux)){
    cout<<aux->GetName()<<endl;
    get=get->Getnext();
    }else{
        get=get->Getnext();
    }}
}
Resource *Listares::UserOnList(string _id){//Printea los nombres de los resources en los que el user esta
    Resource *aux;
    Nodores *get=actual;
    while(get!=NULL){
        aux=get->Getresource();
        aux->searchinlist(_id);
        get=get->Getnext();
    }
    return NULL;
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
Resource *Listares::EnrollResource(string _name, string _id){//para estudiante enrolllar en resource.
    Resource *aux;
    bool check;
    Nodores *get=actual;
   while (get!=NULL){
        aux=get->Getresource();
        if(aux->GetName()==_name){//FUNCIÓN CHEQUEO VIRTUAL
            check=aux->checking();
           if (check==true){
            aux->IntroduceUserinResource(_id);
            cout<<"Enroll succeded";
           return NULL;
            }
           if (check==false){
               cout<<"Enroll is not posible";
           }


        }
        get=get->Getnext();
    }
   cout<<"Incorrect name, try again"<<endl;
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
void Listares::InsertNodeSelPosition(Resource *res,int position){
    Nodores *get=actual;
    for(int i=0;i<position;i++){
        get=get->Getnext();
    }
     get->setnext(new Nodores(res,get->Getnext()));
}
/*string Listares::toStringCourses(){
    stringstream s;
    Nodores *get=actual;
    Resource *res;
    for(int h=0;h<(num_cour+1);h++){
        res= get->Getresource();
        s<<res->toString()<<endl;
        get=get->Getnext();
    }
    return s.str();
};
*/
