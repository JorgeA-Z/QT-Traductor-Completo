#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "automata.h"
#include <string>
#include <iostream>
#include "pila.h"
#include "ep.h"
#include "t.h"
#include "e.h"
#include "nt.h"
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
void MainWindow::pila()
{
    int LR[95][46] = {0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-3,1,2,3,4,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-3,0,7,3,4,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,-5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,-6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,-8,10,11,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,-11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      -7,0,0,0,-7,0,0,0,0,0,0,0,0,0,0,0,0,-7,0,-7,-7,-7,0,-7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,-8,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,-9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,19,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,0,22,0,-13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,-10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      27,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,-16,0,28,29,30,0,0,0,0,0,25,0,0,0,0,0,23,24,0,26,0,0,0,0,0,0,31,0,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,33,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      27,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,-16,0,28,29,30,0,0,0,0,0,25,0,0,0,0,0,34,24,0,26,0,0,0,0,0,0,31,0,0,
                      -18,0,0,0,-18,0,0,0,0,0,0,0,0,0,0,0,0,-18,0,-18,-18,-18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      -19,0,0,0,-19,0,0,0,0,0,0,0,0,0,0,0,0,-19,0,-19,-19,-19,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,0,0,36,0,0,0,35,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,0,0,37,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,0,0,38,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      46,47,48,49,0,42,0,0,0,0,43,0,-30,0,41,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,0,0,44,45,0,40,
                      0,0,0,0,0,0,0,0,0,0,0,0,50,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      51,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,-15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      46,47,48,49,0,42,0,0,0,0,43,0,0,0,41,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,44,45,0,52,
                      46,47,48,49,0,42,0,0,0,0,43,0,0,0,41,-32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,53,0,44,45,0,54,
                      46,47,48,49,0,42,0,0,0,0,43,0,0,0,41,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,44,45,0,55,
                      46,47,48,49,0,42,0,0,0,0,43,0,0,0,41,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,44,45,0,56,
                      0,0,0,0,0,0,0,0,0,0,0,0,57,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,59,58,60,63,62,0,61,-31,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      46,47,48,49,0,42,0,0,0,0,43,0,0,0,41,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,44,45,0,64,
                      46,47,48,49,0,42,0,0,0,0,43,0,0,0,41,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,44,45,0,65,
                      46,47,48,49,0,42,0,0,0,0,43,0,0,0,41,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,44,45,0,66,
                      0,0,0,0,0,-53,-53,-53,-53,-53,0,-53,-53,-53,0,-53,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,-36,-36,-36,-36,-36,0,-36,-36,-36,0,-36,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,-37,-37,-37,-37,-37,0,-37,-37,-37,36,-37,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,-38,-38,-38,-38,-38,0,-38,-38,-38,0,-38,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,-39,-39,-39,-39,-39,0,-39,-39,-39,0,-39,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,-40,-40,-40,-40,-40,0,-40,-40,-40,0,-40,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      -26,0,0,0,-26,0,0,0,0,0,0,0,0,0,0,0,0,-26,0,-26,-26,-26,-26,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,0,22,0,-13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,67,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,59,58,60,63,62,0,61,68,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,69,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,59,58,60,63,62,0,61,0,71,0,-34,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70,0,0,0,0,
                      0,0,0,0,0,59,58,60,63,62,0,61,0,0,0,72,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,59,58,60,63,62,0,61,0,0,0,73,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      -25,0,0,0,-25,0,0,0,0,0,0,0,0,0,0,0,0,-25,0,-25,-25,-25,-25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      46,47,48,49,0,42,0,0,0,0,43,0,0,0,41,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,44,45,0,74,
                      46,47,48,49,0,42,0,0,0,0,43,0,0,0,41,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,44,45,0,75,
                      46,47,48,49,0,42,0,0,0,0,43,0,0,0,41,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,44,45,0,76,
                      46,47,48,49,0,42,0,0,0,0,43,0,0,0,41,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,44,45,0,77,
                      46,47,48,49,0,42,0,0,0,0,43,0,0,0,41,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,44,45,0,78,
                      46,47,48,49,0,42,0,0,0,0,43,0,0,0,41,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,44,45,0,79,
                      0,0,0,0,0,59,58,60,63,62,0,61,0,0,0,80,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,-45,-45,-45,-45,-45,0,-45,-45,-45,0,-45,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,-46,-46,-46,-46,-46,0,-46,-46,-46,0,-46,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      -22,0,0,0,-22,0,0,0,0,0,0,0,0,0,0,0,0,-22,0,-22,-22,-22,-22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,-41,-41,-41,-41,-41,0,-41,-41,-41,0,-41,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-33,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      46,47,48,49,0,42,0,0,0,0,43,0,0,0,41,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,44,45,0,81,
                      27,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,85,0,0,28,29,30,0,0,0,0,0,0,0,0,0,0,0,0,0,0,83,0,84,0,0,0,0,31,82,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,85,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,86,0,0,0,0,0,0,0,
                      0,0,0,0,0,-47,-47,-47,-47,-47,0,-47,-47,-47,0,-47,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,-48,58,-48,-48,-48,0,-48,-48,-48,0,-48,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,59,58,-49,-49,-49,0,-49,-49,-49,0,-49,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,59,58,60,-50,-50,0,-50,-50,-50,0,-50,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,59,58,60,-51,-51,0,61,-51,-51,0,-51,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,59,58,60,-52,62,0,61,-52,-52,0,-52,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,-44,-44,-44,-44,-44,0,-44,-44,-44,0,-44,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,59,58,60,63,62,0,61,0,71,0,-34,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,87,0,0,0,0,
                      -27,0,0,0,-27,0,0,0,0,0,0,0,0,0,0,0,0,-27,0,-27,-27,-27,89,0,0,0,0,0,0,0,0,0,0,0,0,0,0,88,0,0,0,0,0,0,0,0,
                      -42,0,0,0,-42,0,0,0,0,0,0,0,0,0,0,0,0,-42,0,-42,-42,-42,-42,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      -43,0,0,0,-43,0,0,0,0,0,0,0,0,0,0,0,0,-43,0,-43,-43,-43,-43,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      27,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-20,0,28,29,30,0,0,0,0,0,0,0,0,0,0,0,0,0,90,91,0,0,0,0,0,0,31,0,0,
                      -24,0,0,0,-24,0,0,0,0,0,0,0,0,0,0,0,0,-24,0,-24,-24,-24,-24,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-35,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      -23,0,0,0,-23,0,0,0,0,0,0,0,0,0,0,0,0,-23,0,-23,-23,-23,-23,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      27,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,85,0,0,28,29,30,0,0,0,0,0,0,0,0,0,0,0,0,0,0,83,0,84,0,0,0,0,31,92,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,93,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      27,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-20,0,28,29,30,0,0,0,0,0,0,0,0,0,0,0,0,0,94,91,0,0,0,0,0,0,31,0,0,
                      -28,0,0,0,-28,0,0,0,0,0,0,0,0,0,0,0,0,-28,0,-28,-28,-28,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      -29,0,0,0,-29,0,0,0,0,0,0,0,0,0,0,0,0,-29,0,-29,-29,-29,-29,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    Pila pila;
    EP* elemento;
    std::string valor;

    elemento = new T("$");

    pila.push(elemento);

    elemento = new T("0");

    pila.push(elemento);



};
void MainWindow::Lista()
{
    pila();

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
