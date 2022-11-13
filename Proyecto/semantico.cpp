#include "semantico.h"

Semantico::Semantico()
{

}
Semantico::Semantico(ArbolSintactico *a)
{
    arbol = a;
};
void Semantico::validarSentencias()
{
    tabla->generarTabla(arbol);

};
void Semantico::SetTree(ArbolSintactico *a)
{
        arbol = a;
};
