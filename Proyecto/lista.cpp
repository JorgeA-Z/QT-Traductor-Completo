#include "lista.h"
using namespace std;
Lista::nodo::nodo()
{
    next = nullptr;

};


Lista::nodo::nodo(string v) {
    val = v;
    next = nullptr;

}

Lista::nodo::~nodo() {

}

void Lista::nodo::setReferencia(nodo *n)
{
    next = n;

};

void Lista::nodo::setVal(string v)
{
    val = v;
};

string Lista::nodo::getVal()
{
    return val;
};

Lista::nodo* Lista::nodo::getReferencia()
{
    return next;
};

Lista::Lista()
{
    head = nullptr;
    tail = nullptr;
}

Lista::~Lista()
{
    deleteAll();
}

void Lista::insertHead(string v)
{
    nodo *vtx = new nodo(v);
    vtx->setReferencia(head);
    head = vtx;
    if (tail == nullptr)
    {
        tail = head;
    }
};
void Lista::insertTail(string v)
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
void Lista::deleteHead()
{
    if (head == nullptr)
    {
        return;
    }
    nodo *temp = head;
    head = head->getReferencia();
    delete temp;
};
void Lista::deleteTail()
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

void Lista::deleteAll(){

    nodo *aux;

    while (head != nullptr)
    {
        aux = head;

        head = head->getReferencia();

        delete aux;
    }

};
string Lista::getList()
{
    string data;
    nodo* aux = head;

    while(aux != nullptr)
    {
        data += aux->getVal();
        aux = aux->getReferencia();
    }

    return data;
};
