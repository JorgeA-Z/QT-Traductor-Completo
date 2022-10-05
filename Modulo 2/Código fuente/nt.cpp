#include "nt.h"
using namespace std;
//Implementacion del nodo
NT::Nodo::Nodo()
{
    next = nullptr;

};
/*
NT::Nodo::Nodo(string s) {
    val = s;
    next = nullptr;

};
*/
NT::Nodo::~Nodo() {

};
void NT::Nodo::setReferencia(Nodo *n)
{
    next = n;

};
/*
void NT::Nodo::setVal(string s)
{
    val = s;
};

string NT::Nodo::getVal()
{
    return val;
};
*/

typename NT::Nodo* NT::Nodo::getReferencia()
{
    return next;
};

NT::NT()
{

}
NT::NT(const int& i, const std::string &v)
{
    id = i;
    val = v;
};

void NT::setId(const int& i)
{
    id = i;
}

int NT::getId() const
{
    return id;

} 