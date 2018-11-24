#ifndef NODO_H
#define NODO_H
#include "resource.h"

//Nodes for the resources list. Each node has an object of type Resource and a link to the next node
template <class T>
class Nodo
{
private:
    T *obj;
    Nodo<T> *next;
public:
    Nodo(T *, Nodo<T> *);
    virtual ~Nodo();
    //Set the next node. This method set the link of two nodes
    virtual void setnext(Nodo<T> *);
    //Method to get the next node with wich the actual node has a link
    virtual Nodo<T> *Getnext()const;
    //Method to get the resource in the node
    virtual T *GetObj() const;
    //Method to set the resource on the node
    virtual void SetObj(T *);

};

#endif // NODO_H
