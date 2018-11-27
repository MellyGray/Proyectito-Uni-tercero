#include "listares.h"


Listares::Listares()
{
    actual= NULL;
};
void Listares::selectresource(Resource *res){//Me vale
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

string Listares::toStringList(){//Nueva con toStringLista
    stringstream s;
    Nodores *get=actual;
    Resource *res;
    while (get!= NULL){
        res= get->Getresource();
        s<<res->toStringList()<<endl;//Tostring de listas
        get= get->Getnext();
    }
    return s.str();
};

Listares::~Listares(){//Me vale
    Nodores *get=actual;
    Nodores *aux;
    while (get!=NULL){
        aux=get->Getnext();
        delete get;
        get=aux;
    }
    actual=NULL;
};
//Necesitamos otra para la lista de lista
void Listares::keepresource(){//First seminars are writted on the top, we have the nums of each elements so we now where each elment is located,
    Nodores *get=actual, *aux =actual;//First in txt is the depest element in the list.
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
};
void Listares::keepsourcelist(){
    Nodores *get=actual, *aux=actual;
    int position_sem=((num_cour+num_fdp)+2);
    Resource *res;
    ofstream writel("Resourcelist.txt", ios::out);//Cambiar los write de los cursos fdp seminars
    writel<<num_cour<<endl;
    writel<<num_fdp<<endl;
    writel<<num_sem<<endl;
    for(int i=0;i<position_sem;i++){//Mirar que es lo que se guarda, si se guarda siempre lo mismo no hace falta na
        get= get->Getnext();
}
    for(int j=0;j<(num_sem+1);j++){
        res= get->Getresource();
        res->datasavinglist(writel);
        get=get->Getnext();
}
    get=aux;
    for(int k=0;k<(num_cour+1);k++){
        get= get->Getnext();
}
    for(int l=0;l<(num_fdp+1);l++){
        res= get->Getresource();
        res->datasavinglist(writel);
        get=get->Getnext();
    }
    get=aux;
    for(int h=0;h<(num_cour+1);h++){
        res= get->Getresource();
        res->datasavinglist(writel);
        get=get->Getnext();
    }
    writel.close();

}


void Listares::chargeresource(){
    ifstream read("Resources.txt", ios::in);
    Course cour_aux,cour;
    FDP fdp_aux,fdp;
    Seminar sem_aux,sem;
    Resource *res;
    read>>num_cour;
    read>>num_fdp;
    read>>num_sem;
    res=&sem; //Set type of memory
    res=sem_aux.readTxt(read);
        for (int k=0;k<num_sem;k++)
        {
                selectresource(res);
                res=sem_aux.readTxt(read);
            }
        selectresource(res);
    res=&fdp;//Set type of memory
    res=fdp_aux.readTxt(read);
        for (int j=0;j<num_fdp;j++)
        {
                    selectresource(res);
                    res=fdp_aux.readTxt(read);
                }
        selectresource(res);

    res=&cour;//Set type of memory
    res=cour_aux.readTxt(read);
    for (int i=0;i<num_cour;i++){
                    selectresource(res);
                    res=cour_aux.readTxt(read);
               }
        selectresource(res);

    read.close();
}
void Listares::chargeresourcelist(){
    ifstream readl("Resourceslist.txt", ios::in);
    Seminar sem_aux;
    Course cou_aux;
    FDP fdp_aux;
    Resource *res;
    readl>>num_cour;
    readl>>num_fdp;
    readl>>num_sem;
    res=&sem_aux;
    res=sem_aux.readTXTlist(readl);
    for (int k=0; k<num_sem;k++){
        selectresource(res);
        res=sem_aux.readTxt(readl);
    };
    res=&fdp_aux;
    res=fdp_aux.readTxtList(readl);
    for (int l=0; l<num_fdp; l++){
        selectresource(res);
        res=fdp_aux.readTxtList(readl);
    };
    res=&cou_aux;//Set type of memory
    res=cou_aux.readTxt(readl);
    for (int i=0;i<num_cour;i++){
                    selectresource(res);
                    res=cou_aux.readTxt(readl);
               }
        selectresource(res);

    readl.close();
}

void Listares::PrintResourcesOnList(){//Printea los nombres de los resources en la lista
    Resource *aux;
    Nodores *get=actual;
    while(get!=NULL){
    aux=get->Getresource();
    cout<<aux->GetName()<<endl;
    get=get->Getnext();
    }
}

Resource *Listares::UserOnList(string _id){//Printea los nombres de los resources en los que el user esta.Revisar por que la borre sin querer
    int position_sem=((num_cour+num_fdp)+2);
    Resource *aux;
    FDP fdp_aux;
    Nodores *get=actual, *naux=actual;
    for(int i=0;i<position_sem;i++){
        get=get->Getnext();
     }
    for(int j=0;j<(num_sem+1);j++){
        aux=get->Getresource();
        aux->searchinlist(_id);
        get=get->Getnext();
    }
    get=naux;
    aux=&fdp_aux;
    for(int k=0;k<(num_cour+1);k++){
        get= get->Getnext();
}
    for(int l=0;l<(num_fdp+1);l++){
        aux=get->Getresource();//Hacerla virtual como writting
        aux->searchinlist(_id);
        get=get->Getnext();
    }
    get=naux;
    for(int h=0;h<(num_cour+1);h++){
        aux=get->Getresource();
        aux->searchinlist(_id);
        get=get->Getnext();
    }
    actual=naux;//Restauración No hace falta creo
    return NULL;
}
Resource *Listares::ResourcesOnList(string _ID){//CREO QUE ME VALE,MIRAR
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

Resource *Listares::EnrollResource(string _name, string _id){//para estudiante enrolllar en resource.DIria que está terminao Hasta el nabo
    Resource *aux;
    bool check;
    Nodores *get=actual, *naux=actual;
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
                cout<<"Enroll is not posible"
            }
        }
        get=get->Getnext();
    }
   cout<<"Incorrect name, try again"<<endl;
   return NULL;
}


Resource *Listares::DeleteResource(string _ID){//NUEVA MELLY
    Nodores *get=actual;
    Nodores *aux=NULL;
    bool found=false;
    Resource *res;
    while(get!=NULL && !found){
        res=get->Getresource();         //El numero de recursos de list se cambia con el objeto externo que llama a la lista.
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
void Listares::DeleteNodores(Nodores *aux,Nodores *get){//NUEVA MELLY
    if (aux==NULL){//If the resource to delete is at the first node.
        actual=get->Getnext();
    }else{
        aux->setnext(get->Getnext());
    }
    delete get;
}
void Listares::InsertNodeSelPosition(Resource *res,int position){//NUEVA MELLY
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
