#ifndef NODORES_H
#define NODORES_H
#include "resource.h"
class Nodores
{
public:
    Nodores();
    Nodores(Resource *, Nodores *);
    ~Nodores();
    setnext(Nodores *);
    Nodores *Getnext();
    Resource *Getresource();
    setrest(Resource *);
private:
    Resource *res;
    Nodores *next;
};

#endif // NODORES_H
