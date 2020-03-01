#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "main.cpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool active = false;
int from;
int to;

void MainWindow::on_v0_clicked()
{
    if(!active){
        active = true;
        ui ->deNum->setNum(0);
        from = 0;
    }
    else{
        active = false;
        ui ->aNum->setNum(0);
        to = 0;
    }
}

void MainWindow::on_v1_clicked()
{
    if(!active){
        active = true;
        ui ->deNum->setNum(1);
        from = 1;
    }
    else{
        active = false;
        ui ->aNum->setNum(1);
        to = 1;
    }

}

void MainWindow::on_v2_clicked()
{
    if(!active){
        active = true;
        ui ->deNum->setNum(2);
        from = 2;
    }
    else{
        active = false;
        ui ->aNum->setNum(2);
        to = 2;
    }
}

void MainWindow::on_v3_clicked()
{
    if(!active){
        active = true;
        ui ->deNum->setNum(3);
        from = 3;
    }
    else{
        active = false;
        ui ->aNum->setNum(3);
        to = 3;
    }
}

void MainWindow::on_v4_clicked()
{
    if(!active){
        active = true;
        ui ->deNum->setNum(4);
        from = 4;
    }
    else{
        active = false;
        ui ->aNum->setNum(4);
        to = 4;
    }

}

void MainWindow::on_v5_clicked()
{
    if(!active){
        active = true;
        ui ->deNum->setNum(5);
        from = 5;
    }
    else{
        active = false;
        ui ->aNum->setNum(5);
        to = 5;
    }
}

void MainWindow::on_v6_clicked()
{
    if(!active){
        active = true;
        ui ->deNum->setNum(6);
        from = 6;
    }
    else{
        active = false;
        ui ->aNum->setNum(6);
        to = 6;
    }
}

void MainWindow::on_v7_clicked()
{
    if(!active){
        active = true;
        ui ->deNum->setNum(7);
        from = 7;
    }
    else{
        active = false;
        ui ->aNum->setNum(7);
        to = 7;
    }
}

void MainWindow::on_v8_clicked()
{
    if(!active){
        active = true;
        ui ->deNum->setNum(8);
        from = 8;
    }
    else{
        active = false;
        ui ->aNum->setNum(8);
        to = 8;
    }
}

void MainWindow::on_buscar_clicked()
{
  string responce = sendMsg(from,to);
  QString qstr = QString::fromStdString(responce);
  ui -> res->setText(qstr);
}
