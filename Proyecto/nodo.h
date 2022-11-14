#ifndef NODO_H
#define NODO_H
#include <string>

class T;

class Nodo
{
protected:
    Nodo *izquierda; //Apunta a una R
    Nodo *derecha;
    Nodo *centro;
    std::string valor;

    std::string tipoD;

    std::string ambito;

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

    virtual void validar();

    virtual T* getTipo();
    virtual T* getID();
    virtual T* getPC();

    virtual T* gettipo();
    virtual T* getidentificador();

    virtual T* getIdentificador();

    void setValor(std::string);
    std::string getValor();

   // virtual std::string validar();
};

#endif // NODO_H
