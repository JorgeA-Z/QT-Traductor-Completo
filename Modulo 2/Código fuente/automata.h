#ifndef AUTOMATA_H
#define AUTOMATA_H
#include <string>

class Automata
{
private:
    std::string cadena;
    int tamR = 33;
    std::string reservadas[33] = {
        "do", "while", "if",
        "auto","double","int","struct",
        "break","else","long","switch",
        "case","enum","register","typeof",
        "char","extern","return","union",
        "const","float","short","unsigned",
        "continue","signed","void",
        "default","goto","sizeof","volatile"};

    int tamOA = 6;
    std::string operadoresAritmeticos[6] = {
        "+","-","*","/","%","="};

    int tamOL = 3;
    std::string operadoresLogicos[3] = {
        "&&","||","!"};

    int tamAbecedario = 26;
    char abecedario[26] = {
        'a','b','c','d','e','f','g','h','i',
        'j','k','l','m','n','o','p','q','r',
        's','t','u','v','w','x','y','z'};

    int tamHexadecimal = 22;
    char hexadecimal[22] = {
        'a','b','c','d','e','f',
        'A','B','C','D','E','F',
        '0','1','2','3','4','5','6','7','8','9'};

    int tamNumeros = 10;
    char numeros[10] = {
        '0','1','2','3','4','5','6','7','8','9'};

    int tamSimbolos = 18;
    char simbolos[18] = {
        '_',',','-','?',')','(','#','|',
        ',',';','[',']','{','}','$','&','>','<'};

    std::string resultados[11] = {
        "Reservadas","Aritmeticos","Logicos","Identificador",
        "Hexadecimal","Float","Int","Arreglo","Identificador", "Simbolo", "No_identificado"};

    std::string Tipos[8] = {
        "double","int","long","char","const","float","short","unsigned"};

    int tamRelacionales = 5;
    std::string Relacionales[5] = {
        "<=", ">=", "!=", "<", ">"};

public:
    Automata();
    Automata(std::string&);
    ~Automata();

    void setCadena(std::string&);
    std::string getCadena();

    bool EstaDentro(std::string x[], std::string y, int tam);
    bool EstaDentroChar(char x[], char y, int tam);

    int Casos(std::string, int obtenido);
    int Analizar(std::string&);
    int FastStep(std::string&, std::string lista1[], std::string lista2[], std::string lista3[]);
    std::string identificar(std::string&);

};

#endif // AUTOMATA_H
