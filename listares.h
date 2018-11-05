#ifndef LISTARES_H
#define LISTARES_H
#include <nodores.h>

class Listares
{
public:
    Listares();
    void selectresource(Resource *);
    string toString();
    ~Listares();
    void keepresource();
    void chargeresource();

private:
    Nodores *actual;
};

#endif // LISTARES_H
