#include "reglas.h"


//r1

R1::R1()
{

};
R1::R1(NT*df)
{
    definiciones = df;


};
NT* R1::getDefiniciones()
{
    return definiciones;
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
};
NT* R3::getDefiniciones()
{
    return definicion;

};
NT* R3::getDefinicion()
{
    return definiciones;
};

//r4
R4::R4(){};
R4::R4(NT*df)
{
    defvar = df;
};
NT* R4::getDefvar()
{
    return defvar;
};

//r5

R5::R5(){};
R5::R5(NT*df)
{
    defFunc = df;
};
NT* R5::getDefFunc()
{
    return defFunc;
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
    out += tipo->get_val();
    out += " / ";
    out += id->get_val();
    out += " / ";
    out += listvar->get_val();
    out += " / ";
    out += pc->get_val();
    return out;
};
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

//r14

R14::R14(){};
R14::R14(T*pi, NT*df, T*po)
{
    parentesisI = pi;
    deflocales = df;
    parentesisO = po;
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
};
NT* R16::getDeflocal()
{
    return deflocal;
};
NT* R16::getDeflocales()
{
    return deflocales;
};

//r17

R17::R17(){};
R17::R17(NT*df)
{
    defvar = df;
};
NT* R17::getDefvar()
{
    return defvar;
};

//r18

R18::R18(){};
R18::R18(NT*df)
{
    sentencia = df;
};
NT* R18::getSentencia()
{
    return sentencia;
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
};
NT* R20::getSentencia()
{
    return sentencia;
};
NT* R20::getSentencias()
{
    return sentencias;
};

//21

R21::R21(){};
R21::R21(T*id, T*equal, NT*E, T*p)
{
    identificador = id;
    igual = equal;
    expresion = E;
    pc = p;
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

//23
R23::R23(){};
R23::R23(T*w, T*pi, NT*e ,T*po, NT*b)
{
    _while = w;
    parentesisi = pi;
    expresion = e;
    parentesiso = po;
    bloque = b;
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

//24

R24::R24(){};
R24::R24(T*r, NT*v, T*p)
{
    _return = r;
    valorRegresa = v;
    pc = p;
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

//25

R25::R25(){};
R25::R25(NT*ll)
{
    llamadaFunc = ll;
};
NT* R25::getLlamadaFunc()
{
    return llamadaFunc;
};

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
};
T* R27::getElse()
{
    return _else;
};
NT* R27::getSentenciaBloque()
{
    return sentenciaBloque;
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
};
NT* R30::getExpresion()
{
    return expresion;
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
};
NT* R32::getExpresion()
{
    return expresion;
};
NT* R32::getListaArgumentos()
{
    return listaArgumentos;
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

//R35
R35::R35()
{

};
R35::R35(NT*l)
{
    llamadaFunc = l;
};
NT* R35::getLlamadaFunc()
{
    return llamadaFunc;
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

//R41
R41::R41()
{

};
R41::R41(NT*s)
{
    sentencia = s;
};
NT* R41::getSentencia()
{
    return sentencia;
};

//R42
R42::R42()
{

};
R42::R42(NT*b)
{
    bloque = b;
};
NT* R42::getBloque()
{
    return bloque;
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

//R44
R44::R44()
{

};
R44::R44(T*o, NT*e)
{
    opSuma = o;
    expresion = e;
};
T* R44::getOpSuma()
{
    return opSuma;
};
NT* R44::getExpresion()
{
    return expresion;
};

//R45
R45::R45()
{

};
R45::R45(T*o, NT*e)
{
    opNot = o;
    expresion = e;
};
T* R45::getOpNot()
{
    return opNot;
};
NT* R45::getExpresion()
{
    return expresion;
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

//R47
R47::R47()
{

};
R47::R47(NT* e1, T* o, NT* e2)
{
    expresion1 = e1;
    opSuma = o;
    expresion2 = e2;
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

//R48
R48::R48()
{

};
R48::R48(NT* e1, T* o, NT* e2)
{
    expresion1 = e1;
    opRelac = o;
    expresion2 = e2;
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

//R49
R49::R49()
{

};
R49::R49(NT* e1, T* o, NT* e2)
{
    expresion1 = e1;
    opIgualdad = o;
    expresion2 = e2;
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

//R50
R50::R50()
{

};
R50::R50(NT* e1, T* o, NT* e2)
{
    expresion1 = e1;
    opAnd = o;
    expresion2 = e2;
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

//R51
R51::R51()
{

};
R51::R51(NT* e1, T* o, NT* e2)
{
    expresion1 = e1;
    opOr = o;
    expresion2 = e2;
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

