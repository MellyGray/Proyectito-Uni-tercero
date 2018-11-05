#include "nodores.h"


Nodores::Nodores()
{

};
Nodores::Nodores(Resource *_res, Nodores *_next){
    res=_res;
    next=_next;
};
Nodores::~Nodores(){

};

void Nodores::setnext(Nodores *_next){
    next=_next;
};

Nodores *Nodores::Getnext(){
    return next;
};

Resource *Nodores::Getresource(){
return res;
};
void Nodores::setrest(Resource *_res){
    res=_res;
};
