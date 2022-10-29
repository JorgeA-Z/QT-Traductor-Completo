#ifndef LISTA_H
#define LISTA_H
#include <string>

class Lista
{
private:
    class nodo {
    private:
        std::string val;
        nodo *next;
    public:
        nodo();
        nodo(std::string v);
        ~nodo();
        void setReferencia(nodo *n);
        void setVal(std::string v);

        std::string getVal();
        nodo* getReferencia();
        //nodo &operator=(const nodo &);
    };

    nodo *head, *tail;
    void deleteAll();
public:
    Lista();
    ~Lista();
    void insertHead(std::string v);
    void insertTail(std::string v);
    void deleteHead();
    void deleteTail();
    std::string getList();

};

#endif // LISTA_H
