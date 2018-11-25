#ifndef NODOUSERS_H
#define NODOUSERS_H
#include "user.h"

class NodoUsers
{
private:
    User *user;
    NodoUsers *next;
public:
    NodoUsers();
    NodoUsers(User *, NodoUsers *);
    virtual ~NodoUsers();
    //Set the next node. This method set the link of two nodes
    void SetNext(NodoUsers *);
    //Method to get the next node with wich the actual node has a link
    NodoUsers *Getnext();
    //Method to get the user in the node
    User *GetUser();
    //Method to set the user on the node
    void SetUser(User *);
};

#endif // NODOUSERS_H
