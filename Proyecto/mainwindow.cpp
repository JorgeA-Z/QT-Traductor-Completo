#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>
#include <iostream>
#include <QDebug>
#include <QFile>
#include <QFont>
#include "arbolsintactico.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    setFixedSize(width(), height());

    /*

    QFile file(R"(C:\Users\52322\Desktop\Stylesheet\Persona5.qss)");

    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);


    QFile r(R"(C:\Users\52322\Desktop\QT-Traductor-Completo\Proyecto\fonts\p5hatty.ttf)");

    QFont f;
    f.setFamily("p5hatty");
    f.setPointSize(20);
    ui->textEdit->setFont(f);

    */


    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(Lista()));
    ui->progressBar->setTextVisible(false);
    ui->progressBar->setValue(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::RunPila(Pila& pila, std::string& programa)
{

//    std::cout << programa << std::endl;

    EP* elemento;

    ArbolSintactico tree;

    int fila, columna;
    elemento = new T("$");

    pila.push(elemento);

    elemento = new T("0");

    pila.push(elemento);


    //El numero que está en el tope de la fila + el número del identificador
    //int|Reservadas|4 main|Identificador|0 (|Simbolo|14 )|Simbolo|15 {|Simbolo|16 }|Simbolo|17

    int i = 0, j, control, accion, t, p;
    char c;
    std::string data, tipo, token, aux1, aux2, semantica;
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
                    if(data[j] == ':')
                    {
                        control++;
                    }
                    j++;
                }
                //Aplicar el algoritmo
                fila = pila.Top()->get_estado();

                columna = stoi(tipo);


                accion = LR[fila][columna];
                if(token != "$")
                {
                    ui->listWidget->addItem(QString::fromStdString(to_string(accion)));
                }

                if(accion < 0)
                {
                    switch(accion)
                    {
                        case -1:
                        //Sintactico
                        ui->listWidget->addItem("Analisis sintactico completado con satisfaccion");
                        parcing = false;
                        ui->progressBar->setValue(100);
                        ui->progressBar->setStyleSheet("QProgressBar::chunk {background:Green;}");

                        //Semantico
                        pila.pop();
                        tree.setRoot(pila.Top());
                        semantica = tree.arbol_to_string();

                        RunTree(semantica);

                        ui->listWidget->addItem("Analisis semantico completado con satisfaccion");

                        i--;

                        break;


                        case -2:
                        //R1
                        PopPila(1, pila, accion, fila);

                        accion = LR[fila][24];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -3:
                        //R2
                        PopPila(0, pila, accion, fila);

                        accion = LR[fila][25];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;
                        break;

                        case -4:
                        //R3
                        PopPila(2, pila, accion, fila);

                        accion = LR[fila][25];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;
                        break;

                        case -5:
                        //R4
                        PopPila(1, pila, accion, fila);

                        accion = LR[fila][26];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;
                        break;

                        case -6:
                        //R5
                        PopPila(1, pila, accion, fila);

                        accion = LR[fila][26];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;
                        break;

                        case -7:
                        //R6
                        PopPila(4, pila, accion, fila);

                        accion = LR[fila][27];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;
                        break;

                        case -8:
                        //R7
                        PopPila(0, pila, accion, fila);

                        accion = LR[fila][28];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;
                        break;

                        case -9:
                        //R8
                        PopPila(3, pila, accion, fila);

                        accion = LR[fila][28];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;
                        break;

                        case -10:
                        //R9
                        PopPila(6, pila, accion, fila);

                        accion = LR[fila][29];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;
                        break;

                        case -11:
                        //R10
                        PopPila(0, pila, -11, fila);

                        accion = LR[fila][30];

                        elemento = new E(accion);

                        pila.push(elemento);
                        i--;
                        break;

                        case -12:
                        //R11
                        PopPila(3, pila, accion, fila);

                        accion = LR[fila][30];

                        elemento = new E(accion);

                        pila.push(elemento);
                        i--;
                        break;

                        case -13:
                        //R12
                        PopPila(0, pila, accion, fila);

                        accion = LR[fila][31];

                        elemento = new E(accion);

                        pila.push(elemento);
                        i--;
                        break;

                        case -14:
                        //R13
                        PopPila(4, pila, accion, fila);

                        accion = LR[fila][31];

                        elemento = new E(accion);

                        pila.push(elemento);
                        i--;
                        break;
                        case -15:
                        //R14

                        PopPila(3, pila, accion, fila);

                        accion = LR[fila][32];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -16:
                        //R15
                        PopPila(0, pila, accion, fila);

                        accion = LR[fila][33];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;


                        case -17:
                        //R16
                        PopPila(2, pila, accion, fila);

                        accion = LR[fila][33];

                        elemento = new E(accion);

                        pila.push(elemento);
                        i--;

                        break;


                        case -18:
                        //R17

                        PopPila(1, pila, -18, fila);

                        accion = LR[fila][34];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -19:
                        //R18
                        i--;
                        PopPila(1, pila, accion, fila);

                        accion = LR[fila][34];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;


                        case -20:
                        //R19
                        PopPila(0, pila, accion, fila);

                        accion = LR[fila][35];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;
                        case -21:
                        //R20
                        PopPila(2, pila, accion, fila);

                        accion = LR[fila][35];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;


                        case -22:
                        //R21
                        PopPila(4, pila, accion, fila);

                        accion = LR[fila][36];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -23:
                        //R22
                        PopPila(6, pila, accion, fila);

                        accion = LR[fila][36];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -24:
                        //R23
                        PopPila(5, pila, accion, fila);

                        accion = LR[fila][36];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -25:
                        //R24
                        PopPila(3, pila, accion, fila);

                        accion = LR[fila][36];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -26:
                        //R25
                        PopPila(2, pila, accion, fila);

                        accion = LR[fila][36];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;
                        case -27:
                        //R26
                        PopPila(0, pila, accion, fila);

                        accion = LR[fila][37];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -28:
                        //R27
                        PopPila(2, pila, accion, fila);

                        accion = LR[fila][37];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -29:
                        //R28
                        PopPila(3, pila, accion, fila);

                        accion = LR[fila][38];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -30:
                        //R29
                        PopPila(0, pila, accion, fila);

                        accion = LR[fila][39];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -31:
                        //R30
                        PopPila(1, pila, accion, fila);

                        accion = LR[fila][39];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -32:
                        //R31
                        PopPila(0, pila, accion, fila);

                        accion = LR[fila][40];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -33:
                        //R32
                        PopPila(2, pila, accion, fila);

                        accion = LR[fila][40];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -34:
                        //R33
                        PopPila(0, pila, accion, fila);

                        accion = LR[fila][41];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -35:
                        //R34
                        PopPila(3, pila, accion, fila);

                        accion = LR[fila][41];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -36:
                        //R35
                        PopPila(1, pila, accion, fila);

                        accion = LR[fila][42];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -37:
                        //R36

                        PopPila(1, pila, accion, fila);

                        accion = LR[fila][42];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -38:
                        //R37
                        PopPila(1, pila, accion, fila);

                        accion = LR[fila][42];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -39:
                        //R38
                        PopPila(1, pila, accion, fila);

                        accion = LR[fila][42];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -40:
                        //R39
                        PopPila(1, pila, accion, fila);

                        accion = LR[fila][42];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -41:
                        //R40
                        PopPila(4, pila, accion, fila);

                        accion = LR[fila][43];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -42:
                        //R41
                        PopPila(1, pila, accion, fila);

                        accion = LR[fila][44];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -43:
                        //R42
                        PopPila(1, pila, accion, fila);

                        accion = LR[fila][44];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -44:
                        //R43
                        PopPila(3, pila, accion, fila);

                        accion = LR[fila][45];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -45:
                        //R44
                        PopPila(2, pila, accion, fila);

                        accion = LR[fila][45];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -46:
                        //R45
                        PopPila(2, pila, accion, fila);

                        accion = LR[fila][45];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -47:
                        PopPila(3, pila, accion, fila);

                        accion = LR[fila][45];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -48:
                        //R47
                        PopPila(3, pila, accion, fila);

                        accion = LR[fila][45];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -49:
                        //R48

                        PopPila(3, pila, accion, fila);

                        accion = LR[fila][45];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -50:
                        //R49
                        PopPila(3, pila, accion, fila);

                        accion = LR[fila][45];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -51:
                        //R50
                        PopPila(3, pila, accion, fila);

                        accion = LR[fila][45];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -52:
                        //R51
                        PopPila(3, pila, accion, fila);

                        accion = LR[fila][45];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;

                        case -53:
                        //R52
                        PopPila(1, pila, accion, fila);

                        accion = LR[fila][45];

                        elemento = new E(accion);

                        pila.push(elemento);

                        i--;

                        break;


                    }

                    ui->Pila->addItem(QString::fromStdString(pila.GetPila()));
                }else if ( accion == 0)
                {

                    Errores(columna);
                    ui->progressBar->setValue(75);
                    ui->progressBar->setStyleSheet("QProgressBar::chunk {background:Red;}");
                    parcing = false;

                }else
                {

                    elemento = new T(token);

                    pila.push(elemento);

                    elemento = new E(accion);

                    pila.push(elemento);

                    ui->Pila->addItem(QString::fromStdString(pila.GetPila()));

                }

                data.clear();

            default:
                data +=c;

        }

        i++;
    }

};

void MainWindow::PopPila(const int&tokens, Pila& pila, const int &idregla, int &fila)
{
    // T = 0 * 2
    //T = 0

    EP* elemento;
    T* aux1 = new T();
    T* aux3 = new T();
    T* aux4 = new T();
    T* aux8 = new T();
    NT* aux2 = new NT();
    NT* aux7 = new NT();
    NT* aux9 = new NT();
    EP* aux5;
    EP* aux6;
    Nodo* regla;
    Nodo* conexion;

    int PopTokens, i = 0;

    PopTokens = tokens * 2;

    switch (idregla) {
    case -2:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());
            }
            pila.pop();
            i++;
        }

        regla = new R1(aux2);
        fila = pila.Top()->get_estado();
        elemento = new NT("<programa>", regla);

        pila.push(elemento);
        break;
    case -3:
        regla = new R2();

        while(i < PopTokens)
        {
            i++;
            pila.pop();
        }

        fila = pila.Top()->get_estado();

        elemento = new NT("<Definiciones>", regla);

        pila.push(elemento);

        break;
    case -4:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());
            }
            if(i == 3)
            {
                //No terminal
                aux7 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());
            }
            pila.pop();
            i++;
        }

        regla = new R3(aux7, aux2);
        fila = pila.Top()->get_estado();
        elemento = new NT("<Definiciones>", regla);
        pila.push(elemento);

        break;
    case -5:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());
            }
            pila.pop();
            i++;
        }

        regla = new R4(aux2);
        fila = pila.Top()->get_estado();
        elemento = new NT("<Definicion>", regla);
        pila.push(elemento);
        break;
    case -6:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());
            }
            pila.pop();
            i++;
        }

        regla = new R5(aux2);
        fila = pila.Top()->get_estado();
        elemento = new NT("<Definicion>", regla);
        pila.push(elemento);
        break;
    case -7:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //Terminal
                aux1 = new T(pila.Top()->get_val());
            }
            if(i == 3)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());
            }
            if(i == 5)
            {
                aux3 = new T(pila.Top()->get_val());
            }
            if(i == 7)
            {
                aux4 = new T(pila.Top()->get_val());

            }

            pila.pop();
            i++;
        }

        regla = new R6(aux4, aux3, aux2, aux1);
        fila = pila.Top()->get_estado();
        elemento = new NT("<DefVar>", regla);
        pila.push(elemento);

        break;

    case -8:
        regla = new R7();

        while(i < PopTokens)
        {
            i++;
            pila.pop();
        }

        fila = pila.Top()->get_estado();
        elemento = new NT("<ListaVar>", regla);
        pila.push(elemento);

        break;

    case -9:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //Terminal
                aux1 = new T(pila.Top()->get_val());
            }
            if(i == 3)
            {
                aux3 = new T(pila.Top()->get_val());
            }
            if(i == 5)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }

            pila.pop();
            i++;
        }

        regla = new R8(aux1, aux3, aux2);
        fila = pila.Top()->get_estado();
        elemento = new NT("<ListaVar>", regla);
        pila.push(elemento);

        break;
    case -10:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());
            }
            if(i == 3)
            {
                //Terminal
                aux3 = new T(pila.Top()->get_val());
            }
            if(i == 5)
            {
                aux7 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());
            }
            if(i == 7)
            {
                aux8 = new T(pila.Top()->get_val());
            }
            if(i == 9)
            {
                aux1 = new T(pila.Top()->get_val());
            }
            if(i == 11)
            {
                aux4 = new T(pila.Top()->get_val());
            }
            pila.pop();
            i++;
        }

        regla = new R9(aux4, aux1, aux8, aux3, aux7, aux2);
        fila = pila.Top()->get_estado();
        elemento = new NT("<DefFunc>", regla);
        pila.push(elemento);

        break;

    case -11:
        regla = new R10();

        while(i < PopTokens)
        {
            i++;
            pila.pop();
        }

        fila = pila.Top()->get_estado();

        elemento = new NT("<Parametros>", regla);

        pila.push(elemento);

        break;
    case -12:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());
            }
            if(i == 3)
            {
                aux3 = new T(pila.Top()->get_val());
            }
            if(i == 5)
            {
                aux1 = new T(pila.Top()->get_val());
            }

            pila.pop();
            i++;
        }

        regla = new R11(aux1, aux3, aux2);
        fila = pila.Top()->get_estado();
        elemento = new NT("<Parametros>", regla);
        pila.push(elemento);

        break;
    case -13:
        while(i < PopTokens)
        {
            pila.pop();
            i++;
        }

        regla = new R12();
        fila = pila.Top()->get_estado();
        elemento = new NT("<ListaParam>", regla);
        pila.push(elemento);

        break;
    case -14:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());
            }
            if(i == 3)
            {
                aux3 = new T(pila.Top()->get_val());
            }
            if(i == 5)
            {
                aux4 = new T(pila.Top()->get_val());
            }
            if(i == 7)
            {
                aux1 = new T(pila.Top()->get_val());
            }

            pila.pop();
            i++;
        }

        regla = new R13(aux1, aux4, aux3, aux2);
        fila = pila.Top()->get_estado();
        elemento = new NT("<ListaParam>", regla);
        pila.push(elemento);

        break;
    case -15:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //Terminal
                aux1 = new T(pila.Top()->get_val());
            }
            if(i == 3)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }
            if(i == 5)
            {
                aux3 = new T(pila.Top()->get_val());
            }


            pila.pop();
            i++;
        }

        regla = new R14(aux3, aux2, aux1);
        fila = pila.Top()->get_estado();
        elemento = new NT("<BloqFunc>", regla);
        pila.push(elemento);

        break;
    case -16:
        while(i < PopTokens)
        {
            pila.pop();
            i++;
        }

        regla = new R15();
        fila = pila.Top()->get_estado();
        elemento = new NT("<DefLocales>", regla);
        pila.push(elemento);

        break;
    case -17:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }
            if(i == 3)
            {
                //No terminal
                aux7 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }

            pila.pop();
            i++;
        }

        regla = new R16(aux7, aux2);
        fila = pila.Top()->get_estado();
        elemento = new NT("<DefLocales>", regla);
        pila.push(elemento);

        break;
    case -18:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());
            }


            pila.pop();
            i++;
        }

        regla = new R17(aux2);
        fila = pila.Top()->get_estado();
        elemento = new NT("<DefLocal>", regla);
        pila.push(elemento);

        break;
    case -19:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }

            pila.pop();
            i++;
        }

        regla = new R18(aux2);
        fila = pila.Top()->get_estado();
        elemento = new NT("<DefLocal>", regla);
        pila.push(elemento);

        break;
    case -20:
        while(i < PopTokens)
            {
                pila.pop();
                i++;
            }

            regla = new R19();
            fila = pila.Top()->get_estado();
            elemento = new NT("<Sentencias>", regla);
            pila.push(elemento);

            break;
    case -21:

    while(i < PopTokens)
    {
        if(i == 1)
        {
            //No terminal
            aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

        }
        if(i == 3)
        {
            //No terminal
            aux7 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());
        }

        pila.pop();
        i++;
    }

    regla = new R20(aux2, aux7);
    fila = pila.Top()->get_estado();
    elemento = new NT("<Sentencias>", regla);
    pila.push(elemento);

    break;
    case -22:

    while(i < PopTokens)
    {
        if(i == 1)
        {
            //Terminal
            aux1 = new T(pila.Top()->get_val());
        }
        if(i == 3)
        {
            aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());
        }
        if(i == 5)
        {
            aux3 = new T(pila.Top()->get_val());
        }
        if(i == 7)
        {
            //Terminal
            aux4 = new T(pila.Top()->get_val());
        }

        pila.pop();
        i++;
    }

    regla = new R21(aux4, aux3, aux2, aux1);
    fila = pila.Top()->get_estado();
    elemento = new NT("<Sentencia>", regla);
    pila.push(elemento);

    break;
    case -23:

    while(i < PopTokens)
    {
        if(i == 1)
        {
            //Terminal
            aux7 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());
        }
        if(i == 3)
        {
            //Terminal
            aux9 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());
        }
        if(i == 5)
        {
            //Terminal
            aux4 = new T(pila.Top()->get_val());
        }
        if(i == 7)
        {
            //No terminal
            aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

        }
        if(i == 9)
        {
            //No terminal
            aux1 = new T(pila.Top()->get_val());

        }
        if(i == 11)
        {
            //No terminal
            aux3 = new T(pila.Top()->get_val());

        }

        pila.pop();
        i++;
    }

    regla = new R22(aux3, aux1, aux4, aux2, aux9, aux7);
    fila = pila.Top()->get_estado();
    elemento = new NT("<Sentencia>", regla);
    pila.push(elemento);

    break;
    case -24:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //Terminal
                aux7 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());
            }
            if(i == 3)
            {
                //Terminal
                aux3 = new T(pila.Top()->get_val());
            }
            if(i == 5)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }
            if(i == 7)
            {
                //Terminal
                aux4 = new T(pila.Top()->get_val());
            }
            if(i == 9)
            {
                //No terminal
                aux1 = new T(pila.Top()->get_val());

            }

            pila.pop();
            i++;
        }

        regla = new R23(aux1, aux4, aux2, aux3, aux7);
        fila = pila.Top()->get_estado();
        elemento = new NT("<Sentencia>", regla);
        pila.push(elemento);

        break;
    case -25:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //Terminal
                aux1 = new T(pila.Top()->get_val());
            }
            if(i == 3)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }
            if(i == 5)
            {
                //Terminal
                aux3 = new T(pila.Top()->get_val());
            }

            pila.pop();
            i++;
        }

        regla = new R24(aux3, aux2, aux1);
        fila = pila.Top()->get_estado();
        elemento = new NT("<Sentencia>", regla);
        pila.push(elemento);

        break;
    case -26:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //No terminal
                aux1 = new T(pila.Top()->get_val());

            }
            if(i == 3)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }

            pila.pop();
            i++;
        }

        regla = new R25(aux2);
        fila = pila.Top()->get_estado();
        elemento = new NT("<Sentencia>", regla);
        pila.push(elemento);

        break;
    case -27:
        while(i < PopTokens)
        {
            pila.pop();
            i++;
        }

        regla = new R26();
        fila = pila.Top()->get_estado();
        elemento = new NT("<Otro>", regla);
        pila.push(elemento);

        break;
    case -28:
        while(i < PopTokens)
        {
            if(i == 3)
            {
                //Terminal
                aux1 = new T(pila.Top()->get_val());
            }
            if(i == 1)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }

            pila.pop();
            i++;
        }

        regla = new R27(aux1, aux2);
        fila = pila.Top()->get_estado();
        elemento = new NT("<Otro>", regla);
        pila.push(elemento);

        break;
    case -29:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //Terminal
                aux1 = new T(pila.Top()->get_val());
            }
            if(i == 3)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }
            if(i == 5)
            {
                //Terminal
                aux3 = new T(pila.Top()->get_val());
            }

            pila.pop();
            i++;
        }

        regla = new R28(aux3, aux2, aux1);
        fila = pila.Top()->get_estado();
        elemento = new NT("<Bloque>", regla);
        pila.push(elemento);

        break;
    case -30:
        while(i < PopTokens)
        {

            pila.pop();
            i++;
        }

        regla = new R29();
        fila = pila.Top()->get_estado();
        elemento = new NT("<ValorRegresa>", regla);
        pila.push(elemento);

        break;
    case -31:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }

            pila.pop();
            i++;
        }

        regla = new R30(aux2);
        fila = pila.Top()->get_estado();
        elemento = new NT("<ValorRegresa>", regla);
        pila.push(elemento);

        break;
    case -32:
        while(i < PopTokens)
        {

            pila.pop();
            i++;
        }

        regla = new R31();
        fila = pila.Top()->get_estado();
        elemento = new NT("<Argumentos>", regla);
        pila.push(elemento);

        break;
    case -33:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }
            if(i == 3)
            {
                //No terminal
                aux7 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }

            pila.pop();
            i++;
        }

        regla = new R32(aux7, aux2);
        fila = pila.Top()->get_estado();
        elemento = new NT("<Argumentos>", regla);
        pila.push(elemento);

        break;
    case -34:
        while(i < PopTokens)
        {

            pila.pop();
            i++;
        }

        regla = new R33();
        fila = pila.Top()->get_estado();
        elemento = new NT("<ListaArgumentos>", regla);
        pila.push(elemento);

        break;
    case -35:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                aux7 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());
            }
            if(i == 3)
            {
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());
            }
            if(i == 5)
            {
                aux1 = new T(pila.Top()->get_val());
            }

            pila.pop();
            i++;
        }

        regla = new R34(aux1, aux2, aux7);
        fila = pila.Top()->get_estado();
        elemento = new NT("<ListaArgumentos>", regla);
        pila.push(elemento);

        break;
    case -36:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }

            pila.pop();
            i++;
        }

        regla = new R35(aux2);
        fila = pila.Top()->get_estado();
        elemento = new NT("<Termino>", regla);
        pila.push(elemento);

        break;
    case -37:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //Terminal
                aux1 = new T(pila.Top()->get_val());
            }

            pila.pop();
            i++;
        }

        regla = new R36(aux1);
        fila = pila.Top()->get_estado();
        elemento = new NT("<Termino>", regla);
        pila.push(elemento);

        break;
    case -38:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //Terminal
                aux1 = new T(pila.Top()->get_val());
            }

            pila.pop();
            i++;
        }

        regla = new R37(aux1);
        fila = pila.Top()->get_estado();
        elemento = new NT("<Termino>", regla);
        pila.push(elemento);

        break;
    case -39:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //Terminal
                aux1 = new T(pila.Top()->get_val());
            }

            pila.pop();
            i++;
        }

        regla = new R38(aux1);
        fila = pila.Top()->get_estado();
        elemento = new NT("<Termino>", regla);
        pila.push(elemento);

        break;
    case -40:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //Terminal
                aux1 = new T(pila.Top()->get_val());
            }

            pila.pop();
            i++;
        }

        regla = new R39(aux1);
        fila = pila.Top()->get_estado();
        elemento = new NT("<Termino>", regla);
        pila.push(elemento);

        break;
    case -41:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                aux4 = new T(pila.Top()->get_val());
            }
            if(i == 3)
            {
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());
            }
            if(i == 5)
            {
                aux3 = new T(pila.Top()->get_val());

            }
            if(i == 7)
            {
                aux1 = new T(pila.Top()->get_val());
            }

            pila.pop();
            i++;
        }

        regla = new R40(aux1, aux3, aux2, aux4);
        fila = pila.Top()->get_estado();
        elemento = new NT("<LlamadaFunc>", regla);
        pila.push(elemento);

        break;
    case -42:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }

            pila.pop();
            i++;
        }

        regla = new R41(aux2);
        fila = pila.Top()->get_estado();
        elemento = new NT("<SentenciaBloque>", regla);
        pila.push(elemento);

        break;
    case -43:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }

            pila.pop();
            i++;
        }

        regla = new R42(aux2);
        fila = pila.Top()->get_estado();
        elemento = new NT("<SentenciaBloque>", regla);
        pila.push(elemento);

        break;
    case -44:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //Terminal
                aux1 = new T(pila.Top()->get_val());
            }
            if(i == 3)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }
            if(i == 5)
            {
                //Terminal
                aux3 = new T(pila.Top()->get_val());
            }

            pila.pop();
            i++;
        }

        regla = new R43(aux3, aux2, aux1);
        fila = pila.Top()->get_estado();
        elemento = new NT("<Expresion>", regla);
        pila.push(elemento);

        break;
    case -45:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //Terminal
                aux1 = new T(pila.Top()->get_val());
            }
            if(i == 3)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }

            pila.pop();
            i++;
        }

        regla = new R44(aux1, aux2);
        fila = pila.Top()->get_estado();
        elemento = new NT("<Expresion>", regla);
        pila.push(elemento);

        break;
    case -46:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //Terminal
                aux1 = new T(pila.Top()->get_val());
            }
            if(i == 3)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }

            pila.pop();
            i++;
        }

        regla = new R45(aux1, aux2);
        fila = pila.Top()->get_estado();
        elemento = new NT("<Expresion>", regla);
        pila.push(elemento);

        break;
    case -47:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //Terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());
            }
            if(i == 3)
            {
                //No terminal
                aux1 = new T(pila.Top()->get_val());

            }
            if(i == 5)
            {
                //Terminal
                aux7 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());
            }

            pila.pop();
            i++;
        }

        regla = new R46(aux2, aux1, aux7);
        fila = pila.Top()->get_estado();
        elemento = new NT("<Expresion>", regla);
        pila.push(elemento);

        break;
    case -48:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }
            if(i == 3)
            {
                //Terminal
                aux1 = new T(pila.Top()->get_val());
            }
            if(i == 5)
            {
                //No terminal
                aux7 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }

            pila.pop();
            i++;
        }

        regla = new R47(aux2, aux1, aux7);
        fila = pila.Top()->get_estado();
        elemento = new NT("<Expresion>", regla);
        pila.push(elemento);

        break;
    case -49:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }
            if(i == 3)
            {
                //Terminal
                aux1 = new T(pila.Top()->get_val());
            }
            if(i == 5)
            {
                //No terminal
                aux7 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }

            pila.pop();
            i++;
        }

        regla = new R48(aux2, aux1, aux7);
        fila = pila.Top()->get_estado();
        elemento = new NT("<Expresion>", regla);
        pila.push(elemento);

        break;
    case -50:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }
            if(i == 3)
            {
                //Terminal
                aux1 = new T(pila.Top()->get_val());
            }
            if(i == 5)
            {
                //No terminal
                aux7 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }

            pila.pop();
            i++;
        }

        regla = new R49(aux2, aux1, aux7);
        fila = pila.Top()->get_estado();
        elemento = new NT("<Expresion>", regla);
        pila.push(elemento);

        break;
    case -51:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }
            if(i == 3)
            {
                //Terminal
                aux1 = new T(pila.Top()->get_val());
            }
            if(i == 5)
            {
                //No terminal
                aux7 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }

            pila.pop();
            i++;
        }

        regla = new R50(aux2, aux1, aux7);
        fila = pila.Top()->get_estado();
        elemento = new NT("<Expresion>", regla);
        pila.push(elemento);

        break;
    case -52:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //No terminal
                aux2 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }
            if(i == 3)
            {
                //Terminal
                aux1 = new T(pila.Top()->get_val());
            }
            if(i == 5)
            {
                //No terminal
                aux7 = new NT(pila.Top()->get_val(), pila.Top()->getReferencia());

            }

            pila.pop();
            i++;
        }

        regla = new R51(aux2, aux1, aux7);
        fila = pila.Top()->get_estado();
        elemento = new NT("<Expresion>", regla);
        pila.push(elemento);

        break;
    case -53:
        while(i < PopTokens)
        {
            if(i == 1)
            {
                //Terminal
                aux1 = new T(pila.Top()->get_val());
            }

            pila.pop();
            i++;
        }

        regla = new R52(aux1);
        fila = pila.Top()->get_estado();
        elemento = new NT("<Expresion>", regla);
        pila.push(elemento);

        break;
    }

};

void MainWindow::RunTree(std::string&Stree)
{
    int i = 0;
    char c;

    std::string data;
    cout << Stree << endl;
    while(i< Stree.length())
    {
        c = Stree[i];

        switch(c)
        {

        case '\n':
            ui->Arbol->addItem(QString::fromStdString(data));
            data.clear();
            break;

        }
        data+=c;

        i++;

    }

};

void MainWindow::Errores(const int&error)
{
    ui->listWidget->addItem("Error sintactico, analisis fallido: " + QString::fromStdString(to_string(error)));
    std::string msgError;
    if(error < 4)
    {
        msgError = ";";
    }
    else if(error < 12)
    {
        msgError = "Variable";
    }
    else if(error == 23)
    {
         msgError = ";";
    }
    ui->listWidget->addItem("Syntax Error ' " + QString::fromStdString(MensajesError[error]) + " '");
    ui->listWidget->addItem("Se esperaba -> ' " + QString::fromStdString(msgError) + " '");
};

void MainWindow::Lista()
{
    Pila pila;

    std::string programa;

    ui->progressBar->setValue(0);
    ui->progressBar->setStyleSheet("QProgressBar::chunk {background:White;}");

    QString texto = ui->textEdit->toPlainText();
    int i = 0;
    char c;
    Automata analizador;

    std::string cadena = texto.toStdString();

    std::string data;

    ui->listWidget->clear();
    ui->Pila->clear();
    ui->Arbol->clear();
    ui->progressBar->setValue(25);

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

                programa +=  data + ":" + analizador.identificar(data) + " ";

                data = "(";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                programa +=  data + ":" + analizador.identificar(data)  + " ";

                data.clear();
            }else
            {

                data = "(";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                programa +=  data + ":" + analizador.identificar(data)  + " ";

                data.clear();
            }
            break;
        case '{':
            if(data != "{")
            {
                data.erase(data.length()-1, data.length());


                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=  data + ":" + analizador.identificar(data)  + " ";

                data = "{";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=  data + ":" + analizador.identificar(data)  + " ";

                data.clear();
            }else
            {

                data = "{";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=  data + ":" + analizador.identificar(data)  + " ";

                data.clear();
            }
            break;
        case ')':
            if(data != ")")
            {
                data.erase(data.length()-1, data.length());


                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=  data + ":" + analizador.identificar(data)  + " ";

                data = ")";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=  data + ":" + analizador.identificar(data)  + " ";

                data.clear();
            }else
            {

                data = ")";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=  data + ":" + analizador.identificar(data)  + " ";

                data.clear();
            }
            break;
        case '}':
            if(data != "}")
            {
                data.erase(data.length()-1, data.length());


                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                programa +=  data + ":" + analizador.identificar(data)  + " ";

                data = "}";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                programa +=  data + ":" + analizador.identificar(data)  + " ";

                data.clear();
            }else
            {

                data = "}";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=  data + ":" + analizador.identificar(data)  + " ";

                data.clear();
            }
            break;
        case '[':
            if(data != "[")
            {
                data.erase(data.length()-1, data.length());


                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=  data + ":" + analizador.identificar(data)  + " ";

                data = "[";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=  data + ":" + analizador.identificar(data)  + " ";

                data.clear();
            }else
            {

                data = "[";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=   data + ":" + analizador.identificar(data)  + " ";

                data.clear();
            }
            break;
        case ']':
            if(data != "]")
            {
                data.erase(data.length()-1, data.length());


                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=  data + ":" +  analizador.identificar(data)  + " ";

                data = "]";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=   data + ":" + analizador.identificar(data)  + " ";

                data.clear();
            }else
            {

                data = "]";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=   data + ":" + analizador.identificar(data)  + " ";

                data.clear();
            }
            break;
        case ';':
            if(data != ";")
            {
                data.erase(data.length()-1, data.length());


                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=   data + ":" + analizador.identificar(data)  + " ";
                data = ";";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=   data + ":" + analizador.identificar(data)  + " ";

                data.clear();
            }else
            {

                data = ";";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=  data + ":" +  analizador.identificar(data)  + " ";

                data.clear();
            }
            break;
        case ',':
            if(data != ",")
            {
                data.erase(data.length()-1, data.length());


                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=   data + ":" + analizador.identificar(data)  + " ";
                data = ",";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=   data + ":" + analizador.identificar(data)  + " ";

                data.clear();
            }else
            {

                data = ",";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=  data + ":" +  analizador.identificar(data)  + " ";

                data.clear();
            }
            break;

        case '<':
            if(data != "<")
            {
                if(cadena[i + 1] )
                {
                    if(cadena[i + 1] == '=')
                    {
                        i++;
                        data += cadena[i];
                        data.erase(data.length()-2, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + ":" + analizador.identificar(data)  + " ";

                        data = "<=";

                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + ":" + analizador.identificar(data)  + " ";

                        data.clear();
                    }
                    else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + ":" + analizador.identificar(data)  + " ";

                        data = "<";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                        programa +=  data + ":" + analizador.identificar(data)  + " ";

                        data.clear();
                    }
                }
                else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + ":" + analizador.identificar(data)  + " ";

                        data = "<";

                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + ":" + analizador.identificar(data)  + " ";

                        data.clear();
                    }

            }else
            {
                if(cadena[i + 1])
                {
                    if(cadena[i + 1] == '=')
                    {
                        i++;
                        data += cadena[i];
                        data = "<=";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + ":" + analizador.identificar(data)  + " ";

                        data.clear();
                    }
                    else
                    {
                        data = "<";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + ":" + analizador.identificar(data)  + " ";

                        data.clear();
                    }
                }
                else
                {
                    data = "<";
                    ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                    programa +=   data + ":" + analizador.identificar(data)  + " ";

                    data.clear();
            }
            }
            break;
        case '>':
            if(data != ">")
            {
                if(cadena[i + 1])
                {
                    if(cadena[i + 1] == '=')
                    {
                        i++;
                        data += cadena[i];
                        data.erase(data.length()-2, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" +  analizador.identificar(data)  + " ";

                        data = ">=";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + ":" + analizador.identificar(data)  + " ";

                        data.clear();
                    }
                    else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + ":" + analizador.identificar(data)  + " ";

                        data = ">";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + ":" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                }
                else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + ":" + analizador.identificar(data)  + " ";
                        data = ">";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + ":" + analizador.identificar(data)  + " ";
                        data.clear();
                    }

            }else
            {
                if(cadena[i + 1] )
                {
                    if(cadena[i + 1] == '=')
                    {
                        i++;
                        data += cadena[i];
                        data = ">=";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + ":" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                    else
                    {
                        data = ">";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + ":" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                }
                else
                {
                    data = ">";
                    ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                    programa +=  data + ":" +  analizador.identificar(data)  + " ";
                    data.clear();
            }
            }
            break;
        case '=':
                    if(data != "=")
                    {
                        if(cadena[i + 1] )
                        {
                            if(cadena[i + 1] == '=')
                            {
                                i++;
                                data += cadena[i];

                                data.erase(data.length()-2, data.length());

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=   data + ":" + analizador.identificar(data)  + " ";
                                data = "==";

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=  data + ":" +  analizador.identificar(data)  + " ";
                                data.clear();

                            }
                            else
                            {
                                data.erase(data.length()-1, data.length());

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=  data + ":" +  analizador.identificar(data)  + " ";
                                data = "=";

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=  data + ":" +  analizador.identificar(data)  + " ";
                                data.clear();
                            }
                        }
                        else
                            {
                                data.erase(data.length()-1, data.length());

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=   data + ":" + analizador.identificar(data)  + " ";
                                data = "=";

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=   data + ":" + analizador.identificar(data)  + " ";
                                data.clear();
                            }

                    }else
                    {
                        if(cadena[i + 1] )
                        {
                            if(cadena[i + 1] == '=')
                            {
                                i++;
                                data += cadena[i];
                                data = "==";
                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=   data + ":" + analizador.identificar(data)  + " ";
                                data.clear();
                            }
                            else
                            {
                                data = "=";
                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=   data + ":" + analizador.identificar(data)  + " ";
                                data.clear();
                            }
                        }
                        else
                        {
                                data = "=";
                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=  data + ":" +  analizador.identificar(data)  + " ";
                                data.clear();
                        }
                    }
                    break;
        case '|':
            if(data != "|")
            {
                if(cadena[i + 1] )
                {
                    if(cadena[i + 1] == '|')
                    {
                        i++;
                        data += cadena[i];
                        data.erase(data.length()-2, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" +  analizador.identificar(data)  + " ";
                        data = "||";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + ":" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                    else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + ":" + analizador.identificar(data)  + " ";
                        data = "|";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + ":" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                }
                else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" +  analizador.identificar(data)  + " ";
                        data = "|";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + ":" + analizador.identificar(data)  + " ";
                        data.clear();
                    }

            }else
            {
                if(cadena[i + 1] )
                {
                    if(cadena[i + 1] == '|')
                    {
                        i++;
                        data += cadena[i];
                        data = "||";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" +  analizador.identificar(data)  + " ";
                        data.clear();
                    }
                    else
                    {
                        data = "|";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=   data + ":" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                }
                else
                {
                    data = "|";
                    ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                    programa +=   data + ":" + analizador.identificar(data)  + " ";
                    data.clear();
                }
            }
            break;
        case '&':
                    if(data != "&")
                    {
                        if(cadena[i + 1] )
                        {
                            if(cadena[i + 1] == '&')
                            {
                                i++;
                                data += cadena[i];

                                data.erase(data.length()-2, data.length());

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=   data + ":" + analizador.identificar(data)  + " ";
                                data = "&&";

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=   data + ":" + analizador.identificar(data)  + " ";
                                data.clear();

                            }
                            else
                            {
                                data.erase(data.length()-1, data.length());

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=  data + ":" +  analizador.identificar(data)  + " ";
                                data = "&";

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=  data + ":" +  analizador.identificar(data)  + " ";
                                data.clear();
                            }
                        }
                        else
                            {
                                data.erase(data.length()-1, data.length());

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=   data + ":" + analizador.identificar(data)  + " ";
                                data = "&";

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=  data + ":" +  analizador.identificar(data)  + " ";
                                data.clear();
                            }

                    }else
                    {
                        if(cadena[i + 1] )
                        {
                            if(cadena[i + 1] == '&')
                            {
                                i++;
                                data += cadena[i];
                                data = "&&";
                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=  data + ":" +  analizador.identificar(data)  + " ";
                                data.clear();
                            }
                            else
                            {
                                data = "&";
                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=  data + ":" +  analizador.identificar(data)  + " ";
                                data.clear();
                            }
                        }
                        else
                        {
                            data = "&";
                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                programa +=  data + ":" + analizador.identificar(data)  + " ";
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
                programa +=  data + ":" + analizador.identificar(data)  + " ";
                data.clear();
            }else
            {
                ui->listWidget->addItem(QString::fromStdString("%"));
                programa +=  data + ":" + analizador.identificar(data)  + " ";
                data.clear();
            }
            break;
        case '!':
            if(data != "!")
            {
                if(cadena[i + 1] )
                {
                    if(cadena[i + 1] == '=')
                    {
                        i++;
                        data += cadena[i];
                        data.erase(data.length()-2, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" + analizador.identificar(data)  + " ";
                        data = "!=";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                    else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" + analizador.identificar(data)  + " ";
                        data = "!";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                }
                else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" + analizador.identificar(data)  + " ";
                        data = "!";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" + analizador.identificar(data)  + " ";
                        data.clear();
                    }

            }else
            {
                if(cadena[i + 1] )
                {
                    if(cadena[i + 1] == '=')
                    {
                        i++;
                        data += cadena[i];
                        data = "!=";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                    else
                    {
                        data = "!";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                }
                else
                {
                    data = "!";
                    ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                    programa +=  data + ":" + analizador.identificar(data)  + " ";
                    data.clear();
                }
            }
            break;
        case '/':
            if(data != "/")
            {
                data.erase(data.length()-1, data.length());

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                programa +=  data + ":" + analizador.identificar(data) + " ";

                data = "/";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                programa +=  data + ":" + analizador.identificar(data)  + " ";

                data.clear();
            }else
            {

                data = "/";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                programa +=  data + ":" + analizador.identificar(data)  + " ";

                data.clear();
            }
            break;
        case '+':
            if(data != "+")
            {
                if(cadena[i + 1] )
                {
                    if(cadena[i + 1] == '+')
                    {
                        i++;
                        data += cadena[i];
                        data.erase(data.length()-2, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" + analizador.identificar(data)  + " ";
                        data = "++";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                    else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" + analizador.identificar(data)  + " ";
                        data = "+";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                }
                else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" + analizador.identificar(data)  + " ";
                        data = "+";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" + analizador.identificar(data)  + " ";
                        data.clear();
                    }

            }else
            {
                if(cadena[i + 1] )
                {
                    if(cadena[i + 1] == '+')
                    {
                        i++;
                        data += cadena[i];
                        data = "++";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                    else
                    {
                        data = "+";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                }
                else
                {
                    data = "+";
                    ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                    programa +=  data + ":" + analizador.identificar(data)  + " ";
                    data.clear();
                }
            }
            break;
        case '-':
            if(data != "-")
            {
                if(cadena[i + 1] )
                {
                    if(cadena[i + 1] == '-')
                    {
                        i++;
                        data += cadena[i];
                        data.erase(data.length()-2, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" + analizador.identificar(data)  + " ";
                        data = "--";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                    else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" + analizador.identificar(data)  + " ";
                        data = "-";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                }
                else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" + analizador.identificar(data)  + " ";

                        data = "-";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" + analizador.identificar(data)  + " ";
                        data.clear();
                    }

            }else
            {
                if(cadena[i + 1] )
                {
                    if(cadena[i + 1] == '-')
                    {
                        i++;
                        data += cadena[i];
                        data = "--";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa += data + ":" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                    else
                    {
                        data = "-";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        programa +=  data + ":" + analizador.identificar(data)  + " ";
                        data.clear();
                    }
                }
                else
                {
                    data = "-";
                    ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                    programa +=  data + ":" + analizador.identificar(data)  + " ";
                    data.clear();
                }
            }
            break;
        case '*':
            if(data != "*")
            {
                data.erase(data.length()-1, data.length());

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                programa +=  data + ":" + analizador.identificar(data) + " ";

                data = "*";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                programa +=  data + ":" + analizador.identificar(data)  + " ";

                data.clear();
            }else
            {

                data = "*";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                programa +=  data + ":" + analizador.identificar(data)  + " ";

                data.clear();
            }
            break;
        case ' ':
            if(data != " ")
            {
                data.erase(data.length()-1, data.length());
                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                programa +=  data + ":" + analizador.identificar(data)  + " ";
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

    programa+="$:Reservadas:23";

    ui->progressBar->setValue(50);

    RunPila(pila, programa);


    ui->listWidget->scrollToBottom();

};
