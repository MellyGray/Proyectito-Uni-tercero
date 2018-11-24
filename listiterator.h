#ifndef LISTITERATOR_H
#define LISTITERATOR_H
#include "nodo.h"

template <class T>
class ListIterator
{
private:
    Nodo<T> *cursor;
public:
    ListIterator(Nodo<T> *);
    bool moreElements();
    T *GetObj();

};

#endif // LISTITERATOR_H
