#include "nt.h"
using namespace std;
NT::NT()
{
    referencia = nullptr;
};
NT::NT(const std::string &v, Nodo *n)
{
    val = v;
    referencia = n;
};
void NT::setReferencia(Nodo *n)
{
    referencia = n;
};
Nodo* NT::getReferencia()
{
    return referencia;
};
std::string NT::get_val()
{

    return val;
};
void NT::set_val(const std::string &data)
{
    val = data;
};
