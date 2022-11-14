#ifndef REGLAS_H
#define REGLAS_H
#include "nt.h"
#include "t.h"
class R1: public Nodo
{

private:
        NT* definiciones;

public:
    R1();
    R1(NT*);
    std::string get_val();
    NT* getDefiniciones();
};

class R2: public Nodo
{

public:
    R2();
};

class R3: public Nodo
{
private:
    NT* definicion;
    NT* definiciones;
public:
    R3();
    R3(NT*, NT*);
    NT* getDefiniciones();
    NT* getDefinicion();
    std::string get_val();
};

class R4: public Nodo
{
private:
    NT* defvar;
public:
    R4();
    R4(NT*);
    NT* getDefvar();
    std::string get_val();
};

class R5: public Nodo
{
private:
    NT* defFunc;
public:
    R5();
    R5(NT*);
    NT* getDefFunc();
    std::string get_val();
};

class R6: public Nodo
{
private:
    T* tipo;

    T* id;

    NT* listvar;

    T* pc;

public:
    R6();
    R6(T*, T*, NT*, T*);
    T* getTipo();
    T* getID();
    T* getPC();
    NT* getLisvar();
    std::string get_val();
    void validar();
};

class R7: public Nodo
{
public:
    R7();
};

class R8: public Nodo
{
private:
    T* coma;
    T* identificador;
    NT* lisvar;
public:
    R8();
    R8(T*, T*, NT*);
    T* getComa();
    T* getIdentificador();
    NT* getLisvar();
    std::string get_val();
};

class R9: public Nodo
{
private:
    T* tipo;
    T* identificador;
    T* parentesisI;
    T* parentesisO;
    NT* parametros;
    NT* blockfunc;

public:
    R9();
    R9(T*, T*, T*, T*, NT*, NT*);
    T* gettipo();
    T* getidentificador();
    T* getparentesisI();
    T* getparentesisO();
    NT* getparametros();
    NT* getblockfunc();
    std::string get_val();
};

class R10: public Nodo
{
public:
    R10();
};

class R11: public Nodo
{
private:
    T* tipo;
    T* identificador;
    NT* lisparam;

public:
    R11();
    R11(T*, T*, NT*);
    T* getTipo();
    T* getIdentificador();
    NT* getLisparam();
    std::string get_val();
};

class R12: public Nodo
{
public:
    R12();
};

class R13: public Nodo
{
private:
    T* coma;
    T* tipo;
    T* identificador;
    NT* listaparam;
public:
    R13();
    R13(T*, T*, T*, NT*);
    T* getComa();
    T* getTipo();
    T* getIdentificador();
    NT* getListaparam();
    std::string get_val();
};

class R14: public Nodo
{
private:
    T* parentesisI;
    NT* deflocales;
    T* parentesisO;
public:
    R14();
    R14(T*, NT*, T*);
    T* getParentesisI();
    NT* getDeflocales();
    T* getParentesisO();
    std::string get_val();
};

class R15: public Nodo
{
public:
    R15();
};

class R16: public Nodo
{
private:
    NT* deflocal;
    NT* deflocales;
public:
    R16();
    R16(NT*, NT*);
    NT* getDeflocal();
    NT* getDeflocales();
    std::string get_val();
};

class R17: public Nodo
{
private:
    NT* defvar;
public:
    R17();
    R17(NT*);
    NT* getDefvar();
    std::string get_val();
};

class R18: public Nodo
{
private:
    NT* sentencia;
public:
    R18();
    R18(NT*);
    NT* getSentencia();
    std::string get_val();
};

class R19: public Nodo
{
public:
    R19();
};

class R20: public Nodo
{
    NT* sentencia;
    NT* sentencias;
public:
    R20();
    R20(NT*, NT*);
    NT* getSentencia();
    NT* getSentencias();
    std::string get_val();
};

class R21: public Nodo
{
private:
    T* identificador;
    T* igual;
    NT* expresion;
    T* pc;

public:
    R21();
    R21(T*, T*, NT*, T*);
    T* getIdentificador();
    T* getIgual();
    NT* getExpresion();
    T* getPc();
    std::string get_val();
};

class R22: public Nodo
{
private:
    T* _if;
    T* parentesisI;
    T* parentesisO;
    NT* expresion;
    NT* sentencia;
    NT* otro;
public:
    R22();
    R22(T*, T*,T*, NT*, NT* ,NT*);
    T* get_if();
    T* getParentesisI();
    T* getParentesisO();
    NT* getExpresion();
    NT* getSentencia();
    NT* getOtro();
    std::string get_val();
};

class R23: public Nodo
{
private:
     T* _while;
     T* parentesisi;
     NT* expresion;
     T* parentesiso;
     NT* bloque;
public:
    R23();
    R23(T*, T*, NT* ,T*, NT*);
    T* getWhile();
    T* getParentesisi();
    NT* getExpresion();
    T* getParentesiso();
    NT* getBloque();
    std::string get_val();
};

class R24: public Nodo
{

private:
    T* _return;
    NT* valorRegresa;
    T* pc;
public:
    R24();
    R24(T*, NT*, T*);
    T* getReturn();
    NT* getValorRegresa();
    T* getPc();
    std::string get_val();
};

class R25: public Nodo
{
private:
    NT* llamadaFunc;
public:
    R25();
    R25(NT*);
    NT* getLlamadaFunc();
    std::string get_val();

};

class R26: public Nodo
{
public:
    R26();
};

class R27: public Nodo
{
    private:
        T* _else;
        NT* sentenciaBloque;

    public:
        R27();
        R27(T*, NT*);
        T* getElse();
        NT* getSentenciaBloque();
        std::string get_val();
};

class R28: public Nodo
{
    private:
        T* corcheteAbre;
        NT* sentencias;
        T* corcheteCierre;

    public:
        R28();
        R28(T*, NT*, T*);
        T* getCorcheteAbre();
        NT* getSentencias();
        T* getCorcheteCierre();
        std::string get_val();
};

class R29: public Nodo
{
    private:

    public:
        R29();

};

class R30: public Nodo
{
    private:
        NT* expresion;

    public:
        R30();
        R30(NT*);
        NT* getExpresion();
        std::string get_val();
};

class R31: public Nodo
{
    private:

    public:
        R31();
};

class R32: public Nodo
{
    private:
        NT* expresion;
        NT* listaArgumentos;

    public:
        R32();
        R32(NT*, NT*);
        NT* getExpresion();
        NT* getListaArgumentos();
        std::string get_val();
};

class R33: public Nodo
{
    private:

    public:
        R33();

};

class R34: public Nodo
{
    private:
        T* coma;
        NT* expresion;
        NT* listaArgumentos;

    public:
        R34();
        R34(T*, NT*, NT*);
        T* getComa();
        NT* getExpresion();
        NT* getListaArgumentos();
        std::string get_val();

};

class R35: public Nodo
{
    private:
        NT* llamadaFunc;

    public:
        R35();
        R35(NT*);
        NT* getLlamadaFunc();
        std::string get_val();
};

class R36: public Nodo
{
    private:
        T* identificador;

    public:
        R36();
        R36(T*);
        T* getIdentificador();
        std::string get_val();
};

class R37: public Nodo
{
    private:
        T* entero;

    public:
        R37();
        R37(T*);
        T* getEntero();
        std::string get_val();
};

class R38: public Nodo
{
    private:
        T* real;

    public:
        R38();
        R38(T*);
        T* getReal();
        std::string get_val();
};

class R39: public Nodo
{
    private:
        T* cadena;

    public:
        R39();
        R39(T*);
        T* getCadena();
        std::string get_val();
};

class R40: public Nodo
{
    private:
        T* identificador;
        T* parentesisAbrir;
        NT* argumentos;
        T* parentesisCerrar;

    public:
        R40();
        R40(T*, T*, NT*, T*);
        T* getIdentificador();
        T* getParentesisAbrir();
        NT* getArgumentos();
        T* getParentesisCerrar();
        std::string get_val();
};

class R41: public Nodo
{
    private:
        NT* sentencia;

    public:
        R41();
        R41(NT*);
        NT* getSentencia();
        std::string get_val();
};

class R42: public Nodo
{
    private:
        NT* bloque;

    public:
        R42();
        R42(NT*);
        NT* getBloque();
        std::string get_val();
};

class R43: public Nodo
{
    private:
        T* parentesisAbrir;
        NT* expresion;
        T* parentesisCerrar;

    public:
        R43();
        R43(T*, NT*, T*);
        T* getParentesisAbrir();
        NT* getExpresion();
        T* getParentesisCerrar();
        std::string get_val();
};

class R44: public Nodo
{
    private:
        T* opSuma;
        NT* expresion;

    public:
        R44();
        R44(T*, NT*);
        T* getOpSuma();
        NT* getExpresion();
        std::string get_val();
};

class R45: public Nodo
{
    private:
        T* opNot;
        NT* expresion;

    public:
        R45();
        R45(T*, NT*);
        T* getOpNot();
        NT* getExpresion();
        std::string get_val();
};

class R46: public Nodo
{
    private:
        NT* expresion1;
        T* opMul;
        NT* expresion2;

    public:
        R46();
        R46(NT*, T*, NT*);
        NT* getExpresion1();
        T* getOpMul();
        NT* getExpresion2();
        std::string get_val();
};

class R47: public Nodo
{
    private:
        NT* expresion1;
        T* opSuma;
        NT* expresion2;

    public:
        R47();
        R47(NT*, T*, NT*);
        NT* getExpresion1();
        T* getOpSuma();
        NT* getExpresion2();
        std::string get_val();
};

class R48: public Nodo
{
    private:
        NT* expresion1;
        T* opRelac;
        NT* expresion2;

    public:
        R48();
        R48(NT*, T*, NT*);
        NT* getExpresion1();
        T* getOpRelac();
        NT* getExpresion2();
        std::string get_val();
};

class R49: public Nodo
{
    private:
        NT* expresion1;
        T* opIgualdad;
        NT* expresion2;

    public:
        R49();
        R49(NT*, T*, NT*);
        NT* getExpresion1();
        T* getOpIgualdad();
        NT* getExpresion2();
        std::string get_val();
        void validar();
};

class R50: public Nodo
{
    private:
        NT* expresion1;
        T* opAnd;
        NT* expresion2;

    public:
        R50();
        R50(NT*, T*, NT*);
        NT* getExpresion1();
        T* getOpAnd();
        NT* getExpresion2();
        std::string get_val();
};

class R51: public Nodo
{
    private:
        NT* expresion1;
        T* opOr;
        NT* expresion2;

    public:
        R51();
        R51(NT*, T*, NT*);
        NT* getExpresion1();
        T* getOpOr();
        NT* getExpresion2();
        std::string get_val();
};

class R52: public Nodo
{
    private:
        T* termino;

    public:
        R52();
        R52(T*);
        T* getTermino();
        std::string get_val();
};

#endif // REGLAS_H
