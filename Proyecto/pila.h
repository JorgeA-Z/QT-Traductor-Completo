#ifndef PILA_H
#define PILA_H
#include <string>
#include "ep.h"
class Pila
{
private:
    class Nodo
    {
    private:
        EP *val;
        Nodo *next;

    public:
        Nodo();
        Nodo(EP*s);
        ~Nodo();
        void setReferencia(Nodo *n);
        void setVal(EP *s);

        EP* getVal();
        Nodo *getReferencia();
    };
    Nodo *ancla;
    void copyAll(const Pila &);
    void deleteAll();

public:
    class PilaExeption : public std::exception
    {
    private:
        std::string msg;

    public:
        explicit PilaExeption(const char *message) : msg(message) {}
        explicit PilaExeption(const std::string &message) : msg(message) {}
        virtual ~PilaExeption() throw() {}
        virtual const char *what() const throw()
        {
            return msg.c_str();
        }
    };

    Pila();
    Pila(const Pila &);
    ~Pila();
    bool vacia() const;
    void push(EP *);
    EP *pop();
    EP* Top() const;

    Pila &operator=(const Pila &);
    std::string GetPila();
};
#endif // PILA_H
