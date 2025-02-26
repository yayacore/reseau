#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>

#define SERV_PORT 2400

 int main () {

// // int file descriptor (socket) 1ère étape

 int serv_fd = socket (AF_INET, SOCK_STREAM, 0); perror ("socket");

// // declare struct 

struct sockaddr_in ajout = {  
    .sin_family = AF_INET,
    .sin_port = htons (SERV_PORT),
    .sin_addr.s_addr = INADDR_ANY
};

// // 2ème étape relier l'IP au port : le bind 

bind (serv_fd, (struct ajout*) &ajout, sizeof (ajout)); perror ("bind");

// // 3ème étape listen : écoute du serveur + accorder 8000 octets avec BUFSIZ

listen (serv_fd, BUFSIZ); perror ("listen");

// // 4ème étape limiter, accepter connexions clients

// // déclarer client 

int client = 0;

// declarer struct pour les clients

struct sockaddr client_addr;
socklen_t len;

// // création nv fd
 int clients_fd;

 int client_fd = accept (serv_fd,&client_addr, &len); perror ("accept"); perror ("accept");
client ++;

 // dernière partie : envoyer donées (send)

char *message = "HTTP/1.1 200 OK \n\n <h1>Coucou</h1>";
send (client_fd, message, strlen(message), 0); perror ("send");

 close (client_fd);

return 0;

}