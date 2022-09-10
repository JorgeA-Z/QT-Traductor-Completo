#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "automata.h"
#include <string>
#include <iostream>
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
void MainWindow::Lista()
{
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

                data = "(";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                data.clear();
            }else
            {

                data = "(";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                data.clear();
            }
            break;
        case '{':
            if(data != "{")
            {
                data.erase(data.length()-1, data.length());


                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                data = "{";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                data.clear();
            }else
            {

                data = "{";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                data.clear();
            }
            break;
        case ')':
            if(data != ")")
            {
                data.erase(data.length()-1, data.length());


                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                data = ")";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                data.clear();
            }else
            {

                data = ")";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                data.clear();
            }
            break;
        case '}':
            if(data != "}")
            {
                data.erase(data.length()-1, data.length());


                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                data = "}";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                data.clear();
            }else
            {

                data = "}";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                data.clear();
            }
            break;
        case '[':
            if(data != "[")
            {
                data.erase(data.length()-1, data.length());


                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                data = "[";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                data.clear();
            }else
            {

                data = "[";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                data.clear();
            }
            break;
        case ']':
            if(data != "]")
            {
                data.erase(data.length()-1, data.length());


                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                data = "]";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                data.clear();
            }else
            {

                data = "]";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                data.clear();
            }
            break;
        case ';':
            if(data != ";")
            {
                data.erase(data.length()-1, data.length());


                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                data = ";";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                data.clear();
            }else
            {

                data = ";";

                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
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
                        data = "<=";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data.clear();
                    }
                    else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data = "<";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data.clear();
                    }
                }
                else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data = "<";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
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
                        data.clear();
                    }
                    else
                    {
                        data = "<";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data.clear();
                    }
                }
                else
                {
                    data = "<";
                    ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
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
                        data = ">=";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data.clear();
                    }
                    else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data = ">";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data.clear();
                    }
                }
                else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data = ">";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
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
                        data.clear();
                    }
                    else
                    {
                        data = ">";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data.clear();
                    }
                }
                else
                {
                    data = ">";
                    ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
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

                                data = "==";

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                                data.clear();

                            }
                            else
                            {
                                data.erase(data.length()-1, data.length());

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                                data = "=";

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                                data.clear();
                            }
                        }
                        else
                            {
                                data.erase(data.length()-1, data.length());

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                                data = "=";

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

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
                                data.clear();
                            }
                            else
                            {
                                data = "=";
                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                data.clear();
                            }
                        }
                        else
                        {
                                data = "=";
                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
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
                        data = "||";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data.clear();
                    }
                    else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data = "|";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data.clear();
                    }
                }
                else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data = "|";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
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
                        data.clear();
                    }
                    else
                    {
                        data = "|";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data.clear();
                    }
                }
                else
                {
                    data = "|";
                    ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
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

                                data = "&&";

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                                data.clear();

                            }
                            else
                            {
                                data.erase(data.length()-1, data.length());

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                                data = "&";

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                                data.clear();
                            }
                        }
                        else
                            {
                                data.erase(data.length()-1, data.length());

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

                                data = "&";

                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));

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
                                data.clear();
                            }
                            else
                            {
                                data = "&";
                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                data.clear();
                            }
                        }
                        else
                        {
                            data = "&";
                                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                                data.clear();
                        }
                    }
            break;
        case '%':
            if(data != "%")
            {
                data.erase(data.length()-1, data.length());
                ui->listWidget->addItem(QString::fromStdString(data));
                ui->listWidget->addItem(QString::fromStdString("%"));
                data.clear();
            }else
            {
                ui->listWidget->addItem(QString::fromStdString("%"));
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
                        data = "!=";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data.clear();
                    }
                    else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data = "!";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data.clear();
                    }
                }
                else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data = "!";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
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
                        data.clear();
                    }
                    else
                    {
                        data = "!";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data.clear();
                    }
                }
                else
                {
                    data = "!";
                    ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                    data.clear();
                }
            }
            break;
        case '/':
            if(data != "/")
            {
                data.erase(data.length()-1, data.length());
                ui->listWidget->addItem(QString::fromStdString(data));
                ui->listWidget->addItem(QString::fromStdString("/"));
                data.clear();
            }else
            {
                ui->listWidget->addItem(QString::fromStdString("("));
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
                        data = "++";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data.clear();
                    }
                    else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data = "+";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data.clear();
                    }
                }
                else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data = "+";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
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
                        data.clear();
                    }
                    else
                    {
                        data = "+";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data.clear();
                    }
                }
                else
                {
                    data = "+";
                    ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
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
                        data = "--";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data.clear();
                    }
                    else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data = "-";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data.clear();
                    }
                }
                else
                    {
                        data.erase(data.length()-1, data.length());
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data = "-";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
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
                        data.clear();
                    }
                    else
                    {
                        data = "-";
                        ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                        data.clear();
                    }
                }
                else
                {
                    data = "-";
                    ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
                    data.clear();
                }
            }
            break;
        case '*':
            if(data != "*")
            {
                data.erase(data.length()-1, data.length());
                ui->listWidget->addItem(QString::fromStdString(data));
                ui->listWidget->addItem(QString::fromStdString("*"));
                data.clear();
            }else
            {
                ui->listWidget->addItem(QString::fromStdString("*"));
                data.clear();
            }
        case ' ':
            if(data != " ")
            {
                data.erase(data.length()-1, data.length());
                ui->listWidget->addItem(QString::fromStdString(data) + " : " +QString::fromStdString(analizador.identificar(data)));
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

};
