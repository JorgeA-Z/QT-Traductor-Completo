#include "arbolsintactico.h"
#include "nodo.h"
//Quitar iostream
#include <iostream>
#include "t.h"
#include "simbolo.h"
#include "tabsim.h"
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

std::string ArbolSintactico::BuscarVariables(Nodo* aux, string padre, string abuelo, Tabsim* tabla)
{
    string text = "", sim;
    Nodo* aux2 = aux;
    Nodo* temp;
    Simbolo auxS;

    bool c = false;
    bool d = false;
    bool i = false;

    while((!c || !d || !i))
    {
        if(aux2->getReferenciaCentro())
        {
            temp = aux2->getReferenciaCentro();
            if(temp->getValor() == abuelo)
            {
                if(temp->get_val() == padre)
                {
                    temp = temp->getReferenciaCentro();
                    text += temp->get_val() + "\n";

                    auxS.setAmbito(abuelo);



                    sim  = temp->getID()->get_val();
                    auxS.setId(sim);

                    sim = temp->getTipo()->get_val();

                    auxS.setTipo(sim);


                    tabla->insertHead(auxS);
                }
            }
            text += BuscarVariables(temp, padre, abuelo, tabla);
            c = true;
        }
        else
        {
            c = true;
        }
        if(aux2->getReferenciaIzquierda())
        {
            temp = aux2->getReferenciaIzquierda();
            if(temp->getValor() == abuelo)
            {
                if(temp->get_val() == padre)
                {
                    temp = temp->getReferenciaCentro();
                    text += temp->get_val() + "\n";

                    auxS.setAmbito(abuelo);



                    sim  = temp->getID()->get_val();
                    auxS.setId(sim);

                    sim = temp->getTipo()->get_val();

                    auxS.setTipo(sim);


                    tabla->insertHead(auxS);
                }
            }
            text += BuscarVariables(temp, padre, abuelo, tabla);

            i = true;
        }
        else
        {
            i = true;
        }
        if(aux2->getReferenciaDerecha())
        {
            temp = aux2->getReferenciaDerecha();
            if(temp->getValor() == abuelo)
            {

                if(temp->get_val() == padre)
                {
                    temp = temp->getReferenciaCentro();
                    text += temp->get_val() + "\n";

                    auxS.setAmbito(abuelo);



                    sim  = temp->getID()->get_val();
                    auxS.setId(sim);

                    sim = temp->getTipo()->get_val();

                    auxS.setTipo(sim);


                    tabla->insertHead(auxS);
                }
            }

            text += BuscarVariables(temp, padre, abuelo, tabla);

            d = true;
        }
        else
        {
            d = true;
        }
    }
    return text;
}
std::string ArbolSintactico::BuscarFuncion(Nodo* aux, std::string padre, std::string abuelo, Tabsim* tabla)
{
    string text = "", sim;
    Nodo* aux2 = aux;
    Nodo* temp;
    Simbolo auxS;

    bool c = false;
    bool d = false;
    bool i = false;

    while((!c || !d || !i))
    {
        if(aux2->getReferenciaCentro())
        {
            temp = aux2->getReferenciaCentro();
            if(temp->getValor() == abuelo)
            {
                if(temp->get_val() == padre)
                {
                    temp = temp->getReferenciaCentro();
                    text += temp->get_val() + "\n";

                    auxS.setAmbito(abuelo);



                    sim  = temp->gettipo()->get_val();
                    auxS.setId(sim);

                    sim = temp->getidentificador()->get_val();

                    auxS.setTipo(sim);


                    tabla->insertHead(auxS);
                }
            }
            text += BuscarFuncion(temp, padre, abuelo, tabla);
            c = true;
        }
        else
        {
            c = true;
        }
        if(aux2->getReferenciaIzquierda())
        {
            temp = aux2->getReferenciaIzquierda();
            if(temp->getValor() == abuelo)
            {
                if(temp->get_val() == padre)
                {
                    temp = temp->getReferenciaCentro();
                    text += temp->get_val() + "\n";

                    auxS.setAmbito(abuelo);



                    sim  = temp->gettipo()->get_val();
                    auxS.setId(sim);

                    sim = temp->getidentificador()->get_val();

                    auxS.setTipo(sim);


                    tabla->insertHead(auxS);
                }
            }
            text += BuscarFuncion(temp, padre, abuelo, tabla);

            i = true;
        }
        else
        {
            i = true;
        }
        if(aux2->getReferenciaDerecha())
        {
            temp = aux2->getReferenciaDerecha();
            if(temp->getValor() == abuelo)
            {

                if(temp->get_val() == padre)
                {
                    temp = temp->getReferenciaCentro();
                    text += temp->get_val() + "\n";

                    auxS.setAmbito(abuelo);



                    sim  = temp->gettipo()->get_val();
                    auxS.setId(sim);

                    sim = temp->getidentificador()->get_val();

                    auxS.setTipo(sim);


                    tabla->insertHead(auxS);
                }
            }

            text += BuscarFuncion(temp, padre, abuelo, tabla);

            d = true;
        }
        else
        {
            d = true;
        }
    }
    return text;

};

std::string ArbolSintactico::BuscarSentencia(Nodo* aux, std::string padre, std::string abuelo, Tabsim* tabla)
{
    string text = "", sim;
    Nodo* aux2 = aux;
    Nodo* temp, *temp2, *e1, *e2, *temp3;
    Simbolo auxS;

    bool c = false;
    bool d = false;
    bool i = false;

    while((!c || !d || !i))
    {

        if(aux2->getReferenciaCentro())
        {
            temp = aux2->getReferenciaCentro();
            if(temp->getValor() == abuelo)
            {
                if(temp->get_val() == padre)
                {
                    temp = temp->getReferenciaCentro();

                    temp2 = temp->getReferenciaCentro();

                    cout << temp->get_val() << endl;

                    if(temp->get_val() == " if  (  ) <Expresion> <SentenciaBloque> <Otro>")
                    {
                        temp3  = temp->getReferenciaIzquierda();


                        cout << "Lo he arreglado: aqui van las condicionales" << temp3->get_val() << endl;

                        if(temp3->get_val() == "<Expresion>  < <Expresion>")
                        {
                            e1 = temp3->getReferenciaDerecha();

                            e2 = temp3->getReferenciaIzquierda();

                            cout << e1->get_val().substr(14, e1->get_val().length()) << " " << e2->get_val().substr(14, e1->get_val().length());

                            if (tabla->searchExist(e1->get_val().substr(14, e1->get_val().length())) == false)
                            {
                                text += "Not declared: " + e1->get_val().substr(14, e1->get_val().length()) +"\n";

                                if(tabla->searchExist(e2->get_val().substr(14, e2->get_val().length())) == false)
                                {

                                    text += "Not declared: " + e2->get_val().substr(14, e2->get_val().length()) +"\n";
                                }

                            }else
                            {
                                if(tabla->searchExist(e2->get_val().substr(14, e2->get_val().length())) == false)
                                {

                                    text += "Not declared: " + e2->get_val().substr(14, e2->get_val().length()) +"\n";
                                }else
                                {

                                    if(tabla->searchType( e1->get_val().substr(13, e1->get_val().length()),  e2->get_val().substr(13, e1->get_val().length())) == false)
                                    {
                                        text += "invalid datatype: " + e2->get_val().substr(14, e2->get_val().length()) + " " + e1->get_val().substr(14, e2->get_val().length()) + "\n";
                                    }


                                }

                            }

                        }else
                        {
                            cout << "More methods" << endl;
                        }


                    }else
                    {

                        if(temp2->get_val() == "<Expresion>  + <Expresion>" or temp2->get_val() == "<Expresion>  - <Expresion>" or temp2->get_val() == "<Expresion>  * <Expresion>" or temp2->get_val() == "<Expresion>  / <Expresion>")
                        {
                            e1 = temp2->getReferenciaDerecha();

                            e2 = temp2->getReferenciaIzquierda();

                            cout << e1->get_val().substr(14, e1->get_val().length()) << " " << e2->get_val().substr(14, e1->get_val().length());

                            if (tabla->searchCast(temp->getIdentificador()->get_val(), e1->get_val().substr(14, e1->get_val().length())) == false or tabla->searchCast(temp->getIdentificador()->get_val(), e2->get_val().substr(14, e1->get_val().length())) == false)
                            {
                                text += "invalid datatype: " + temp->getIdentificador()->get_val() +"\n";
                            }

                        }else
                        {
                            if (tabla->searchCast(temp->getIdentificador()->get_val(), temp2->get_val()) == false)
                            {
                                text += "invalid datatype: " + temp->getIdentificador()->get_val() +"\n";
                            }
                        }


                    }

                }
            }
            text += BuscarSentencia(temp, padre, abuelo, tabla);
            c = true;
        }
        else
        {
            c = true;
        }
        if(aux2->getReferenciaIzquierda())
        {
            temp = aux2->getReferenciaIzquierda();
            if(temp->getValor() == abuelo)
            {
                if(temp->get_val() == padre)
                {
                    temp = temp->getReferenciaCentro();

                    temp2 = temp->getReferenciaCentro();

                    cout << temp->get_val() << endl;

                    if(temp->get_val() == " if  (  ) <Expresion> <SentenciaBloque> <Otro>")
                    {
                        temp3  = temp->getReferenciaIzquierda();


                        cout << "Lo he arreglado: aqui van las condicionales" << temp3->get_val() << endl;

                        if(temp3->get_val() == "<Expresion>  < <Expresion>")
                        {
                            e1 = temp3->getReferenciaDerecha();

                            e2 = temp3->getReferenciaIzquierda();

                            cout << e1->get_val().substr(14, e1->get_val().length()) << " " << e2->get_val().substr(14, e1->get_val().length());

                            if (tabla->searchExist(e1->get_val().substr(14, e1->get_val().length())) == false)
                            {
                                text += "Not declared: " + e1->get_val().substr(14, e1->get_val().length()) +"\n";

                                if(tabla->searchExist(e2->get_val().substr(14, e2->get_val().length())) == false)
                                {

                                    text += "Not declared: " + e2->get_val().substr(14, e2->get_val().length()) +"\n";
                                }

                            }else
                            {
                                if(tabla->searchExist(e2->get_val().substr(14, e2->get_val().length())) == false)
                                {

                                    text += "Not declared: " + e2->get_val().substr(14, e2->get_val().length()) +"\n";
                                }else
                                {

                                    if(tabla->searchType( e1->get_val().substr(13, e1->get_val().length()),  e2->get_val().substr(13, e1->get_val().length())) == false)
                                    {
                                        text += "invalid datatype: " + e2->get_val().substr(14, e2->get_val().length()) + " " + e1->get_val().substr(14, e2->get_val().length()) + "\n";
                                    }


                                }

                            }

                        }else
                        {
                            cout << "More methods" << endl;
                        }


                    }else
                    {

                        if(temp2->get_val() == "<Expresion>  + <Expresion>" or temp2->get_val() == "<Expresion>  - <Expresion>" or temp2->get_val() == "<Expresion>  * <Expresion>" or temp2->get_val() == "<Expresion>  / <Expresion>")
                        {
                            e1 = temp2->getReferenciaDerecha();

                            e2 = temp2->getReferenciaIzquierda();

                            cout << e1->get_val().substr(14, e1->get_val().length()) << " " << e2->get_val().substr(14, e1->get_val().length());

                            if (tabla->searchCast(temp->getIdentificador()->get_val(), e1->get_val().substr(14, e1->get_val().length())) == false or tabla->searchCast(temp->getIdentificador()->get_val(), e2->get_val().substr(14, e1->get_val().length())) == false)
                            {
                                text += "invalid datatype: " + temp->getIdentificador()->get_val() +"\n";
                            }

                        }else
                        {
                            if (tabla->searchCast(temp->getIdentificador()->get_val(), temp2->get_val()) == false)
                            {
                                text += "invalid datatype: " + temp->getIdentificador()->get_val() +"\n";
                            }
                        }


                    }

                }
            }
            text += BuscarSentencia(temp, padre, abuelo, tabla);

            i = true;
        }
        else
        {
            i = true;
        }
        if(aux2->getReferenciaDerecha())
        {
            temp = aux2->getReferenciaDerecha();
            if(temp->getValor() == abuelo)
            {

                if(temp->get_val() == padre)
                {
                    temp = temp->getReferenciaCentro();

                    temp2 = temp->getReferenciaCentro();

                    cout << temp->get_val() << endl;

                    if(temp->get_val() == " if  (  ) <Expresion> <SentenciaBloque> <Otro>")
                    {
                        temp3  = temp->getReferenciaIzquierda();


                        cout << "Lo he arreglado: aqui van las condicionales" << temp3->get_val() << endl;

                        if(temp3->get_val() == "<Expresion>  < <Expresion>")
                        {
                            e1 = temp3->getReferenciaDerecha();

                            e2 = temp3->getReferenciaIzquierda();

                            cout << e1->get_val().substr(14, e1->get_val().length()) << " " << e2->get_val().substr(14, e1->get_val().length());

                            if (tabla->searchExist(e1->get_val().substr(14, e1->get_val().length())) == false)
                            {
                                text += "Not declared: " + e1->get_val().substr(14, e1->get_val().length()) +"\n";

                                if(tabla->searchExist(e2->get_val().substr(14, e2->get_val().length())) == false)
                                {

                                    text += "Not declared: " + e2->get_val().substr(14, e2->get_val().length()) +"\n";
                                }

                            }else
                            {
                                if(tabla->searchExist(e2->get_val().substr(14, e2->get_val().length())) == false)
                                {

                                    text += "Not declared: " + e2->get_val().substr(14, e2->get_val().length()) +"\n";
                                }else
                                {

                                    if(tabla->searchType( e1->get_val().substr(13, e1->get_val().length()),  e2->get_val().substr(13, e1->get_val().length())) == false)
                                    {
                                        text += "invalid datatype: " + e2->get_val().substr(14, e2->get_val().length()) + " " + e1->get_val().substr(14, e2->get_val().length()) + "\n";
                                    }


                                }

                            }

                        }else
                        {
                            cout << "More methods" << endl;
                        }



                    }else
                    {

                        if(temp2->get_val() == "<Expresion>  + <Expresion>" or temp2->get_val() == "<Expresion>  - <Expresion>" or temp2->get_val() == "<Expresion>  * <Expresion>" or temp2->get_val() == "<Expresion>  / <Expresion>")
                        {
                            e1 = temp2->getReferenciaDerecha();

                            e2 = temp2->getReferenciaIzquierda();

                            cout << e1->get_val().substr(14, e1->get_val().length()) << " " << e2->get_val().substr(14, e1->get_val().length());

                            if (tabla->searchCast(temp->getIdentificador()->get_val(), e1->get_val().substr(14, e1->get_val().length())) == false or tabla->searchCast(temp->getIdentificador()->get_val(), e2->get_val().substr(14, e1->get_val().length())) == false)
                            {
                                text += "invalid datatype: " + temp->getIdentificador()->get_val() +"\n";
                            }

                        }else
                        {
                            if (tabla->searchCast(temp->getIdentificador()->get_val(), temp2->get_val()) == false)
                            {
                                text += "invalid datatype: " + temp->getIdentificador()->get_val() +"\n";
                            }
                        }


                    }
                }


            }

            text += BuscarSentencia(temp, padre, abuelo, tabla);

            d = true;
        }
        else
        {
            d = true;
        }
    }
    return text;

};

void ArbolSintactico::casteo(Tabsim* tabla, std::string& e)
{
    string out;
    Nodo *aux;

    aux = root->getReferencia();

    out += BuscarSentencia(aux, "<Sentencia>", "<DefLocal>", tabla);

    cout << out << endl;

    e = out;

};

void ArbolSintactico::uso(Tabsim* tabla, std::string& e)
{
    string out;
    Nodo *aux;

    aux = root->getReferencia();

    out += BuscarSentencia(aux, "<Sentencia>", "<DefLocal>", tabla);

    cout << out << endl;

    e = out;

};

void ArbolSintactico::analiza(Tabsim* tabla)
{
    //root->getReferencia()->validar();

    string out;
    Nodo *aux;

    aux = root->getReferencia();

    out += BuscarFuncion(aux, "<DefFunc>", "<Definicion>", tabla);

    //DefVar es padre, Definicion el abuelo

    out += BuscarVariables(aux, "<DefVar>", "<DefLocal>", tabla);

    out += BuscarVariables(aux, "<DefVar>", "<Definicion>", tabla);



};
