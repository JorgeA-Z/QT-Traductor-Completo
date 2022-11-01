#ifndef EP_H
#define EP_H
#include <string>
#include "nodo.h"
class EP
{
protected:
    std::string val;

public:
    EP();
    virtual std::string get_val();
    virtual int get_estado();
    virtual Nodo* getReferencia();

};

#endif // EP_H
