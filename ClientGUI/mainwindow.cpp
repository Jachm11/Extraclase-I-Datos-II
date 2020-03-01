#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
using namespace std;

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

int clt_socket;
bool unconnected = true;
bool active = false;
int from;
int to;

int socketExe(){

    //Crear el socket
        clt_socket = socket(AF_INET,SOCK_STREAM,0);
        if (clt_socket == -1){
            cerr << "No se pudo crear el socket";
            return -1;
        }

        // El hint para el server al que nos conectamos
        int port = 54000;

        string ipAddr = "127.0.0.1";

        sockaddr_in hint;
        hint.sin_family = AF_INET;
        hint.sin_port = htons(port);
        inet_pton(AF_INET,ipAddr.c_str(), &hint.sin_addr);

        // Conectar al server

        int connectRes = connect(clt_socket, (sockaddr*)&hint, sizeof(sockaddr_in));
        if (connectRes == -1){
            cerr << "Error al conectar: Programa finalizado" << endl;
            return -1;
        }else{
            cout << "Conexion con servidor establecida exitosamente!\n";
            unconnected = false;
            return clt_socket;
        }
}


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

string sendMsg(int in, int out){

        string inout = to_string(in) += to_string(out);
        char buffer[4096];

        int sendMsg = send(clt_socket,inout.c_str(),inout.size()+1,0);

        if (sendMsg == -1){
            cout << "Mensaje no enviado al servidor";
            }

        memset(buffer,0,4096);
        int bytesReceived = recv(clt_socket,buffer,4069,0);
        if (bytesReceived == 0) {
           cout << "Se ha perdido la conexion con el servidor";
            }
        cout << string(buffer,bytesReceived);
        return string(buffer);
}

void MainWindow::on_buscar_clicked()
{
    if (unconnected){
    socketExe();
    }
  string responce = sendMsg(from,to);
  QString qstr = QString::fromStdString(responce);
  ui -> res->setText(qstr);
}
