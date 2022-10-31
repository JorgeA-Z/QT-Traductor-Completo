#include "nodo.h"

Nodo::Nodo()
{
    Next = nullptr;

}

Nodo::Nodo(Nodo *n)
{
    Next = n;
};
Nodo::~Nodo()
{

};
void Nodo::setReferencia(Nodo*n)
{
    Next = n;
};

Nodo* Nodo::getReferencia()
{
    return Next;
};
