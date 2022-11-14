#include "semantico.h"

Semantico::Semantico()
{
        tabla = new Tabsim();
}
Semantico::Semantico(ArbolSintactico *a)
{
    arbol = a;
};
void Semantico::GenerarTabla()
{

    arbol->analiza(tabla);

};
void Semantico::SetTree(ArbolSintactico *a)
{
        arbol = a;
};
std::string Semantico::ImprimirTabla()
{

    return tabla->getTabla();
};
void Semantico::validarCasteo(std::string& e)
{
    arbol->casteo(tabla, e);

};
void Semantico::validarUso(){};
void Semantico::validarExpresiones()
{

};
