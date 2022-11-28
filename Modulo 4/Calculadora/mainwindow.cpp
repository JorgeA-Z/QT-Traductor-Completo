#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFile>
#include <stdio.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    setFixedSize(width(), height());

    QFile file(R"(C:\Users\52322\Desktop\Calculadora\Scalcula.qss)");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);

    connect(ui->pushButton0, SIGNAL(clicked()), this, SLOT(B0()));
    connect(ui->pushButton1, SIGNAL(clicked()), this, SLOT(B1()));
    connect(ui->pushButton2, SIGNAL(clicked()), this, SLOT(B2()));
    connect(ui->pushButton3, SIGNAL(clicked()), this, SLOT(B3()));
    connect(ui->pushButton4, SIGNAL(clicked()), this, SLOT(B4()));
    connect(ui->pushButton5, SIGNAL(clicked()), this, SLOT(B5()));
    connect(ui->pushButton6, SIGNAL(clicked()), this, SLOT(B6()));
    connect(ui->pushButton7, SIGNAL(clicked()), this, SLOT(B7()));
    connect(ui->pushButton8, SIGNAL(clicked()), this, SLOT(B8()));
    connect(ui->pushButton9, SIGNAL(clicked()), this, SLOT(B9()));

    connect(ui->pushButtonAC, SIGNAL(clicked()), this, SLOT(AC()));
    connect(ui->pushButtonCos, SIGNAL(clicked()), this, SLOT(cos()));
    connect(ui->pushButtonSen, SIGNAL(clicked()), this, SLOT(sen()));
    connect(ui->pushButtonTan, SIGNAL(clicked()), this, SLOT(tan()));
    connect(ui->pushButtonDiv, SIGNAL(clicked()), this, SLOT(div()));
    connect(ui->pushButtonMul, SIGNAL(clicked()), this, SLOT(mul()));
    connect(ui->pushButtonSum, SIGNAL(clicked()), this, SLOT(sum()));
    connect(ui->pushButtonRes, SIGNAL(clicked()), this, SLOT(res()));
    connect(ui->pushButtonPari, SIGNAL(clicked()), this, SLOT(parI()));
    connect(ui->pushButtonParo, SIGNAL(clicked()), this, SLOT(parO()));
    connect(ui->pushButtonSqr, SIGNAL(clicked()), this, SLOT(sqr()));
    connect(ui->pushButtonX, SIGNAL(clicked()), this, SLOT(ex()));
    connect(ui->pushButtonMod, SIGNAL(clicked()), this, SLOT(mod()));
    connect(ui->pushButtonEqual, SIGNAL(clicked()), this, SLOT(equl()));
    connect(ui->pushButtonDL, SIGNAL(clicked()), this, SLOT(DL()));
    connect(ui->pushButtonDot, SIGNAL(clicked()), this, SLOT(Dot()));
    connect(ui->pushButtonPrueba, SIGNAL(clicked()), this, SLOT(prueba()));
    display = "";
    showed += "";
    ui->label->setText(QString::fromStdString(showed));


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::B0()
{
    display += "0";
    showed += "0";
    ui->label->setText(QString::fromStdString(showed));


};
void MainWindow::B1()
{
    display += "1";
    showed += "1";
    ui->label->setText(QString::fromStdString(showed));

};
void MainWindow::B2()
{
    display += "2";
    showed += "2";
    ui->label->setText(QString::fromStdString(showed));

};
void MainWindow::B3()
{
    display += "3";
    showed += "3";
    ui->label->setText(QString::fromStdString(showed));

};
void MainWindow::B4()
{
    display += "4";
    showed += "4";
    ui->label->setText(QString::fromStdString(showed));

};
void MainWindow::B5()
{
    display += "5";
    showed += "5";
    ui->label->setText(QString::fromStdString(showed));

};
void MainWindow::B6()
{
    display += "6";
    showed += "6";
    ui->label->setText(QString::fromStdString(showed));

};
void MainWindow::B7()
{
    display += "7";
    showed += "7";
    ui->label->setText(QString::fromStdString(showed));

};
void MainWindow::B8()
{
    display += "8";
    showed += "8";
    ui->label->setText(QString::fromStdString(showed));

};
void MainWindow::B9()
{
    display += "9";
    showed += "9";
    ui->label->setText(QString::fromStdString(showed));

};
void MainWindow::sqr()
{
    display += "r";
    showed += "√";
    ui->label->setText(QString::fromStdString(showed));

};

void MainWindow::ex()
{
    display += "^";
    showed += "^";
    ui->label->setText(QString::fromStdString(showed));

};
void MainWindow::parI()
{
    display += "(";
    showed += "(";
    ui->label->setText(QString::fromStdString(showed));

};
void MainWindow::parO()
{
    display += ")";
    showed += ")";
    ui->label->setText(QString::fromStdString(showed));

};
void MainWindow::sum()
{
    display += "+";
    showed += "+";
    ui->label->setText(QString::fromStdString(showed));

};
void MainWindow::res()
{
    display += "-";
    showed += "-";
    ui->label->setText(QString::fromStdString(showed));

};
void MainWindow::div()
{
    display += "/";
    showed += "/";
    ui->label->setText(QString::fromStdString(showed));

};
void MainWindow::mul()
{
    display += "*";
    showed += "*";
    ui->label->setText(QString::fromStdString(showed));

};
void MainWindow::cos()
{
    display += "c";
    showed += "cos";
    ui->label->setText(QString::fromStdString(showed));

};
void MainWindow::tan()
{
    display += "t";
    showed += "tan";
    ui->label->setText(QString::fromStdString(showed));

};
void MainWindow::sen()
{
    display += "s";
    showed += "sen";
    ui->label->setText(QString::fromStdString(showed));

};

void MainWindow::AC()
{
    display = "";
    showed = "";
    ui->label->setText(QString::fromStdString(showed));

};

void MainWindow::mod()
{
    display += "%";
    showed += "%";
    ui->label->setText(QString::fromStdString(showed));
};

void MainWindow::DL()
{
    //sin cos tan
    if(showed[showed.length() - 1] == 'n' || showed[showed.length() - 1] == 's' || display[display.length() - 1] == 'r')
    {
        showed = showed.substr(0, showed.length() - 3);
    }
    else
    {
        showed = showed.substr(0, showed.length() - 1);
    }
    display = display.substr(0, display.length() - 1);
    ui->label->setText(QString::fromStdString(showed));
}
void MainWindow::Dot()
{
    display += ".";
    showed += ".";
    ui->label->setText(QString::fromStdString(showed));
}
void MainWindow::prueba()
{
    display = "(2*(5*(3+(6/2+(10/5)-2)/5))-10)^2";
    //display = "-8*-6+8*-2";
    ui->label->setText(QString::fromStdString(display));
};
void MainWindow::equl()
{
    std::fstream steps;
    steps.open("Steps.txt", std::fstream::app);
    steps << "-------------------OPERATION_BEGIN------------------" << std::endl;
    steps << display << std::endl;
    std::string resultado = Resolver(display);

    display = resultado;
    showed = display;
    ui->label->setText(QString::fromStdString(display));

    steps << "-------------------OPERATION_END------------------" << std::endl;

};
std::string MainWindow::Resolver(std::string cadena)
{
    //Orden Operacional:
    /*
    primero: c s t
    segundo: ()
    tercero: ^
    cuarto :  *   /   √  %
    ultimo :  +   -
    */
    std::fstream steps;
    steps.open("Steps.txt", std::fstream::app);

    std::string temp, temp2 = "", result, contenido, ERROR, numero1, numero2, operacion, op;
    ERROR = "ERROR";
    int i = 0, x = 0, begin, first = 0, last = 0;
    bool encontrado = false, operando = false, operando2 = false;

    temp = cadena;
    temp2 = cadena;
    //Antes que nada bajo este comentario hay que resolver los cos() sen() tan() con parcing Maradona (Re-Durisimo)
    //Recorrer para buscar ()
    while(i < temp.length())
    {
        if(temp[i] == '(' && !encontrado)
        {
            begin =  i - x;
            first = begin;
            encontrado = true;
            x -= 1;
        }
        else if(temp[i] == '(' && encontrado)
        {
            x = 0;
            begin =  i - x;
            first = begin;
            x -= 1;
        }
        if(encontrado)
        {
            x++;
        }
        if(temp[i] == ')' && encontrado)
        {
            encontrado = false;
            x -= 1;
        }
        else if(temp[i] == ')')
        {
            return ERROR;
        }
        //Evaluamos el contenido de (x)
        if(!encontrado && x > 0)
        {
            begin =  i - x;
            temp2 = "";
            last = i + 1;
            //Enviar paquete de cosas dentro de parentesis
            contenido = temp.substr(begin, x);
            result = Resolver(contenido);

            //Comienzo
            temp2 = temp.substr(0, first);

            //Cambio
            temp2 += result;

            //Final
            temp2 += temp.substr(last, temp.length() - i);
            temp = temp2;
            steps << temp<< std::endl;
            i = 0;
            x = 0;
            encontrado = false;
        }
        else
        {
            i++;
        }
    }

    //Esto ya funciona como la seda >:D aqui no tocar nada si no le sabes
    //Recorrer dentro de las operaciones particulares o exteriores
    i = 0;
    x = 0;
    numero1 = "-";
    temp = temp2;
    steps << temp<< std::endl;

    //Coseno, Seno, Tangente
    while(i <= temp.length())
    {
        if((temp[i] != 's' && temp[i] != 'c' && temp[i] != 't') || ((temp[i] == '+' || temp[i] == '-') && (i == 0)))
        {
            x++;
        }
        else if(operando)
        {
            x--;
            operando2 = true;
        }
        else
        {
            begin =  i - x;
            numero1 = temp.substr(begin, x);
            op = temp[i];
            operando = true;
            x = 0;
            first = begin;
        }
        if(operando)
        {
            if(temp[i] == '^' || temp[i] == 'r' || temp[i] == '*' || temp[i] == '/' || temp[i] == '%' || temp[i] == '+' || temp[i] == '-' || i == temp.length() || operando2)
            {
                x--;
                if(x < 0)
                {
                    x *= -1;
                }
                begin = i - x;
                if(x == 0)
                {
                    x = 1;
                }
                numero2 = temp.substr(begin, x);
                last = i;
                temp2 = "";
                temp2 += temp.substr(0,first);
                if(op == "c")
                {
                    result = Cos(stof(numero2));
                }
                else if(op == "s")
                {
                    result = Sen(stof(numero2));
                }
                else if(op == "t")
                {
                    result = Tan(stof(numero2));
                }
                temp2 += result;
                if(temp.length() - i > 1)
                {
                    temp2 += temp.substr(last, temp.length() - i);
                }
                temp = temp2;
                x = 1;
                i = 0;
                operando = false;
                operando2 = false;
                numero1 = "-";
            }
        }
        else if(temp[i] == '^' || temp[i] == 'r' || temp[i] == '*' || temp[i] == '/' || temp[i] == '%' || temp[i] == '+' || temp[i] == '-')
        {
           x = 0;
        }
        i++;
    }

    i = 0;
    x = 0;

    //Recorrer para buscar ^ r (de raiz)
    while(i <= temp.length())
    {
        if((temp[i] != '^' && temp[i] != 'r') || ((temp[i] == '+' || temp[i] == '-') && ((i == 0) || (operando && x == 0))))
        {
            x++;
        }
        else if(x == 0 && temp[i] != 'r')
        {
            return ERROR;
        }
        else if(operando)
        {
            x--;
            operando2 = true;
        }
        else
        {
            begin =  i - x;
            numero1 = temp.substr(begin, x);
            op = temp[i];
            operando = true;
            x = 0;
            first = begin;
        }
        if(operando)
        {
            if(((temp[i] == '+' || temp[i] == '-' || temp[i] == '*' || temp[i] == '/' || temp[i] == '%'  || i == temp.length()) && (temp[i-1] != '*' && temp[i-1] != '/' && temp[i-1] != '%')) || operando2 )
            {
                if(x < 0)
                {
                    x *= -1;
                }
                begin = i - x;
                if(x == 0)
                {
                    x = 1;
                }
                numero2 = temp.substr(begin, x);
                if(numero2[0] == '^' || numero2[0] == 'r')
                {
                    numero2 = temp.substr(begin + 1, x - 1);
                }

                last = i;
                temp2 = "";
                temp2 += temp.substr(0,first);
                if(op == "^")
                {
                    result = Elevar(stof(numero1), stof(numero2));
                }
                else if(op == "r")
                {
                    if(numero2[0] == '-')
                    {
                        numero2 = numero2.substr(1, numero2.length() - 1);
                        result = Raiz(stof(numero2));
                        result += "i";
                        return result + " -> Numero no operable";
                    }
                    else
                    {
                        result = Raiz(stof(numero2));
                    }
                }
                temp2 += result;
                if(temp.length() - i > 1)
                {
                    temp2 += temp.substr(last, temp.length() - i);
                }
                temp = temp2;
                x = 1;
                i = 0;
                operando = false;
                operando2 = false;
                numero1 = "-";
            }
        }
        else if(temp[i] == '*' || temp[i] == '/' || temp[i] == '%')
        {
           x = 0;
        }
        if(x > 0 && (temp[i] == '+' || temp[i] == '-') && i > 0)
        {
            x = 0;
        }
        i++;
    }

    i = 0;
    x = 0;

    //Acomodar orden operacional Izquierda -> Derecha para la multiplicacion y division (falta)
    //Recorrer para buscar * / %
    while(i <= temp.length())
    {
        if((temp[i] != '*' && temp[i] != '/' && temp[i] != '%') || ((temp[i] == '+' || temp[i] == '-') && ((i == 0) || (operando && x == 0))))
        {
            x++;
        }
        else if(x == 0)
        {
            return ERROR;
        }
        else if(operando)
        {
            operando2 = true;
        }
        else
        {
            begin =  i - x;
            numero1 = temp.substr(begin, x);
            op = temp[i];
            operando = true;
            x = 0;
            first = begin;
        }
        if(operando)
        {
            if(((temp[i] == '+' || temp[i] == '-' || i == temp.length()) && (temp[i-1] != '*' && temp[i-1] != '/' && temp[i-1] != '%')) || operando2 )
            {
                if(x < 0)
                {
                    x *= -1;
                }
                begin = i - x;
                if(x == 0)
                {
                    x = 1;
                }
                numero2 = temp.substr(begin, x);
                if(numero2[0] == '*' || numero2[0] == '/' || numero2[0] == '%')
                {
                    numero2 = temp.substr(begin + 1, x - 1);
                }
                last = i;
                temp2 = "";
                temp2 += temp.substr(0,first);
                if(op == "*")
                {
                    result = Multiplicar(stof(numero1), stof(numero2));
                }
                else if(op == "/")
                {
                    result = Dividir(stof(numero1), stof(numero2));
                }
                else if(op == "%")
                {
                    result = Modular(stoi(numero1), stoi(numero2));
                }
                temp2 += result;
                if(temp.length() - i > 1)
                {
                    temp2 += temp.substr(last, temp.length() - i);
                }
                temp = temp2;
                x = 1;
                i = 0;
                operando = false;
                operando2 = false;
                numero1 = "-";
            }
        }
        if(x > 0 && (temp[i] == '+' || temp[i] == '-') && i > 0)
        {
            x = 0;
        }
        i++;
    }

    i = 0;
    x = 0;
    //Recorrer para buscar + -
    while(i <= temp.length())
    {
        if((temp[i] != '+' && temp[i] != '-') || ((temp[i] == '+' || temp[i] == '-') && ((i == 0) || (operando && x == 0))))
        {
            x++;
        }
        else if(x == 0 && i > 0 && !operando)
        {
            return ERROR;
        }
        else if(operando)
        {
            operando2 = true;
        }
        else if(i > 0)
        {
            if(temp[i] == '-')
            {
                if(temp[i-1] == '-')
                {

                }
            }
            begin =  i - x;
            numero1 = temp.substr(begin, x);
            op = temp[i];
            operando = true;
            x = 0;
            first = begin;
        }
        if(operando)
        {
            if(((i == temp.length())  && (temp[i-1] != '+' && temp[i-1] != '-')) || operando2 )
            {
                if(numero1 == "-")
                {
                    numero1 = "1";
                }
                //x--;
                if(x < 0)
                {
                    x *= -1;
                }
                begin = i - x;
                if(x == 0)
                {
                    x = 1;
                }
                numero2 = temp.substr(begin + 1, x);
                if(numero2[numero2.length()-1] == '+' || numero2[numero2.length()-1] == '-')
                {
                    numero2 = temp.substr(begin, x);
                }
                last = i;

                temp2 = "";
                temp2 += temp.substr(0,first);
                if(op == "+")
                {
                    result = Sumar(stof(numero1), stof(numero2));
                }
                else if(op == "-")
                {
                    result = Restar(stof(numero1), stof(numero2));
                }
                temp2 += result;
                if(temp.length() - i > 1)
                {
                    temp2 += temp.substr(last, temp.length() - i);
                }
                temp = temp2;
                x = 1;
                i = 0;
                operando = false;
                operando2 = false;
                numero1 = "-";
            }
        }
        i++;
    }

    temp = temp2;
    steps << std::endl << temp<< std::endl << std::endl;
    steps.close();
    return temp;
};

std::string MainWindow::Elevar(float num1, float num2)
{

    float result = ASM_POT(num1,num2);
    return std::to_string(result);
}
std::string MainWindow::Multiplicar(float num1, float num2)
{
    float result = ASM_MUL(num1, num2);
    return std::to_string(result);
}
std::string MainWindow::Dividir(float num1, float num2)
{
    float result = ASM_DIV(num1, num2);
    return std::to_string(result);
}
std::string MainWindow::Raiz(float num1)
{
    float result = ASM_RAIZ(num1);
    return std::to_string(result);
}
std::string MainWindow::Modular(float num1, float num2)
{
    float result = ASM_MOD(num1, num2);

    return std::to_string(result);
}
std::string MainWindow::Sumar(float num1, float num2)
{
    float result = ASM_SUM(num1, num2);
    return std::to_string(result);
};
std::string MainWindow::Restar(float num1, float num2)
{
    float result = ASM_RES(num1, num2);
    return std::to_string(result);
}
std::string MainWindow::Sen(float num1)
{
    float result = ASM_SEN(num1);

    return std::to_string(result);
}
std::string MainWindow::Cos(float num1)
{
    float result = ASM_COS(num1);

    return std::to_string(result);
}
std::string MainWindow::Tan(float num1)
{
    float result = ASM_TAN(num1);

    return std::to_string(result);
}
//ASM FUNCTIONS
//SUMA //READY->
float MainWindow::ASM_SUM(float $a, float $b)
{
    float $result;
    __asm__ __volatile__ (
        "fld %1;"
        "fld %2;"
        "faddp;"
        "fstp %0;" : "=m" ($result) : "g"($a) , "g"($b)
    );
    return $result ;
}
//MODULO
int MainWindow::ASM_MOD(int $a, int $b)
{
    int $result;
    __asm__ __volatile__ (
        "movl %1, %%eax;"
        "movl %2, %%edi;"
        "xorl %%edx, %%edx;"
        "divl %%edi;"
        "movl %%edx,%0;" : "=g" ( $result ) : "g" ( $a ), "g" ( $b )
    );
    return $result ;
}
//RESTA //READY->
float MainWindow::ASM_RES(float $a, float $b)
{
    float $result;
    __asm__ __volatile__ (
        "fld %2;"
        "fld %1;"
        "fsubp;"
        "fstp %0;" : "=m" ($result) : "g"($a) , "g"($b)
    );
    return $result;
}
//MULTIPLICACION //READY->
float MainWindow::ASM_MUL(float $a, float $b)
{
    float $result;
    __asm__ __volatile__ (
        "fld %1;"
        "fld %2;"
        "fmulp;"
        "fstp %0;" : "=m" ($result) : "g"($a) , "g"($b)
    );
    return $result ;
}
//DIVISION //READY->
float MainWindow::ASM_DIV(float $a, float $b)
{
    float $result;
    __asm__ __volatile__ (
        "fld %2;"
        "fld %1;"
        "fdivp;"
        "fstp %0;" : "=m" ($result) : "g"($a) , "g"($b)
    );
    return $result ;
}
//POTENCIA //READY->
float MainWindow::ASM_POT(float $a, float $b)
{
    float $result = $a;

    while($b > 1)
    {
        $result = ASM_MUL($result, $a);
        $b--;
    }

    return $result;
};
//RAIZ //READY->
float MainWindow::ASM_RAIZ(float $a)
{
    float $result;

    __asm__ __volatile__ (
        "fld %1;"

        "fsqrt;"

        "fstp %0;" : "=m" ($result) : "g"($a)
    );
    return $result;
};
//COSENO //READY->
float MainWindow::ASM_COS(float $a)
{
    float $result;

    __asm__ __volatile__ (
        "fld %1;"

        "fcos;"

        "fstp %0;" : "=m" ($result) : "g"($a)
    );
    return $result;
};
//SENO //READY->
float MainWindow::ASM_SEN(float $a)
{
    float $result;

    __asm__ __volatile__ (
        "fld %1;"

        "fsin;"

        "fstp %0;" : "=m" ($result) : "g"($a)
    );
    return $result;
};
//TAN //READY->
float MainWindow::ASM_TAN(float $a)
{
    float result1 = ASM_SEN($a);
    float result2 = ASM_COS($a);

    float result = ASM_DIV(result1, result2);
    return result;
};
