#include "ep.h"
using namespace std;
EP::EP()
{

}
string EP::get_val()
{
    return val;
};
int EP::get_estado()
{
    return stoi(val);
};
Nodo* EP::getReferencia()
{
    return nullptr;
};
