#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>
#include <iostream>
#include <QDebug>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    setFixedSize(width(), height());
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(Lista()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::RunPila(Pila& pila, std::string& programa)
{

    std::cout << programa << std::endl;
  
    EP* elemento;

    int fila, columna;
    elemento = new T("$");

    pila.push(elemento);

    elemento = new T("0");

    pila.push(elemento);


    //El numero que está en el tope de la fila + el número del identificador
    //int|Reservadas|4 main|Identificador|0 (|Simbolo|14 )|Simbolo|15 {|Simbolo|16 }|Simbolo|17

    int i = 0, j, control, accion, t, p;
    char c;
    std::string data, tipo, token;
    bool llave = false, parcing = true;
    while (parcing)
    {

        c = programa[i];

        switch(c)
        {
            case ' ':
                //data = int|Reservadas|4
                j = 0;
                control = 0;
                llave = false;
                while(j < data.length())
                {

                    if(control == 1 && llave == false)
                    {
                        llave = true;
                        token = data.substr(0, j - 1);

                    }
                    if(control == 2)
                    {
                        tipo = data.substr(j, data.length() - j + 1);
                        break;
                    }
                    if(data[j] == '|')
                    {
                        control++;
                    }
                    j++;
                }
                //Aplicar el algoritmo
                fila = stoi(pila.Top()->get_val());
                
                columna = stoi(tipo);
                
                
                accion = LR[fila][columna];

                std::cout << fila << " " << columna << " " << accion <<std::endl;

                if(accion < 0)
                {
                    switch(accion)
                    {
                        case -1:

                        std::cout << "Analisis completado"  <<std::endl;

                        parcing = false;

                        i--;

                        break;

                        
                        case -2:
                        //R1

                        PopPila(1, pila);

                        fila = stoi(pila.Top()->get_val());

                        elemento = new T("<programa>");

                        pila.push(elemento);

                        accion = LR[fila][24];

                        elemento = new T(to_string(accion));

                        pila.push(elemento);
                        i--;
                        
                        break;
                        
                        case -3:
                        //R2
                        PopPila(0, pila);

                        fila = stoi(pila.Top()->get_val());

                        elemento = new T("<Definiciones>");

                        pila.push(elemento);

                        accion = LR[fila][25];

                        elemento = new T(to_string(accion));

                        pila.push(elemento);

                        i--;
                        break;

                        case -4:
                        //R3
                        PopPila(2, pila);

                        fila = stoi(pila.Top()->get_val());

                        elemento = new T("<Definiciones>");

                        pila.push(elemento);

                        accion = LR[fila][25];

                        elemento = new T(to_string(accion));

                        pila.push(elemento);
                        i--;

                        break;

                        case -5:
                        //R4
                        PopPila(1, pila);

                        fila = stoi(pila.Top()->get_val());

                        elemento = new T("<Definicion>");

                        pila.push(elemento);

                        accion = LR[fila][26];

                        elemento = new T(to_string(accion));

                        pila.push(elemento);

                        std::cout << token << std::endl;

                        i--;
                        break;

                        case -6:
                        //R5

                        PopPila(1, pila);

                        fila = stoi(pila.Top()->get_val());

                        elemento = new T("<Definicion>");

                        pila.push(elemento);

                        accion = LR[fila][26];

                        elemento = new T(to_string(accion));

                        pila.push(elemento);

                        i--;
                        break;

                        case -7:
                        //R6
                        PopPila(4, pila);

                        fila = stoi(pila.Top()->get_val());

                        elemento = new T("<DefVar>");

                        pila.push(elemento);

                        accion = LR[fila][27];

                        elemento = new T(to_string(accion));

                        pila.push(elemento);

                        std::cout << token << std::endl;

                        i--;

                        break;
                        
                        case -8:
                        //R7

                        PopPila(0, pila);

                        fila = stoi(pila.Top()->get_val());

                        elemento = new T("<ListaVar>");

                        pila.push(elemento);

                        accion = LR[fila][28];

                        elemento = new T(to_string(accion));

                        pila.push(elemento);

                        std::cout << token << std::endl;
                        i--;



                        break;
                        
                        case -9:
                        //R8

                        i--;
                        break;
                        
                        case -10:
                        //R9
                        PopPila(6, pila);

                        fila = stoi(pila.Top()->get_val());

                        elemento = new T("<DefFunc>");

                        pila.push(elemento);

                        accion = LR[fila][29];

                        elemento = new T(to_string(accion));

                        pila.push(elemento);
                        i--;

                        break;
                        
                        case -11:
                        //R10

                        PopPila(0, pila);

                        fila = stoi(pila.Top()->get_val());

                        elemento = new T("<Parametros>");

                        pila.push(elemento);

                        accion = LR[fila][30];

                        elemento = new T(to_string(accion));

                        pila.push(elemento);
                        i--;

                        break;
                        
                        case -12:
                        //R11
                        i--;

                        break;
                        
                        case -13:
                        //R12
                        i--;

                        break;
                        
                        case -14:
                        //R13
                        i--;

                        break;
                        
                        case -15:
                        //R14

                        PopPila(3, pila);

                        fila = stoi(pila.Top()->get_val());

                        elemento = new T("<BloqFunc>");

                        pila.push(elemento);

                        accion = LR[fila][32];

                        elemento = new T(to_string(accion));

                        pila.push(elemento);

                        i--;

                        break;
                        
                        case -16:
                        //R15
                        PopPila(0, pila);

                        fila = stoi(pila.Top()->get_val());

                        elemento = new T("<DefLocales>");

                        pila.push(elemento);

                        accion = LR[fila][33];

                        elemento = new T(to_string(accion));

                        pila.push(elemento);

                        i--;

                        break;

                        
                        case -17:
                        //R16
                        PopPila(2, pila);

                        fila = stoi(pila.Top()->get_val());

                        elemento = new T("<DefLocales>");

                        pila.push(elemento);

                        accion = LR[fila][33];

                        elemento = new T(to_string(accion));

                        pila.push(elemento);
                        i--;

                        break;

                        
                        case -18:
                        //R17
                        PopPila(1, pila);

                        fila = stoi(pila.Top()->get_val());

                        elemento = new T("<DefLocal>");

                        pila.push(elemento);

                        accion = LR[fila][34];

                        elemento = new T(to_string(accion));

                        pila.push(elemento);

                        i--;

                        break;


                        
                        case -19:
                        //R18
                        i--;

                        break;

                        
                        case -20:
                        //R19

                        i--;
                        break;

                        
                        case -21:
                        //R20
                        i--;

                        break;

                        
                        case -22:
                        //R21
                        i--;

                        break;

                        case -23:
                        //R22
                        i--;

                        break;
                        
                        case -24:
                        //R23
                        i--;

                        break;

                        case -25:
                        //R24
                        i--;

                        break;

                        case -26:
                        //R25
                        i--;

                        break;

                        case -27:
                        //R26
                        i--;

                        break;

                        case -28:
                        //R27
                        i--;

                        break;

                        case -29:
                        //R28
                        i--;

                        break;

                        case -30:
                        //R29
                        i--;

                        break;

                        case -31:
                        //R30
                        i--;

                        break;
                        
                        case -32:
                        //R31
                        i--;

                        break;

                        case -33:
                        //R32
                        i--;

                        break;

                        case -34:
                        //R33
                        i--;

                        break;

                        case -35:
                        //R34
                        i--;

                        break;

                        case -36:
                        //R35
                        i--;

                        break;

                        case -37:
                        //R36
                        
                        i--;

                        break;

                        case -38:
                        //R37
                        i--;

                        break;

                        case -39:
                        //R38
                        i--;

                        break;

                        case -40:
                        //R39
                        i--;

                        break;
                        
                        case -41:
                        //R40
                        i--;

                        break;

                        case -42:
                        //R41
                        i--;

                        break;

                        case -43:
                        //R42
                        i--;

                        break;

                        case -44:
                        //R43
                        i--;

                        break;

                        case -45:
                        //R44
                        i--;

                        break;

                        case -46:
                        //R45
                        i--;

                        break;

                        case -47:
                        //R46

                        i--;
                        break;

                        case -48:
                        //R47
                        i--;

                        break;

                        case -49:
                        //R48

                        i--;
                        break;
                        
                        case -50:
                        //R49
                        i--;

                        break;

                        case -51:
                        //R50
                        i--;
                        break;

                        case -52:
                        //R51
                        i--;
                        break;

                        case -53:
                        //R52
                        i--;
                        break;

                    }


                }else if ( accion == 0)
                {
                    std::cout << "Error sintactico" <<std::endl;
                    parcing = false;

                }else
                {

                    elemento = new T(token);
                    
                    pila.push(elemento);
                    
                    elemento = new T(to_string(accion));
                    
                    pila.push(elemento);

                    std::cout << fila << " " << columna << " " << accion <<std::endl;

                }

                data.clear();

            default:
                data +=c;

        }


        i++;
    } 

    
/*

    std::string valor;

*/

};
void MainWindow::PopPila(const int&tokens, Pila& pila)
{
    // T = 0 * 2
    //T = 0


    int PopTokens, i = 0;

    PopTokens = tokens * 2;

    while(i < PopTokens)
    {
        pila.pop();


        i++;
    }

    std::cout << "Se ha popeado: " << i << "Tokens a popear: " << PopTokens << std::endl;

};

void MainWindow::Lista()
{
    Pila pila;

    
    std::string programa;

    QString texto = ui->textEdit->toPlainText();
    int i = 0;
    char c;
    Automata analizador;

    std::string cadena = texto.toStdString();

    std::string data;

    ui->listWidget->clear();

    ui->textEdit->clear();

    while (i < cadena.length())
    {
        c = cadena[i];

        data+= c;


        switch(c)
        {
        case '(':
            if(data != "(")
            {
                data.erase(data.length()-1, data.length());

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                programa +=  data + "|" + analizador.identificar(data) + " ";
                
                data = "(";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                programa +=  data + "|" + analizador.identificar(data)  + " ";

                data.clear();
            }else
            {

                data = "(";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                
                programa +=  data + "|" + analizador.identificar(data)  + " ";
                
                data.clear();
            }
            break;
        case '{':
            if(data != "{")
            {
                data.erase(data.length()-1, data.length());


                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=  data + "|" + analizador.identificar(data)  + " ";

                data = "{";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=  data + "|" + analizador.identificar(data)  + " ";

                data.clear();
            }else
            {

                data = "{";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=  data + "|" + analizador.identificar(data)  + " ";
                
                data.clear();
            }
            break;
        case ')':
            if(data != ")")
            {
                data.erase(data.length()-1, data.length());


                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=  data + "|" + analizador.identificar(data)  + " ";

                data = ")";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=  data + "|" + analizador.identificar(data)  + " ";

                data.clear();
            }else
            {

                data = ")";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=  data + "|" + analizador.identificar(data)  + " ";
                
                data.clear();
            }
            break;
        case '}':
            if(data != "}")
            {
                data.erase(data.length()-1, data.length());


                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                
                programa +=  data + "|" + analizador.identificar(data)  + " ";

                data = "}";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                
                programa +=  data + "|" + analizador.identificar(data)  + " ";

                data.clear();
            }else
            {

                data = "}";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=  data + "|" + analizador.identificar(data)  + " ";
                
                data.clear();
            }
            break;
        case '[':
            if(data != "[")
            {
                data.erase(data.length()-1, data.length());


                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=  data + "|" + analizador.identificar(data)  + " ";

                data = "[";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=  data + "|" + analizador.identificar(data)  + " ";

                data.clear();
            }else
            {

                data = "[";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=   data + "|" + analizador.identificar(data)  + " ";
                
                data.clear();
            }
            break;
        case ']':
            if(data != "]")
            {
                data.erase(data.length()-1, data.length());


                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=  data + "|" +  analizador.identificar(data)  + " ";

                data = "]";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=   data + "|" + analizador.identificar(data)  + " ";

                data.clear();
            }else
            {

                data = "]";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=   data + "|" + analizador.identificar(data)  + " ";
                
                data.clear();
            }
            break;
        case ';':
            if(data != ";")
            {
                data.erase(data.length()-1, data.length());


                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=   data + "|" + analizador.identificar(data)  + " ";
                data = ";";
                
                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=   data + "|" + analizador.identificar(data)  + " ";

                data.clear();
            }else
            {

                data = ";";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=  data + "|" +  analizador.identificar(data)  + " ";
                
                data.clear();
            }
            break;
        case '<':
            if(data != "<")
            {
                if(cadena[i + 1] != NULL)
                {
                    if(cadena[i + 1] == '=')
                    {
                        i++;
                        data += cadena[i];
                        data.erase(data.length()-2, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + "|" + analizador.identificar(data)  + " ";
                        
                        data = "<=";
                        
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + "|" + analizador.identificar(data)  + " ";
                        
                        data.clear();
                    }
                    else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + "|" + analizador.identificar(data)  + " ";
                        
                        data = "<";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        
                        programa +=  data + "|" + analizador.identificar(data)  + " ";
                        
                        data.clear();
                    }
                }
                else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + "|" + analizador.identificar(data)  + " ";
                        
                        data = "<";
                        
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + "|" + analizador.identificar(data)  + " ";
                        
                        data.clear();
                    }

            }else
            {
                if(cadena[i + 1] != NULL)
                {
                    if(cadena[i + 1] == '=')
                    {
                        i++;
                        data += cadena[i];
                        data = "<=";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + "|" + analizador.identificar(data)  + " ";
                     
                        data.clear();
                    }
                    else
                    {
                        data = "<";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + "|" + analizador.identificar(data)  + " ";
                        
                        data.clear();
                    }
                }
                else
                {
                    data = "<";
                    ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                    programa +=   data + "|" + analizador.identificar(data)  + " ";
             
                    data.clear();
            }
            }
            break;
        case '>':
            if(data != ">")
            {
                if(cadena[i + 1] != NULL)
                {
                    if(cadena[i + 1] == '=')
                    {
                        i++;
                        data += cadena[i];
                        data.erase(data.length()-2, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" +  analizador.identificar(data)  + " ";
                
                        data = ">=";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + "|" + analizador.identificar(data)  + " ";
                    
                        data.clear();
                    }
                    else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + "|" + analizador.identificar(data)  + " ";
                        
                        data = ">";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + "|" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                }
                else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + "|" + analizador.identificar(data)  + " ";
                        data = ">";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + "|" + analizador.identificar(data)  + " ";
                        data.clear();
                    }

            }else
            {
                if(cadena[i + 1] != NULL)
                {
                    if(cadena[i + 1] == '=')
                    {
                        i++;
                        data += cadena[i];
                        data = ">=";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + "|" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                    else
                    {
                        data = ">";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + "|" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                }
                else
                {
                    data = ">";
                    ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                    programa +=  data + "|" +  analizador.identificar(data)  + " ";
                    data.clear();
            }
            }
            break;
        case '=':
                    if(data != "=")
                    {
                        if(cadena[i + 1] != NULL)
                        {
                            if(cadena[i + 1] == '=')
                            {
                                i++;
                                data += cadena[i];

                                data.erase(data.length()-2, data.length());

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=   data + "|" + analizador.identificar(data)  + " ";
                                data = "==";

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=  data + "|" +  analizador.identificar(data)  + " ";
                                data.clear();

                            }
                            else
                            {
                                data.erase(data.length()-1, data.length());

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=  data + "|" +  analizador.identificar(data)  + " ";
                                data = "=";

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=  data + "|" +  analizador.identificar(data)  + " ";
                                data.clear();
                            }
                        }
                        else
                            {
                                data.erase(data.length()-1, data.length());

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=   data + "|" + analizador.identificar(data)  + " ";
                                data = "=";

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=   data + "|" + analizador.identificar(data)  + " ";
                                data.clear();
                            }

                    }else
                    {
                        if(cadena[i + 1] != NULL)
                        {
                            if(cadena[i + 1] == '=')
                            {
                                i++;
                                data += cadena[i];
                                data = "==";
                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=   data + "|" + analizador.identificar(data)  + " ";
                                data.clear();
                            }
                            else
                            {
                                data = "=";
                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=   data + "|" + analizador.identificar(data)  + " ";
                                data.clear();
                            }
                        }
                        else
                        {
                                data = "=";
                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=  data + "|" +  analizador.identificar(data)  + " ";
                                data.clear();
                        }
                    }
                    break;
        case '|':
            if(data != "|")
            {
                if(cadena[i + 1] != NULL)
                {
                    if(cadena[i + 1] == '|')
                    {
                        i++;
                        data += cadena[i];
                        data.erase(data.length()-2, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" +  analizador.identificar(data)  + " ";
                        data = "||";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + "|" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                    else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + "|" + analizador.identificar(data)  + " ";
                        data = "|";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + "|" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                }
                else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" +  analizador.identificar(data)  + " ";
                        data = "|";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + "|" + analizador.identificar(data)  + " ";
                        data.clear();
                    }

            }else
            {
                if(cadena[i + 1] != NULL)
                {
                    if(cadena[i + 1] == '|')
                    {
                        i++;
                        data += cadena[i];
                        data = "||";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" +  analizador.identificar(data)  + " ";
                        data.clear();
                    }
                    else
                    {
                        data = "|";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + "|" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                }
                else
                {
                    data = "|";
                    ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                    programa +=   data + "|" + analizador.identificar(data)  + " ";
                    data.clear();
                }
            }
            break;
        case '&':
                    if(data != "&")
                    {
                        if(cadena[i + 1] != NULL)
                        {
                            if(cadena[i + 1] == '&')
                            {
                                i++;
                                data += cadena[i];

                                data.erase(data.length()-2, data.length());

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=   data + "|" + analizador.identificar(data)  + " ";
                                data = "&&";

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=   data + "|" + analizador.identificar(data)  + " ";
                                data.clear();

                            }
                            else
                            {
                                data.erase(data.length()-1, data.length());

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=  data + "|" +  analizador.identificar(data)  + " ";
                                data = "&";

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=  data + "|" +  analizador.identificar(data)  + " ";
                                data.clear();
                            }
                        }
                        else
                            {
                                data.erase(data.length()-1, data.length());

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=   data + "|" + analizador.identificar(data)  + " ";
                                data = "&";

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=  data + "|" +  analizador.identificar(data)  + " ";
                                data.clear();
                            }

                    }else
                    {
                        if(cadena[i + 1] != NULL)
                        {
                            if(cadena[i + 1] == '&')
                            {
                                i++;
                                data += cadena[i];
                                data = "&&";
                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=  data + "|" +  analizador.identificar(data)  + " ";
                                data.clear();
                            }
                            else
                            {
                                data = "&";
                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=  data + "|" +  analizador.identificar(data)  + " ";
                                data.clear();
                            }
                        }
                        else
                        {
                            data = "&";
                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=  data + "|" + analizador.identificar(data)  + " ";
                                data.clear();
                        }
                    }
            break;
        case '%':
            if(data != "%")
            {
                //Por revisar
                data.erase(data.length()-1, data.length());
                ui->listWidget->addItem(QString::fromStdString(data));
                ui->listWidget->addItem(QString::fromStdString("%"));
                programa +=  data + "|" + analizador.identificar(data)  + " ";
                data.clear();
            }else
            {
                ui->listWidget->addItem(QString::fromStdString("%"));
                programa +=  data + "|" + analizador.identificar(data)  + " ";
                data.clear();
            }
            break;
        case '!':
            if(data != "!")
            {
                if(cadena[i + 1] != NULL)
                {
                    if(cadena[i + 1] == '=')
                    {
                        i++;
                        data += cadena[i];
                        data.erase(data.length()-2, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" + analizador.identificar(data)  + " ";
                        data = "!=";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                    else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" + analizador.identificar(data)  + " ";
                        data = "!";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                }
                else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" + analizador.identificar(data)  + " ";
                        data = "!";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" + analizador.identificar(data)  + " ";
                        data.clear();
                    }

            }else
            {
                if(cadena[i + 1] != NULL)
                {
                    if(cadena[i + 1] == '=')
                    {
                        i++;
                        data += cadena[i];
                        data = "!=";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                    else
                    {
                        data = "!";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                }
                else
                {
                    data = "!";
                    ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                    programa +=  data + "|" + analizador.identificar(data)  + " ";
                    data.clear();
                }
            }
            break;
        case '/':
            if(data != "/")
            {
                
                //Por revisar
                data.erase(data.length()-1, data.length());
                ui->listWidget->addItem(QString::fromStdString(data));
                ui->listWidget->addItem(QString::fromStdString("/"));
                data.clear();
            }else
            {
                ui->listWidget->addItem(QString::fromStdString("("));
                programa +=  data + "|" + analizador.identificar(data)  + " ";
                data.clear();
            }
            break;
        case '+':
            if(data != "+")
            {
                if(cadena[i + 1] != NULL)
                {
                    if(cadena[i + 1] == '+')
                    {
                        i++;
                        data += cadena[i];
                        data.erase(data.length()-2, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" + analizador.identificar(data)  + " ";
                        data = "++";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                    else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" + analizador.identificar(data)  + " ";
                        data = "+";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                }
                else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" + analizador.identificar(data)  + " ";
                        data = "+";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" + analizador.identificar(data)  + " ";
                        data.clear();
                    }

            }else
            {
                if(cadena[i + 1] != NULL)
                {
                    if(cadena[i + 1] == '+')
                    {
                        i++;
                        data += cadena[i];
                        data = "++";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                    else
                    {
                        data = "+";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                }
                else
                {
                    data = "+";
                    ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                    programa +=  data + "|" + analizador.identificar(data)  + " ";
                    data.clear();
                }
            }
            break;
        case '-':
            if(data != "-")
            {
                if(cadena[i + 1] != NULL)
                {
                    if(cadena[i + 1] == '-')
                    {
                        i++;
                        data += cadena[i];
                        data.erase(data.length()-2, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" + analizador.identificar(data)  + " ";
                        data = "--";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                    else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" + analizador.identificar(data)  + " ";
                        data = "-";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                }
                else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" + analizador.identificar(data)  + " ";
                        
                        data = "-";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" + analizador.identificar(data)  + " ";
                        data.clear();
                    }

            }else
            {
                if(cadena[i + 1] != NULL)
                {
                    if(cadena[i + 1] == '-')
                    {
                        i++;
                        data += cadena[i];
                        data = "--";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa += data + "|" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                    else
                    {
                        data = "-";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + "|" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                }
                else
                {
                    data = "-";
                    ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                    programa +=  data + "|" + analizador.identificar(data)  + " ";
                    data.clear();
                }
            }
            break;
        case '*':
            if(data != "*")
            {
                //Por revisar
                data.erase(data.length()-1, data.length());
                ui->listWidget->addItem(QString::fromStdString(data));
                ui->listWidget->addItem(QString::fromStdString("*"));
                programa +=  data + "|" + analizador.identificar(data)  + " ";
                data.clear();
            }else
            {
                ui->listWidget->addItem(QString::fromStdString("*"));
                programa +=  data + "|" + analizador.identificar(data)  + " ";
                data.clear();
            }
        case ' ':
            if(data != " ")
            {
                data.erase(data.length()-1, data.length());
                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=  data + "|" + analizador.identificar(data)  + " ";
                data.clear();
                
            }else
            {
                data.clear();
            }

            break;
        case '\t':
            data.clear();
            break;

        case '\n':
            data.clear();
            break;
        }

        i++;
    }
    //Corre el sintactico

    programa+="$|Reservadas|23";

    RunPila(pila, programa);

};
