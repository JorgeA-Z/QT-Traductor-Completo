#include "tabsim.h"
using namespace std;

Tabsim::nodo::nodo()
{
    next = nullptr;

};


Tabsim::nodo::nodo(Simbolo v) {
    val = v;
    next = nullptr;

}

Tabsim::nodo::~nodo() {

}

void Tabsim::nodo::setReferencia(nodo *n)
{
    next = n;

};

void Tabsim::nodo::setVal(Simbolo v)
{
    val = v;
};

Simbolo Tabsim::nodo::getVal()
{
    return val;
};

Tabsim::nodo* Tabsim::nodo::getReferencia()
{
    return next;
};
Tabsim::Tabsim()
{
    head = nullptr;
    tail = nullptr;
}

Tabsim::~Tabsim()
{
    deleteAll();
}

void Tabsim::insertHead(Simbolo v)
{
    nodo *vtx = new nodo(v);
    vtx->setReferencia(head);
    head = vtx;
    if (tail == nullptr)
    {
        tail = head;
    }
};
void Tabsim::insertTail(Simbolo v)
{
    if (tail == nullptr)
    {
        insertHead(v);
        return;
    }
    nodo *vtx = new nodo(v);
    tail->setReferencia(vtx);
    tail = vtx;
};
void Tabsim::deleteHead()
{
    if (head == nullptr)
    {
        return;
    }
    nodo *temp = head;
    head = head->getReferencia();
    delete temp;
};
void Tabsim::deleteTail()
{
    if (tail == nullptr)
    {
        return;
    }
    nodo *pre, *temp;
    pre = head;
    temp = head->getReferencia();
    while (temp->getReferencia() != nullptr)
    {
        temp = temp->getReferencia();
        pre = pre->getReferencia();
    }
    pre->setReferencia(nullptr);
    delete temp;
    tail = pre;
};

void Tabsim::deleteAll(){

    nodo *aux;

    while (head != nullptr)
    {
        aux = head;

        head = head->getReferencia();

        delete aux;
    }

};

string Tabsim::getTabla()
{
    string data;
    nodo* aux = head;

    while(aux != nullptr)
    {
        data += aux->getVal().getSimbolo() + "\n";
        aux = aux->getReferencia();
    }

    return data;
};
void Tabsim::generarTabla(ArbolSintactico*arbol)
{
    arbol->analiza();
};
