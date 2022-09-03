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
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(Lista()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Lista()
{
    QString texto = ui->textEdit->toPlainText();
    QString op;
    int i = 0;
    char c;
    Automata analizador;

    std::string cadena = texto.toStdString();

    std::string data;
    QString s;

    ui->listWidget->clear();

    ui->textEdit->clear();
    cadena+= "\n";

    while (i < cadena.length())
    {
        c = cadena[i];


        switch(c)
        {
        case '\n':
            op = QString::fromStdString(analizador.identificar(data));

            if(op == "No Identificado")
            {
                s = QChar(0x0058);
            }else
            {
                s = QChar(0x2713);
            }
             ui->listWidget->addItem(QString::fromStdString(data) + " : "+ op + " " +s);



            data.clear();

        default:
            if(c != '\n')
            {
                data+= c;
            }


        }

        i++;
    }

};
