#ifndef ARBOLSINTACTICO_H
#define ARBOLSINTACTICO_H
#include "ep.h"
#include <string>
class ArbolSintactico
{
private:
    EP* root;

public:
    ArbolSintactico();
    ArbolSintactico(EP*);
    void setRoot(EP*);
    std::string arbol_to_string();
    std::string Recorrer(Nodo* aux, std::string espacios);
};

#endif // ARBOLSINTACTICO_H
