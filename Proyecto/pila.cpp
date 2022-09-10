#include "pila.h"

using namespace std;
//Implementacion del nodo
Pila::Nodo::Nodo()
{
    next = nullptr;

};
Pila::Nodo::Nodo(string s) {
    val = s;
    next = nullptr;

};
Pila::Nodo::~Nodo() {

};
void Pila::Nodo::setReferencia(Nodo *n)
{
    next = n;

};
void Pila::Nodo::setVal(string s)
{
    val = s;
};

string Pila::Nodo::getVal()
{
    return val;
};
typename Pila::Nodo* Pila::Nodo::getReferencia()
{
    return next;
};
//Implementacion de la Pila
Pila::Pila() : ancla(nullptr){

               };
Pila::Pila(const Pila &myPila) : ancla(nullptr)
{
    copyAll(myPila);
};
Pila::~Pila()
{
    deleteAll();
};
void Pila::copyAll(const Pila &myPila){

    Nodo* aux = myPila.ancla;
    Nodo* last = nullptr;
    Nodo* nuevoNodo;

    while (aux != nullptr)
    {
        nuevoNodo = new Nodo(aux->getVal());

        if (nuevoNodo == nullptr)
        {
            throw PilaExeption("Memoria no disponible, inser data");
        }

        if(last == nullptr)
        {
            ancla = nuevoNodo;
        }else
        {
            last->setReferencia(nuevoNodo);
        }

        last = nuevoNodo;

        aux = aux->getReferencia();
    }


};
void Pila::deleteAll(){

    Nodo *aux;

    while (ancla != nullptr)
    {
        aux = ancla;

        ancla = ancla->getReferencia();

        delete aux;
    }

};
bool Pila::vacia() const
{
    return ancla == nullptr;
};
void Pila::push(const string &s)
{
    Nodo *aux = new Nodo(s);

    if (aux == nullptr)
    {
        throw PilaExeption("Memoria no dispobible, push");
    }

    aux->setReferencia(ancla);

    ancla = aux;
};
string Pila::pop()
{
    if (ancla == nullptr)
    {
        throw PilaExeption("Insuficiencia de datos, Pop");
    }

    string result = ancla->getVal();

    Nodo *aux = ancla;

    ancla = ancla->getReferencia();

    delete aux;

    return result;
};
string Pila::Top() const {

    if (ancla == nullptr)
    {
        throw PilaExeption("Insuficiencia de datos, Top");
    }

    return ancla->getVal();

};

Pila &Pila::operator=(const Pila &myPila)
{
    deleteAll();

    copyAll(myPila);

    return *this;
};
