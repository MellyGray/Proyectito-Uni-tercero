#ifndef NODORES_H
#define NODORES_H
#include "resource.h"
class Nodores
{
public:
    Nodores();
    Nodores(Resource *, Nodores *);
    ~Nodores();
    void setnext(Nodores *);
    Nodores *Getnext();
    Resource *Getresource();
    void setrest(Resource *);
private:
    Resource *res;
    Nodores *next;
};

#endif // NODORES_H