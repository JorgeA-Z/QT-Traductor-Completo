#include "arbolsintactico.h"
#include "nodo.h"
using namespace std;
ArbolSintactico::ArbolSintactico()
{

}
ArbolSintactico::ArbolSintactico(EP* r)
{
    root = r;
};
void ArbolSintactico::setRoot(EP*r)
{
    root = r;
};
std::string ArbolSintactico::arbol_to_string()
{

    string out;
    Nodo *aux;

    out += "";

    out += root->get_val();

    aux = root->getReferencia();

    out += Recorrer(aux);

    return out;
};
std::string ArbolSintactico::Recorrer(Nodo* aux)
{
    string text;
    string espacio = "";

    Nodo* aux2 = aux->getReferenciaCentro();

    while(aux2)
    {
        while(aux2->getReferenciaIzquierda())
        {
            espacio += "    ";
            text += espacio + aux2->getReferenciaIzquierda()->get_val() + espacio +Recorrer(aux2->getReferenciaIzquierda());
        }
        while(aux2->getReferenciaCentro())
        {
            espacio += "    ";
            text += espacio + aux2->getReferenciaCentro()->get_val() + espacio + Recorrer(aux2->getReferenciaCentro());
        }
        while(aux2->getReferenciaDerecha())
        {
            espacio += "    ";
            text += espacio + aux2->getReferenciaDerecha()->get_val() + espacio +  Recorrer(aux2->getReferenciaDerecha());
        }
        text += espacio + aux2->get_val() + espacio;
    }

    espacio = "    ";
    return text;
}
