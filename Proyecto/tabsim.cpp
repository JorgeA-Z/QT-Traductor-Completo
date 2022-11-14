#include "tabsim.h"
#include <iostream>
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

std::string Tabsim::datatype(std::string d)
{
    char c;
    int i = 1;

    while(i < d.length())
    {
        c = d[i];

        switch(c)
        {

        case '.':

            if(d.substr(i, d.length()).length() > 14 )
            {
                return "d";

            }else
            {
                return "f";
            }

        }
        i++;
    }

    return "i";

};

bool Tabsim::searchCast(std::string expresion1, std::string expresion2)
{
    if (head == NULL)
    {


        return false;
    }
    nodo *temp;
    int index = 0;
    temp = head;

    //Aqui validar las cosas


    while (temp->getVal().getId() != expresion1)
    {
        index++;
        temp = temp->getReferencia();
        if (temp == NULL)
        {
            return false;
        }

    }

    if(temp->getVal().getId() == expresion1)
    {

        if(temp->getVal().getTipo() == " int")
        {
            if(datatype(expresion2) == "i")
            {
                cout << temp->getVal().getTipo() << expresion2 << endl;
                return true;
            }

        }

        if(temp->getVal().getTipo() == " float")
        {

            if(datatype(expresion2) == "f")
            {
                cout << temp->getVal().getTipo() << expresion2 << endl;
                return true;
            }
        }

        if(temp->getVal().getTipo() == " double")
        {
            if(datatype(expresion2) == "d" or datatype(expresion2) == "f")
            {
                cout << temp->getVal().getTipo() << expresion2 << endl;
                return true;
            }
        }
    }

    return false;
};


bool Tabsim::searchExist(std::string expresion1)
{
    if (head == NULL)
    {

        return false;
    }
    nodo *temp;
    int index = 0;
    temp = head;

    //Aqui validar las cosas

    while (temp->getVal().getId() !=  " " + expresion1)
    {
        index++;
        temp = temp->getReferencia();
        if (temp == NULL)
        {
            return false;
        }
    }

    return true;
};

bool Tabsim::searchType(std::string expresion1, std::string expresion2)
{
    if (head == NULL)
    {

        return false;
    }

    nodo *temp;

    nodo *temp1;

    int index = 0;
    temp = head;

    //Aqui validar las cosas

    while (temp->getVal().getId() != expresion1)
    {
        index++;
        temp = temp->getReferencia();
        if (temp == NULL)
        {
            return false;
        }
    }

    index = 0;

    temp1 = head;

    //Aqui validar las cosas

    while (temp1->getVal().getId() !=  expresion2)
    {
        index++;
        temp1 = temp1->getReferencia();
        if (temp1 == NULL)
        {
            return false;
        }
    }

    if(temp->getVal().getTipo() == temp1->getVal().getTipo())
    {
        return true;
    }

    return false;

};
