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

    std::string datatype(std::string d);

    bool searchCast(std::string expresion1, std::string expresion2);

    bool searchExist(std::string expresion1);

    bool searchType(std::string expresion1, std::string expresion2);

    std::string getTabla();

    class Exeption : public std::exception
    {
    private:
        std::string msg;

    public:
        explicit Exeption(const char *message) : msg(message) {}
        explicit Exeption(const std::string &message) : msg(message) {}
        virtual ~Exeption() throw() {}
        virtual const char *what() const throw()
        {
            return msg.c_str();
        }
    };
};

#endif // TABSIM_H
