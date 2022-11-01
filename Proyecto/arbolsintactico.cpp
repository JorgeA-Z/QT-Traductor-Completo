#include "arbolsintactico.h"
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

    out += "";

    return out;
};
