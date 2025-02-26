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

struct sockaddr_in serv_addr = {
    .sin_addr.s_addr = inet_addr("127.0.0.1"),
    .sin_port =htons(3000),
    .sin_family = AF_INET
};

connect(client_fd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

    return 0;
}