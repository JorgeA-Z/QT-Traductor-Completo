#ifndef NODO_H
#define NODO_H
#include <string>

class Nodo
{
protected:
    Nodo *izquierda; //Apunta a una R
    Nodo *derecha;
    Nodo *centro;
    std::string valor;

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
    void setValor(std::string);
    std::string getValor();

   // virtual std::string validar();
};

#endif // NODO_H
