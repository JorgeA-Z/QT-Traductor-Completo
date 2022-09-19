#include "automata.h"
#include <iostream>
using namespace std;

Automata::Automata()
{

}
Automata::Automata(std::string &c)
{
    cadena = c;

}
Automata::~Automata()
{

}
void Automata::setCadena(std::string &c)
{
    cadena = c;

};
string Automata::getCadena()
{
    return cadena;
};
std::string  Automata::identificar(string& palabras)
{
    int obtenido = -1;

    obtenido = FastStep(palabras, reservadas, operadoresAritmeticos, operadoresLogicos);

    if(obtenido == -1)
    {
        obtenido = Analizar(palabras);
        int casos = Casos(palabras, obtenido);
        return resultados[obtenido] + " " +to_string(casos);
    }
    else
    {
        int casos = Casos(palabras, obtenido);
        return resultados[obtenido] + " " +to_string(casos);
    }
};
int Automata::Casos(string palabras, int obtenido)
{
    if(resultados[obtenido] == "Identificador")
    {
        return 0;
    }
    if(resultados[obtenido] == "int")
    {
        return 1;
    }
    if(resultados[obtenido] == "float")
    {
        return 2;
    }
    //Cadena es return 3
    if(resultados[obtenido] == "Reservadas")
    {
        if(EstaDentro(Tipos, palabras, 8))
        {
            return 4;
        }
    }
    if(palabras == "+")
    {
        return 5;
    }
    if(palabras == "*")
    {
        return 6;
    }
    if(EstaDentro(Relacionales, palabras, 3))
    {
        return 7;
    }
    if(palabras == "||")
    {
        return 8;
    }
    if(palabras == "&&")
    {
        return 9;
    }
    if(palabras == "!")
    {
        return 10;
    }
    if(palabras == "==")
    {
        return 11;
    }
    if(palabras == ";")
    {
        return 12;
    }
    if(palabras == ",")
    {
        return 13;
    }
    if(palabras == "(")
    {
        return 14;
    }
    if(palabras == ")")
    {
        return 15;
    }
    if(palabras == "{")
    {
        return 16;
    }
    if(palabras == "}")
    {
        return 17;
    }
    if(palabras == "=")
    {
        return 18;
    }
    if(palabras == "if")
    {
        return 19;
    }
    if(palabras == "while")
    {
        return 20;
    }
    if(palabras == "return")
    {
        return 21;
    }
    if(palabras == "else")
    {
        return 22;
    }
    if(palabras == "$")
    {
        return 23;
    }
}
bool Automata::EstaDentro(string palabras[], string palabra,  int tam)
{
    int i = 0;

    while(tam > i)
    {
        if(palabras[i] == palabra)
        {
            return true;
        }
        i++;
    }
    return false;
}
bool Automata::EstaDentroChar(char palabras[], char palabra,  int tam)
{
    int i = 0;

    while(tam > i)
    {
        if(palabras[i] == palabra)
        {
            return true;
        }
        i++;
    }
    return false;
}
int Automata::Analizar(std::string&palabra)
{
    int posicion = 0;
        int contador  = 0;
        //Comienza como un string
        if(EstaDentroChar(abecedario, palabra[contador], tamAbecedario))
        {
            posicion = 0;
        }
        //Comienza como numero
        if(EstaDentroChar(numeros, palabra[contador], tamNumeros))
        {
            //Hex begin
            if(palabra[contador] == '0')
            {
                posicion = 4;
            }
            else
            {
                posicion = 1;
            }
        }
        //Comienza como simbolo
        if(EstaDentroChar(simbolos, palabra[contador], tamSimbolos))
        {
            //Float
            if(palabra[contador] == '.')
            {
                posicion = 3;
            }
            posicion = 2;
        }
        if(palabra[contador] == '.')
        {
            posicion = 3;
        }

        contador++;
        while(contador < palabra.size())
        {
            switch(posicion)
            {
                //Letra
                case 0:
                {
                    contador++;
                    posicion = 0;
                    if(EstaDentroChar(abecedario, palabra[contador], tamNumeros))
                    {
                        posicion = 0;
                    }
                    else if(palabra[contador] == '.')
                    {
                        posicion = 9;
                    }
                    break;
                }
                //Numero
                case 1:
                {
                    if(EstaDentroChar(numeros, palabra[contador], tamNumeros))
                    {
                        posicion = 1;
                    }
                    else if(palabra[contador] == '.')
                    {
                        posicion = 3;
                    }
                    else if(EstaDentroChar(abecedario, palabra[contador], tamNumeros))
                    {
                        posicion = 9;
                    }
                    contador++;
                    break;
                }
                //Simbolo
                case 2:
                {
                    posicion = 2;
                    contador++;
                    break;
                }
                //Float
                case 3:
                {
                    if(EstaDentroChar(numeros, palabra[contador], tamNumeros))
                    {
                        posicion = 3;
                    }
                    else
                    {
                        posicion = 9;
                    }
                    contador++;
                    break;
                }
                //Posible Hex
                case 4:
                {
                    if(palabra[contador] == 'x')
                    {
                        posicion = 5;
                    }
                    else if(EstaDentroChar(numeros, palabra[contador], tamNumeros))
                    {
                        posicion = 1;
                    }
                    contador++;
                    break;
                }
                //Hex
                case 5:
                {
                    if(EstaDentroChar(hexadecimal, palabra[contador], tamHexadecimal))
                    {
                        posicion = 5;
                    }
                    else
                    {
                        posicion = -1;
                    }
                    contador++;
                    break;
                }
                case 9:
                {
                    contador++;
                    break;
                }
                default:
                {
                    posicion = 9;
                    contador++;
                    break;
                }
            }
        }
        switch(posicion)
        {
            case 0:
            {
                return 3;
            }
            case 1:
            {

                return 6;
            }
            case 2:
            {
                if(palabra.size() < 2)
                {
                    return 9;
                }
                return 10;
            }
            case 3:
            {
                return 5;
            }
            case 5:
            {
                return 4;
            }
            case 9:
            {
                return 10;
            }
            default:
            {
                return 6;
                break;
            }
        }
};
int Automata::FastStep(string& palabra, string lista1[], string lista2[], string lista3[])
{
    int encontrado = -1;

    if(EstaDentro(lista1, palabra, tamR))
    {
        encontrado = 0;
    }
    else if(EstaDentro(lista2, palabra, tamOA))
    {
        encontrado = 1;
    }
    else if(EstaDentro(lista3, palabra, tamOL))
    {
        encontrado = 2;
    }
    return encontrado;
};
