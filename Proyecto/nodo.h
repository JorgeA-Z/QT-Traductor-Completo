#ifndef NODO_H
#define NODO_H


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

};

#endif // NODO_H
