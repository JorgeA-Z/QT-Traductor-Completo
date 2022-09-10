#ifndef PILA_H
#define PILA_H
#include <string>
class Pila
{
private:
    class Nodo
    {
    private:
        std::string val;
        Nodo *next;

    public:
        Nodo();
        Nodo(std::string s);
        ~Nodo();
        void setReferencia(Nodo *n);
        void setVal(std::string s);

        std::string getVal();
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
    void push(const std::string &);
    std::string pop();
    std::string Top() const;

    Pila &operator=(const Pila &);
};
#endif // PILA_H
