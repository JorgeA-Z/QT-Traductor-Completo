#ifndef TABSIM_H
#define TABSIM_H
#include "simbolo.h"
#include <string>
#include "arbolsintactico.h"
class Tabsim
{
private:

    class nodo {
    private:
        Simbolo val;
        nodo *next;
    public:
        nodo();
        nodo(Simbolo v);
        ~nodo();
        void setReferencia(nodo *n);
        void setVal(Simbolo v);

        Simbolo getVal();
        nodo* getReferencia();
        //nodo &operator=(const nodo &);
    };

    nodo *head, *tail;
    void deleteAll();

public:
    Tabsim();
    ~Tabsim();
    void insertHead(Simbolo v);
    void insertTail(Simbolo v);
    void deleteHead();
    void deleteTail();
    void generarTabla(ArbolSintactico*);
    std::string getTabla();
};

#endif // TABSIM_H
