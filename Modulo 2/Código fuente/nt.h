#ifndef NT_H
#define NT_H
#include "ep.h"
class NT: public EP
{
protected:
    class Nodo
    {
    private:
        //std::string val;
        Nodo *next;

    public:
        Nodo();
        //Nodo(std::string s);
        ~Nodo();
        void setReferencia(Nodo *n);
        //void setVal(std::string s);

        //std::string getVal();
        Nodo *getReferencia();
    };
    Nodo *ancla;
    int id;

public:
    NT();
    NT(const int&, const std::string &);
    void setId(const int&);
    int getId() const;
};

#endif // NT_H
