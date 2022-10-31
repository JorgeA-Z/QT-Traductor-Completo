#ifndef NT_H
#define NT_H
#include "ep.h"
#include "nodo.h"
class NT: public EP
{
protected:
    Nodo *referencia;

public:
    NT();
    NT(const int&, const std::string &);
};

#endif // NT_H
