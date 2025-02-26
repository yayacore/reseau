#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>

#define SERVER_PORT 2400

int main () {

// indiquer le file descriptor, ici "serv_info"

int serv_info = socket (AF_INET, SOCK_STREAM, 0); perror ("socket");

// déclarer sockeraddrin

struct sockaddr_in addrIn = {
    .sin_family = AF_INET, 
    .sin_addr.s_addr = INADDR_ANY,
    .sin_port = htons (SERVER_PORT)
};

// relier l'adresse IP et le port avec bind 

bind (serv_info, (struct sockaddr*)&addrIn, sizeof (addrIn)); perror ("bind");

// permettre l'écoute du port

listen (serv_info, BUFSIZ); perror ("listen");

// attendre des connexions + définir client (récup nv fd, adresse, taille)
int nbClients = 0; 

struct sockaddr client_addr;
socklen_t len;
// nv fd 
int client_fd = accept (serv_info,&client_addr, &len); perror ("accept");
nbClients ++;

// dernière étape : envoyer requête sur serveur

char *signal = "HTTP/1.1 200 OK\n\n <h1>Hello</h1>";
send (client_fd, signal, strlen(signal), 0); perror ("send");

close(client_fd);

return 0;

}