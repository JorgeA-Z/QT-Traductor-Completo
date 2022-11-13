#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <string>
class Simbolo
{
private:
    std::string id;
    std::string ambito;
    std::string tipo;


public:
    Simbolo();
    Simbolo(std::string&, std::string&, std::string&);

    void setId(std::string&);
    void setAmbito(std::string&);
    void setTipo(std::string&);

    std::string getId();

    std::string getAmbito();

    std::string getTipo();

    std::string getSimbolo();

};

#endif // SIMBOLO_H
