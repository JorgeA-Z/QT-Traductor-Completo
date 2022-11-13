#ifndef SEMANTICO_H
#define SEMANTICO_H
#include "arbolsintactico.h"
#include "tabsim.h"
#include <string>
class Semantico
{
private:
    std::string errores[10];
    ArbolSintactico *arbol;
    Tabsim* tabla;

public:
    Semantico();
    Semantico(ArbolSintactico *a);
    void validarSentencias();
    void SetTree(ArbolSintactico *a);

};

#endif // SEMANTICO_H
