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
    std::string ImprimirTabla();
    void GenerarTabla();
    void SetTree(ArbolSintactico *a);
    void validarCasteo(std::string& e);
    void validarUso();
    void validarExpresiones();

};

#endif // SEMANTICO_H
