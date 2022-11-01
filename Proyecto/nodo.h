#ifndef NODO_H
#define NODO_H
#include <string>

class Nodo
{
private:
    Nodo *Next; //Apunta a una R
public:
    Nodo();
    Nodo(Nodo *);
    ~Nodo();
    void setReferencia(Nodo*);
    Nodo *getReferencia();
    virtual std::string get_val();

};

#endif // NODO_H
