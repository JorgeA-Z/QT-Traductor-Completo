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

    out += root->get_val() + "\n";

    aux = root->getReferencia();

    out += "---|";
    out += aux->get_val();

    out += Recorrer(aux, "");

    return out;
};

std::string ArbolSintactico::Recorrer(Nodo* aux, string espacios)
{
    string text = "";
    string space = "";
    space += espacios;
    Nodo* aux2 = aux;
    Nodo* temp;

    bool c = false;
    bool d = false;
    bool i = false;

    while((!c || !d || !i))
    {
        if(aux2->getReferenciaCentro())
        {
            space += "   ";
            temp = aux2->getReferenciaCentro();

            text += space + temp->getValor() + "\n";
            text += space + temp->get_val() + "\n";
            text += Recorrer(temp, space);
            c = true;
        }
        else
        {
            c = true;
        }
        if(aux2->getReferenciaIzquierda())
        {
            space += "   ";
            temp = aux2->getReferenciaIzquierda();

            text += space + temp->getValor() + "\n";
            text += space + temp->get_val() + "\n";
            text += Recorrer(temp, space);

            i = true;
        }
        else
        {
            i = true;
        }
        if(aux2->getReferenciaDerecha())
        {
            space += "   ";
            temp = aux2->getReferenciaDerecha();

            text += space + temp->getValor() + "\n";
            text += space + temp->get_val() + "\n";
            text += Recorrer(temp, space);

            d = true;
        }
        else
        {
            d = true;
        }
    }
    return text;
}
