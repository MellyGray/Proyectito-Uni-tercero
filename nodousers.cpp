#include "nodousers.h"


NodoUsers::NodoUsers()
{

};
NodoUsers::NodoUsers(User *_user, NodoUsers *_next){
    user=_user;
    next=_next;
};
NodoUsers::~NodoUsers(){

};

void NodoUsers::SetNext(NodoUsers *_next){
    next=_next;
};

NodoUsers *NodoUsers::Getnext(){
    return next;
};

User *NodoUsers::GetUser(){
return user;
};
void NodoUsers::SetUser(User *_user){
    user=_user;
};
