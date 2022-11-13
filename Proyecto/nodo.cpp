#include "nodo.h"
#include <iostream>
using namespace std;

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
void Nodo::setValor(std::string s)
{
    valor = s;
};

std::string Nodo::getValor()
{
    return valor;
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
};
void Nodo::validar()
{
    tipoD = "v";
    if(izquierda != nullptr )
    {
        izquierda->validar();

    }

    if(centro != nullptr )
    {
        centro->validar();
    }

    if(derecha != nullptr )
    {
        derecha->validar();
    }

    cout << tipoD << endl;

};
