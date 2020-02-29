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
    int srv_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (srv_socket == -1){
        cerr << "No se pudo crear el socket";
        return -1;
    }

    // Ligar (bind) a un puerto o IP
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000); //host to network short
    inet_pton(AF_INET,"0.0.0.0",&hint.sin_addr);

    if (bind(srv_socket,(sockaddr*) &hint, sizeof(hint)) == -1){
         cerr << "No se pudo ligar al IP/puerto";
         return -2;
    }


    // Poner el socket a escuchar
    if(listen(srv_socket, SOMAXCONN) == -1){
        cerr << "Not srv_socket" ;
    }

    // Aceptar llamadas
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);
    char host [NI_MAXHOST];
    char svc[NI_MAXSERV];

    int clt_socket = accept(srv_socket,(sockaddr*)&client,&clientSize);

    if (clt_socket == -1) {
        cerr << "Promeblemas con el cliente";
    }

    char buffer [4096] = {0};

    while (true){
        memset(buffer,0,4096);
        int bytesRecv = recv(clt_socket,buffer,4096,0);
        if (bytesRecv == -1){
            cerr << "Hubo un error de coneccion" << endl;
            break;
        }

        if (bytesRecv == 0){
            cout << "El cliente se ha desconectado" << endl;
            break;
        }
        cout << string(buffer, 0 , bytesRecv) << endl;

    }

    return 0;
}
