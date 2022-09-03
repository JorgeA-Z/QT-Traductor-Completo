#include "automata.h"
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
        return resultados[obtenido];
    }
    else
    {
        return resultados[obtenido];
    }
};
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
                    return 3;
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
        if(posicion == 1)
            {
                return 6;
            }
            else if(posicion == 2)
            {
                if(palabra.size() < 2)
                {
                    return 9;
                }
                return 10;
            }
            else if(posicion == 3)
            {
                return 5;
            }
            else if(posicion == 5)
            {
                return 4;
            }
            else if(posicion == 9)
            {
                return 10;
            }
            else
            {
                return 9;
            }
            return 0;
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
