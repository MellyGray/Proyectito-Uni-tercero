#include "listiterator.h"

template <class T>
ListIterator<T>::ListIterator(Nodo<T> *obj){
    cursor=obj;
}
template <class T>
bool ListIterator<T>::moreElements(){
    return (cursor!=NULL);
}
template <class T>
T *ListIterator<T>::GetObj(){}
