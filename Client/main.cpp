#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;

int main() {

    //Crear el socket
    int clt_socket = socket(AF_INET,SOCK_STREAM,0);
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
        cerr << "Error al conectar" << endl;
        return 1;
    }else{
        cout << "Conexion con servidor establecida exitosamente!\n";
    }


    //loop

    char buffer[4096];
    string userInp;

    do{

        getline(cin,userInp);
        int sendMsg = send(clt_socket,userInp.c_str(),userInp.size()+1,0);

        if (sendMsg == -1){
            cout << "Mensaje no enviado al servidor";
            continue;
        }


        memset(buffer,0,4096);
        int bytesReceived = recv(clt_socket,buffer,4069,0);
        if (bytesReceived == 0) {
            cout << "Se ha perdido la conexion con el servidor";
            break;
        }
        cout << string(buffer,bytesReceived);

    } while (true);

    close(clt_socket);

    return 0;
}
