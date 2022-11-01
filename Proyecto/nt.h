#ifndef NT_H
#define NT_H
#include "ep.h"
#include "nodo.h"
class NT: public EP
{
private:
    Nodo *referencia;

public:
    NT();
    NT(const std::string &, Nodo *);
    void setReferencia(Nodo *);
    Nodo* getReferencia();

    std::string get_val();
    void set_val(const std::string &);
};

#endif // NT_H
