#ifndef NODO_H
#define NODO_H
#include <string>

class Nodo
{
protected:
    Nodo *izquierda; //Apunta a una R
    Nodo *derecha;
    Nodo *centro;

public:
    Nodo();
    Nodo(Nodo *, Nodo*, Nodo*);
    ~Nodo();

    virtual void setReferenciaIzquierda(Nodo*);
    virtual Nodo *getReferenciaIzquierda();

    virtual void setReferenciaDerecha(Nodo*);
    virtual Nodo *getReferenciaDerecha();

    virtual void setReferenciaCentro(Nodo*);
    virtual Nodo *getReferenciaCentro();

    virtual std::string get_val();

};

#endif // NODO_H
