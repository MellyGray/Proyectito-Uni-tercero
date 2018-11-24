#include "nodo.h"

template <class T>
Nodo<T>::Nodo(T *_obj, Nodo<T> *_next):obj(_obj),next(_next){
};
template <class T>
Nodo<T>::~Nodo(){

};
template <class T>
void Nodo<T>::setnext(Nodo<T> *_next){
    next=_next;
};
template <class T>
Nodo<T> *Nodo<T>::Getnext()const{
    return next;
};
template <class T>
T *Nodo<T>::GetObj()const{
return obj;
};
template <class T>
void Nodo<T>::SetObj(T *_obj){
    obj=_obj;
};
