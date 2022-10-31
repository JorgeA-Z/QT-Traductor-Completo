#include "pila.h"
#include "lista.h"
using namespace std;
//Implementacion del nodo
Pila::Nodo::Nodo()
{
    next = nullptr;

};
Pila::Nodo::Nodo(EP *s) {
    val = s;
    next = nullptr;

};
Pila::Nodo::~Nodo() {

};
void Pila::Nodo::setReferencia(Nodo *n)
{
    next = n;

};
void Pila::Nodo::setVal(EP *s)
{
    val = s;
};

EP* Pila::Nodo::getVal()
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
void Pila::push(EP *s)
{
    Nodo *aux = new Nodo(s);

    if (aux == nullptr)
    {
        throw PilaExeption("Memoria no dispobible, push");
    }

    aux->setReferencia(ancla);

    ancla = aux;
};
EP* Pila::pop()
{
    if (ancla == nullptr)
    {
        throw PilaExeption("Insuficiencia de datos, Pop");
    }

    EP* result = ancla->getVal();

    Nodo *aux = ancla;

    ancla = ancla->getReferencia();

    delete aux;

    return result;
};
EP* Pila::Top() const {

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
std::string Pila::GetPila()
{
    Lista lista;

    Nodo *aux = ancla;

    while(aux != nullptr)
    {
        lista.insertHead(aux->getVal()->get_val());

        aux = aux->getReferencia();
    }

    return lista.getList();
};
