// EXO CLIENT 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>

//#define SERV_PORT 2400
#define CLIENT_PORT 3000

 int main () {

int client_fd = socket (AF_INET, SOCK_STREAM, 0);

struct sockaddr_in add = {
    .sin_family = AF_INET,
    .sin_port = htons (CLIENT_PORT),
    .sin_addr.s_addr = INADDR_ANY
};

bind (client_fd, (struct sockadd *)&add, sizeof (add)); perror ("bind");

//listen (serv_fd, BUFSIZ); perror ("listen");

int clients = 0;

while (1) {
    struct sockaddr client; 
    socklen_t len;
    int client_fd = accept (client_fd, &add, &len); perror ("accept");
    clients ++;

    char *message = "HTTP/1.1 200 OK\n\n <h1>EXERCICE</h1>";
    recv (client_fd, message, strlen(message), 0); perror ("rcv");
    close (client_fd);
}

    return 0;
}