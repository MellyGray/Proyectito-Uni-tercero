#include "nodores.h"


Nodores::Nodores()
{

};
Nodores::Nodores(Resource *_resource, Nodores *_next){
    resource=_resource;
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
return resource;
};
void Nodores::SetResource(Resource *_resource){
    resource=_resource;
};
