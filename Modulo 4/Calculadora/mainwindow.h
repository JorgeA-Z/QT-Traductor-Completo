#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <iostream>
#include <fstream>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void B0();
    void B1();
    void B2();
    void B3();
    void B4();
    void B5();
    void B6();
    void B7();
    void B8();
    void B9();

    void sqr();
    void equl();
    void ex();
    void parI();
    void parO();

    void sum();
    void res();
    void div();
    void mul();

    void cos();
    void tan();
    void sen();

    void AC();
    void DL();
    void Dot();
    void mod();
    void prueba();

    std::string Resolver(std::string cadena);

    std::string Elevar(float cadena1, float cadena2);
    std::string Multiplicar(float cadena1, float cadena2);
    std::string Dividir(float cadena1, float cadena2);
    std::string Raiz(float cadena1);
    std::string Modular(float cadena1, float cadena2);
    std::string Sumar(float cadena1, float cadena2);
    std::string Restar(float cadena1, float cadena2);
    std::string Sen(float cadena1);
    std::string Cos(float cadena1);
    std::string Tan(float cadena1);

    //ASM FUNCTIONS
    float ASM_MUL( float $a, float $b );
    float ASM_DIV( float $a, float $b );
    float ASM_RES( float $a, float $b );
    float ASM_SUM( float $a, float $b );
    float ASM_POT( float $a, float $b );
    int ASM_MOD( int $a, int $b );
    float ASM_RAIZ( float $a);

    float ASM_COS(float $a);
    float ASM_SEN(float $a);
    float ASM_TAN(float $a);

private:
    Ui::MainWindow *ui;
    std::string display;
    std::string showed;
};
#endif // MAINWINDOW_H
