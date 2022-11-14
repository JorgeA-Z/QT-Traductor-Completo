#ifndef ARBOLSINTACTICO_H
#define ARBOLSINTACTICO_H
#include "ep.h"
#include <string>
#include <fstream>
//#include "tabsim.h"
class Tabsim;

class ArbolSintactico
{
private:
    EP* root;

public:
    ArbolSintactico();
    ArbolSintactico(EP*);
    void setRoot(EP*);
    std::string arbol_to_string();
    std::string Recorrer(Nodo* aux, std::string espacios);
    std::string BuscarVariables(Nodo* aux, std::string padre, std::string abuelo, Tabsim* tabla);
    std::string BuscarFuncion(Nodo* aux, std::string padre, std::string abuelo, Tabsim* tabla);


    std::string BuscarSentencia(Nodo* aux, std::string padre, std::string abuelo, Tabsim* tabla);

    void casteo(Tabsim* tabla, std::string& e);

    void uso(Tabsim* tabla, std::string& e);

    void analiza(Tabsim* tabla);

    class Exeption : public std::exception
    {
    private:
        std::string msg;

    public:
        explicit Exeption(const char *message) : msg(message) {}
        explicit Exeption(const std::string &message) : msg(message) {}
        virtual ~Exeption() throw() {}
        virtual const char *what() const throw()
        {
            return msg.c_str();
        }
    };
};

#endif // ARBOLSINTACTICO_H
