#ifndef NODORES_H
#define NODORES_H
#include "resource.h"

//Nodes for the resources list. Each node has an object of type Resource and a link to the next node
class Nodores
{
private:
    Resource *resource;
    Nodores *next;
public:
    Nodores();
    Nodores(Resource *, Nodores *);
    virtual ~Nodores();
    //Set the next node. This method set the link of two nodes
    void setnext(Nodores *);
    //Method to get the next node with wich the actual node has a link
    Nodores *Getnext();
    //Method to get the resource in the node
    Resource *Getresource();
    //Method to set the resource on the node
    void SetResource(Resource *);

};

#endif // NODORES_H
