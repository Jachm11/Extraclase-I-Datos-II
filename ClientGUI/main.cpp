#include "mainwindow.h"
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

int clt_socket;

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
            return clt_socket;
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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    int client = (socketExe());
    if (client == -1){
        return 1;
    }
    w.show();
    return a.exec();

}
