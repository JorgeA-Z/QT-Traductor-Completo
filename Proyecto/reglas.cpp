#include "reglas.h"
#include <iostream>
using namespace std;

//r1

R1::R1()
{

};
R1::R1(NT*df)
{
    definiciones = df;
    centro = definiciones->getReferencia();
};
NT* R1::getDefiniciones()
{
    return definiciones;
};
std::string R1::get_val()
{
    return definiciones->get_val();
};
//r2
R2::R2()
{

};

//r3

R3::R3(){};
R3::R3(NT*def, NT*defs)
{
    definicion = def;
    definiciones = defs;

    izquierda = definicion->getReferencia();
    izquierda->setValor(definicion->get_val());
    derecha = definiciones->getReferencia();
    derecha->setValor(definiciones->get_val());
};
NT* R3::getDefiniciones()
{
    return definicion;

};
NT* R3::getDefinicion()
{
    return definiciones;
};
std::string R3::get_val()
{
    return definicion->get_val() + " " +definiciones->get_val();
};

//r4
R4::R4(){};
R4::R4(NT*df)
{
    defvar = df;
    centro = defvar->getReferencia();
    centro->setValor(defvar->get_val());
};
NT* R4::getDefvar()
{
    return defvar;
};
std::string R4::get_val()
{
    return  defvar->get_val();
};

//r5

R5::R5(){};
R5::R5(NT*df)
{
    defFunc = df;
    centro = defFunc->getReferencia();
    centro->setValor(defFunc->get_val());
};
NT* R5::getDefFunc()
{
    return defFunc;
};

std::string R5::get_val()
{
    return  defFunc->get_val();
};
//r6
R6::R6()
{
    tipo = nullptr;
    id = nullptr;
    listvar = nullptr;
    pc = nullptr;

};
R6::R6(T*t, T*i, NT*l, T*p)
{
    tipo = t;
    id = i;
    listvar = l;
    pc = p;

    centro = listvar->getReferencia();
    centro->setValor(listvar->get_val());

};
T* R6::getTipo()
{
    return tipo;
};
T* R6::getID()
{
    return id;
};
T* R6::getPC()
{
    return pc;
};
NT* R6::getLisvar()
{
    return listvar;
};
std::string R6::get_val()
{
    std::string out;
    out += "\n";
    out += tipo->get_val();
    out += " ";
    out += id->get_val();
    out += " ";
    out += listvar->get_val();
    out += " ";
    out += pc->get_val();
    return out;
};

void R6::validar()
{
    if(tipo->get_val() == " int")
    {
        tipoD = "i";
    }

    if(tipo->get_val() == " float")
    {
        tipoD = "f";

    }

    if(tipo->get_val() == " char")
    {
        tipoD = "c";

    }

    if(tipo->get_val() == " void")
    {
        tipoD = "v";

    }

    if(tipo->get_val() == " double")
    {
        tipoD = "d";

    }

    cout << tipoD << endl;

    if(centro != nullptr )
    {
        centro->validar();
    }

}
//r7

R7::R7()
{

}

//r8

R8::R8()
{

};
R8::R8(T*c, T*i, NT*l)
{
    coma = c;
    identificador = i;
    lisvar = l;
    centro = lisvar->getReferencia();
    centro->setValor(lisvar->get_val());

};
T* R8::getComa()
{
    return coma;
};
T* R8::getIdentificador()
{
    return identificador;
};
NT* R8::getLisvar()
{
    return lisvar;
};
std::string R8::get_val()
{
    return coma->get_val() + " " +identificador->get_val() + " " + lisvar->get_val();
};
//r9

R9::R9()
{

};
R9::R9(T*t, T*i, T*pi, T*po, NT*p, NT*b)
{
    tipo = t;
    identificador =i;
    parentesisI = pi;
    parentesisO = po;
    parametros = p;
    blockfunc= b;

    izquierda = parametros->getReferencia();
    izquierda->setValor(parametros->get_val());
    derecha = blockfunc->getReferencia();
    derecha->setValor(blockfunc->get_val());

};
T* R9::gettipo()
{
    return tipo;
};
T* R9::getidentificador()
{
    return identificador;
};
T* R9::getparentesisI()
{
    return parentesisI;
};
T* R9::getparentesisO()
{
    return parentesisO;
};
NT* R9::getparametros()
{
    return parametros;
};
NT* R9::getblockfunc()
{
    return blockfunc;
};

std::string R9::get_val()
{
    return tipo->get_val() + " " +identificador->get_val() + " " + parentesisI->get_val() + " " +parametros->get_val() + " " + parentesisO->get_val() + " " + blockfunc->get_val();
};

//r10

R10::R10()
{

};


//r11

R11::R11()
{

};
R11::R11(T*t, T*id, NT*lis)
{
    tipo = t;
    identificador = id;
    lisparam = lis;

    centro = lisparam->getReferencia();
    centro->setValor(lisparam->get_val());
};
T* R11::getTipo()
{
    return tipo;
};
T* R11::getIdentificador()
{
    return identificador;
};
NT* R11::getLisparam()
{
    return lisparam;
};

std::string R11::get_val()
{
    return tipo->get_val() + " " + identificador->get_val() + " " + lisparam->get_val();
};

//r12

R12::R12()
{

};

//r13
R13::R13()
{

};
R13::R13(T*c, T*t, T*i, NT*lp)
{
    coma = c;
    tipo = t;
    identificador = i;
    listaparam = lp;

    centro = listaparam->getReferencia();
    centro->setValor(listaparam->get_val());
};
T* R13::getComa()
{
    return coma;

};
T* R13::getTipo()
{
    return tipo;
};
T* R13::getIdentificador()
{
    return identificador;
};
NT* R13::getListaparam()
{
    return listaparam;
};

std::string R13::get_val()
{
    return coma->get_val() + " " + tipo->get_val() + " " + identificador->get_val() + " " + listaparam->get_val();
};

//r14

R14::R14(){};
R14::R14(T*pi, NT*df, T*po)
{
    parentesisI = pi;
    deflocales = df;
    parentesisO = po;

    centro = deflocales->getReferencia();
    centro->setValor(deflocales->get_val());
};
T* R14::getParentesisI()
{
    return parentesisI;
};
NT* R14::getDeflocales()
{
    return deflocales;
};
T* R14::getParentesisO()
{
    return parentesisO;
};

std::string R14::get_val()
{
    return parentesisI->get_val() + " " + deflocales->get_val() + " " +parentesisO->get_val();
};
//r15

R15::R15()
{

}

//r16

R16::R16(){};
R16::R16(NT* dfl, NT* dfls)
{
    deflocal = dfl;
    deflocales = dfls;

    izquierda = deflocal->getReferencia();
    izquierda->setValor(deflocal->get_val());
    derecha = deflocales->getReferencia();
    derecha->setValor(deflocales->get_val());

};
NT* R16::getDeflocal()
{
    return deflocal;
};
NT* R16::getDeflocales()
{
    return deflocales;
};
std::string R16::get_val()
{
    return deflocal->get_val() + " " + deflocales->get_val();
}

//r17

R17::R17(){};
R17::R17(NT*df)
{
    defvar = df;
    centro = defvar->getReferencia();
    centro->setValor(defvar->get_val());
};
NT* R17::getDefvar()
{
    return defvar;
};

std::string R17::get_val()
{
    return defvar->get_val();
}

//r18

R18::R18(){};
R18::R18(NT*df)
{
    sentencia = df;
    centro = sentencia->getReferencia();
    centro->setValor(sentencia->get_val());
};
NT* R18::getSentencia()
{
    return sentencia;
};

std::string R18::get_val()
{
    return sentencia->get_val();
};

//r19
R19::R19()
{

};

//20

R20::R20()
{

};
R20::R20(NT*s, NT*ss)
{
    sentencia = s;
    sentencias = ss;

    izquierda = sentencia->getReferencia();
    izquierda->setValor(sentencia->get_val());
    derecha = sentencias->getReferencia();
    derecha->setValor(sentencias->get_val());

};
NT* R20::getSentencia()
{
    return sentencia;
};
NT* R20::getSentencias()
{
    return sentencias;
};
std::string R20::get_val()
{
    return sentencia->get_val() + " " + sentencias->get_val();
};

//21

R21::R21(){};
R21::R21(T*id, T*equal, NT*E, T*p)
{
    identificador = id;
    igual = equal;
    expresion = E;
    pc = p;

    centro = expresion->getReferencia();
    centro->setValor(expresion->get_val());
};
T* R21::getIdentificador()
{
    return identificador;

};
T* R21::getIgual()
{
    return igual;

};
NT* R21::getExpresion()
{
    return expresion;
};
T* R21::getPc()
{
    return pc;
};

std::string R21::get_val()
{
    return identificador->get_val() + " " + igual->get_val() + " " + expresion->get_val() +" " + pc->get_val();
};

//22

R22::R22(){};
R22::R22(T*i, T*pi,T*po, NT*e, NT*s ,NT*o)
{
    _if = i;
    parentesisI = pi;
    parentesisO = po;
    expresion = e;
    sentencia = s;
    otro = o;

    izquierda = expresion->getReferencia();
    izquierda->setValor(expresion->get_val());
    centro = sentencia->getReferencia();
    centro->setValor(sentencia->get_val());
    derecha = otro->getReferencia();
    derecha->setValor(otro->get_val());
};
T* R22::get_if()
{
    return _if;
};
T* R22::getParentesisI()
{
    return parentesisI;
};
T* R22::getParentesisO()
{
    return parentesisO;
};
NT* R22::getExpresion()
{
    return expresion;
};
NT* R22::getSentencia()
{
    return sentencia;
};
NT* R22::getOtro()
{
    return otro;
};
std::string R22::get_val()
{
    return _if->get_val() + " " + parentesisI->get_val() + " " + parentesisO->get_val() + " " + expresion->get_val() + " " + sentencia->get_val() + " "  + otro->get_val();
};
//23
R23::R23(){};
R23::R23(T*w, T*pi, NT*e ,T*po, NT*b)
{
    _while = w;
    parentesisi = pi;
    expresion = e;
    parentesiso = po;
    bloque = b;

    izquierda = expresion->getReferencia();
    izquierda->setValor(expresion->get_val());
    derecha = bloque->getReferencia();
    derecha->setValor(bloque->get_val());
};
T* R23::getWhile()
{
    return _while;

};
T* R23::getParentesisi()
{
    return parentesisi;

};
NT* R23::getExpresion()
{
    return expresion;

};
T* R23::getParentesiso()
{
    return parentesiso;

};
NT* R23::getBloque()
{
    return bloque;
};
std::string R23::get_val()
{
    return _while->get_val() + " " + parentesisi->get_val() +  " " + expresion->get_val() + " " + parentesiso->get_val() + " " + bloque->get_val();

};
//24

R24::R24(){};
R24::R24(T*r, NT*v, T*p)
{
    _return = r;
    valorRegresa = v;
    pc = p;

    centro = valorRegresa->getReferencia();
    centro->setValor(valorRegresa->get_val());
};
T* R24::getReturn()
{
   return _return;

};
NT* R24::getValorRegresa()
{
    return valorRegresa;

};
T* R24::getPc()
{
    return pc;
};
std::string R24::get_val()
{

    return _return->get_val() + " " + valorRegresa->get_val() + " " + pc ->get_val();
};
//25

R25::R25(){};
R25::R25(NT*ll)
{
    llamadaFunc = ll;
    centro = llamadaFunc->getReferencia();
    centro->setValor(llamadaFunc->get_val());
};
NT* R25::getLlamadaFunc()
{
    return llamadaFunc;
};
std::string R25::get_val()
{
    return llamadaFunc->get_val();
}
//26
R26::R26()
{

};

//R27
R27::R27()
{

};
R27::R27(T*e, NT*s)
{
    _else = e;
    sentenciaBloque = s;

    centro = sentenciaBloque->getReferencia();
    centro->setValor(sentenciaBloque->get_val());
};
T* R27::getElse()
{
    return _else;
};
NT* R27::getSentenciaBloque()
{
    return sentenciaBloque;
};
std::string R27::get_val()
{
    return _else->get_val() + " " + sentenciaBloque->get_val();
};
//R28
R28::R28()
{

};
R28::R28(T*c1, NT*s, T*c2)
{
    corcheteAbre = c1;
    sentencias = s;
    corcheteCierre = c2;

    centro = sentencias->getReferencia();
    centro->setValor(sentencias->get_val());
};
T* R28::getCorcheteAbre()
{
    return corcheteAbre;
};
NT* R28::getSentencias()
{
    return sentencias;
};
T* R28::getCorcheteCierre()
{
    return corcheteCierre;
};
std::string R28::get_val()
{
    return corcheteAbre->get_val() + " " +sentencias->get_val() + " " +corcheteCierre->get_val();
};
//R29
R29::R29()
{

};

//R30
R30::R30()
{

};
R30::R30(NT* e)
{
    expresion = e;

    centro = expresion->getReferencia();
    centro->setValor(expresion->get_val());
};
NT* R30::getExpresion()
{
    return expresion;
};
std::string R30::get_val()
{
    return expresion->get_val();
};

//R31
R31::R31()
{

};

//R32
R32::R32()
{

};
R32::R32(NT*e, NT*l)
{
    expresion = e;
    listaArgumentos = l;

    izquierda = expresion->getReferencia();
    izquierda->setValor(expresion->get_val());
    derecha = listaArgumentos->getReferencia();
    derecha->setValor(listaArgumentos->get_val());

};
NT* R32::getExpresion()
{
    return expresion;
};
NT* R32::getListaArgumentos()
{
    return listaArgumentos;
};
std::string R32::get_val()
{
    return expresion->get_val() + " " +listaArgumentos->get_val();
};
//R33
R33::R33()
{

};

//R34
R34::R34()
{

};
R34::R34(T*c, NT*e ,NT*l )
{
    coma = c;
    expresion = e;
    listaArgumentos = l;

    izquierda = expresion->getReferencia();
    izquierda->setValor(expresion->get_val());
    derecha = listaArgumentos->getReferencia();
    derecha->setValor(listaArgumentos->get_val());

};
T* R34::getComa()
{
    return coma;
};
NT* R34::getExpresion()
{
    return expresion;
};
NT* R34::getListaArgumentos()
{
    return listaArgumentos;
};
std::string R34::get_val()
{
    return coma->get_val() + expresion->get_val() + listaArgumentos->get_val();
};

//R35
R35::R35()
{

};
R35::R35(NT*l)
{
    llamadaFunc = l;
    centro = llamadaFunc->getReferencia();
    centro->setValor(llamadaFunc->get_val());

};
NT* R35::getLlamadaFunc()
{
    return llamadaFunc;
};
std::string R35::get_val()
{
    return llamadaFunc->get_val();
};

//R36
R36::R36()
{

};
R36::R36(T*i)
{
    identificador = i;
};
T* R36::getIdentificador()
{
    return identificador;
};
std::string R36::get_val()
{
    return identificador->get_val();
};

//R37
R37::R37()
{

};
R37::R37(T*e)
{
    entero = e;
};
T* R37::getEntero()
{
    return entero;
};
std::string R37::get_val()
{
    return  entero->get_val();
};
//R38
R38::R38()
{

};
R38::R38(T*r)
{
    real = r;
};
T* R38::getReal()
{
    return real;
};
std::string R38::get_val()
{
    return real->get_val();
};
//R39
R39::R39()
{

};
R39::R39(T*c)
{
    cadena = c;
};
T* R39::getCadena()
{
    return cadena;
};
std::string R39::get_val()
{
    return cadena->get_val();
};
//R40
R40::R40()
{

};
R40::R40(T*i, T*p1, NT*a, T*p2)
{
    identificador = i;
    parentesisAbrir = p1;
    argumentos = a;
    parentesisCerrar = p2;

    centro = argumentos->getReferencia();
    centro->setValor(argumentos->get_val());
};
T* R40::getIdentificador()
{
    return identificador;
};
T* R40::getParentesisAbrir()
{
    return parentesisAbrir;
};
NT* R40::getArgumentos()
{
    return argumentos;
};
T* R40::getParentesisCerrar()
{
    return parentesisCerrar;
};
std::string R40::get_val()
{
    return identificador->get_val() + " " + parentesisAbrir->get_val()+ " " + argumentos->get_val()+ " " +parentesisCerrar->get_val();
};
//R41
R41::R41()
{

};
R41::R41(NT*s)
{
    sentencia = s;
    centro = sentencia->getReferencia();
};
NT* R41::getSentencia()
{
    return sentencia;
};
std::string R41::get_val()
{
    return sentencia->get_val();
};
//R42
R42::R42()
{

};
R42::R42(NT*b)
{
    bloque = b;
    centro = bloque->getReferencia();
    centro->setValor(bloque->get_val());
};
NT* R42::getBloque()
{
    return bloque;
};
std::string R42::get_val()
{
    return bloque->get_val();
};
//R43
R43::R43()
{

};
R43::R43(T*p1, NT*e, T*p2)
{
    parentesisAbrir = p1;
    expresion = e;
    parentesisCerrar = p2;

    centro = expresion->getReferencia();
    centro->setValor(expresion->get_val());
};
T* R43::getParentesisAbrir()
{
    return parentesisAbrir;
};
NT* R43::getExpresion()
{
    return expresion;
};
T* R43::getParentesisCerrar()
{
    return parentesisCerrar;
};
std::string R43::get_val()
{
    return parentesisAbrir->get_val() + " " + expresion->get_val() + " " + parentesisCerrar->get_val();
};
//R44
R44::R44()
{

};
R44::R44(T*o, NT*e)
{
    opSuma = o;
    expresion = e;
    centro = expresion->getReferencia();
    centro->setValor(expresion->get_val());
};
T* R44::getOpSuma()
{
    return opSuma;
};
NT* R44::getExpresion()
{
    return expresion;
};
std::string R44::get_val()
{
    return opSuma->get_val() + " " + expresion->get_val();
};
//R45
R45::R45()
{

};
R45::R45(T*o, NT*e)
{
    opNot = o;
    expresion = e;
    centro = expresion->getReferencia();
    centro->setValor(expresion->get_val());
};
T* R45::getOpNot()
{
    return opNot;
};
NT* R45::getExpresion()
{
    return expresion;
};
std::string R45::get_val()
{
    return opNot->get_val() + " " + expresion->get_val();
};
//R46
R46::R46()
{

};
R46::R46(NT* e1, T* o, NT* e2)
{
    expresion1 = e1;
    opMul = o;
    expresion2 = e2;

    izquierda = expresion1->getReferencia();
    izquierda->setValor(expresion1->get_val());
    derecha = expresion2->getReferencia();
    derecha->setValor(expresion2->get_val());

};
NT* R46::getExpresion1()
{
    return expresion1;
};
T* R46::getOpMul()
{
    return opMul;
};
NT* R46::getExpresion2()
{
    return expresion2;
};
std::string R46::get_val()
{
    return expresion1->get_val() + " " + opMul->get_val() + " " + expresion2->get_val();
};
//R47
R47::R47()
{

};
R47::R47(NT* e1, T* o, NT* e2)
{
    expresion1 = e1;
    opSuma = o;
    expresion2 = e2;

    izquierda = expresion1->getReferencia();
    izquierda->setValor(expresion1->get_val());
    derecha = expresion2->getReferencia();
    derecha->setValor(expresion2->get_val());
};
NT* R47::getExpresion1()
{
    return expresion1;
};
T* R47::getOpSuma()
{
    return opSuma;
};
NT* R47::getExpresion2()
{
    return expresion2;
};
std::string R47::get_val()
{
    return expresion1->get_val() + " " + opSuma->get_val() + " " + expresion2->get_val();
};

//R48
R48::R48()
{

};
R48::R48(NT* e1, T* o, NT* e2)
{
    expresion1 = e1;
    opRelac = o;
    expresion2 = e2;

    izquierda = expresion1->getReferencia();
    izquierda->setValor(expresion1->get_val());
    derecha = expresion2->getReferencia();
    derecha->setValor(expresion2->get_val());
};
NT* R48::getExpresion1()
{
    return expresion1;
};
T* R48::getOpRelac()
{
    return opRelac;
};
NT* R48::getExpresion2()
{
    return expresion2;
};
std::string R48::get_val()
{
    return expresion1->get_val() + " " + opRelac->get_val() + " " + expresion2->get_val();
};

//R49
R49::R49()
{

};
R49::R49(NT* e1, T* o, NT* e2)
{
    expresion1 = e1;
    opIgualdad = o;
    expresion2 = e2;

    izquierda = expresion1->getReferencia();
    izquierda->setValor(expresion1->get_val());
    derecha = expresion2->getReferencia();
    derecha->setValor(expresion2->get_val());
};
NT* R49::getExpresion1()
{
    return expresion1;
};
T* R49::getOpIgualdad()
{
    return opIgualdad;
};
NT* R49::getExpresion2()
{
    return expresion2;
};

std::string R49::get_val()
{
    return expresion1->get_val() + " " + opIgualdad->get_val() + " " + expresion2->get_val();
};

void R49::validar()
{

    if(izquierda != nullptr )
    {
        centro->validar();
    }


    if(derecha != nullptr )
    {
        centro->validar();
    }
}
//R50
R50::R50()
{

};
R50::R50(NT* e1, T* o, NT* e2)
{
    expresion1 = e1;
    opAnd = o;
    expresion2 = e2;

    izquierda = expresion1->getReferencia();
    izquierda->setValor(expresion1->get_val());
    derecha = expresion2->getReferencia();
    derecha->setValor(expresion2->get_val());

};
NT* R50::getExpresion1()
{
    return expresion1;
};
T* R50::getOpAnd()
{
    return opAnd;
};
NT* R50::getExpresion2()
{
    return expresion2;
};
std::string R50::get_val()
{
    return expresion1->get_val() + " " + opAnd->get_val() + " " + expresion2->get_val();
};

//R51
R51::R51()
{

};
R51::R51(NT* e1, T* o, NT* e2)
{
    expresion1 = e1;
    opOr = o;
    expresion2 = e2;

    izquierda = expresion1->getReferencia();
    izquierda->setValor(expresion1->get_val());
    derecha = expresion2->getReferencia();
    derecha->setValor(expresion2->get_val());

};
NT* R51::getExpresion1()
{
    return expresion1;
};
T* R51::getOpOr()
{
    return opOr;
};
NT* R51::getExpresion2()
{
    return expresion2;
};
std::string R51::get_val()
{
    return expresion1->get_val() + " " + opOr->get_val() + " " + expresion2->get_val();
};
//R52
R52::R52()
{

};
R52::R52(T*t)
{
    termino = t;
};
T* R52::getTermino()
{
    return termino;
};
std::string R52::get_val()
{
    return termino->get_val();
};
