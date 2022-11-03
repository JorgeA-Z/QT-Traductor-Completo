#include "nodo.h"

Nodo::Nodo()
{
    izquierda = nullptr;
    derecha = nullptr;
    centro = nullptr;


};
Nodo::Nodo(Nodo *i, Nodo*d, Nodo*c)
{
    izquierda = i;
    derecha = d;
    centro = c;

};
Nodo::~Nodo(){};

void Nodo::setReferenciaIzquierda(Nodo*i)
{
        izquierda = i;
};
Nodo* Nodo::getReferenciaIzquierda()
{
    return izquierda;
};
void Nodo::setReferenciaDerecha(Nodo*d)
{
    derecha = d;

};
Nodo* Nodo::getReferenciaDerecha()
{
    return derecha;
};
void Nodo::setReferenciaCentro(Nodo*c)
{
    centro = c;
};
Nodo* Nodo::getReferenciaCentro()
{
    return centro;
};
std::string Nodo::get_val()
{
    std::string out;
    out = "None";
    return out;
}
