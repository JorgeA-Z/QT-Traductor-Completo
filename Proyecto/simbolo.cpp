#include "simbolo.h"
using namespace std;
Simbolo::Simbolo()
{

}
Simbolo::Simbolo(std::string&, std::string&, std::string&){};

void Simbolo::setId(std::string&i)
{
    id = i;
};
void Simbolo::setAmbito(std::string&a)
{
    ambito = a;
};
void Simbolo::setTipo(std::string&t)
{
    tipo = t;
};
std::string Simbolo::getId()
{
    return id;
};
std::string Simbolo::getAmbito()
{
    return ambito;
};
std::string Simbolo::getTipo()
{
    return tipo;
};

std::string Simbolo::getSimbolo()
{
    return id + " " + tipo + " " + ambito;
};
