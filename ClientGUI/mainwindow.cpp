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

///
/// \brief clt_socket Varaibe que guarda la direccion del socket
///
int clt_socket;
///
/// \brief unconnected Boleano para saber si la conexion ya fue establecida
///
bool unconnected = true;
///
/// \brief active El primer veritece fue seleccionado
///
bool active = false;
///
/// \brief from De que vertice voy
///
int from;
///
/// \brief to A que vertice voy
///
int to;

/**
 * @brief socketExe es la funcion encargada de crear el socket de cliente y conectarlo al sevidor
 * @return retorna un entero que indica el estado del socket, -1 si falló, 1 si todo salió bien
 */

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

/**
 * @brief MainWindow::on_v0_clicked cambia el valor de in o out segun el input anterior
 */

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

/**
 * @brief MainWindow::on_v1_clicked cambia el valor de in o out segun el input anterior
 */
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
/**
 * @brief MainWindow::on_v2_clicked cambia el valor de in o out segun el input anterior
 */

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

/**
 * @brief MainWindow::on_v3_clicked cambia el valor de in o out segun el input anterior
 */

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

/**
 * @brief MainWindow::on_v4_clicked cambia el valor de in o out segun el input anterior
 */

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
/**
 * @brief MainWindow::on_v5_clicked cambia el valor de in o out segun el input anterior
 */
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
/**
 * @brief MainWindow::on_v6_clicked cambia el valor de in o out segun el input anterior
 */

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

/**
 * @brief MainWindow::on_v7_clicked cambia el valor de in o out segun el input anterior
 */
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

/**
 * @brief MainWindow::on_v8_clicked cambia el valor de in o out segun el input anterior
 */
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

/**
 * @brief sendMsg
 * @param in Indica el vertice del que se quiere salir
 * @param out Indica el vertice al que se quiere llegar
 * @return retorna la respuesta del servidor
 */
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

/**
 * @brief MainWindow::on_buscar_clicked si no se ha creado el socket lo crea y manda un mesaje al servidor, sino solo manda el mensaje
 */

void MainWindow::on_buscar_clicked()
{
    if (unconnected){
    socketExe();
    }
  string responce = sendMsg(from,to);
  QString qstr = QString::fromStdString(responce);
  ui -> res->setText(qstr);
}
