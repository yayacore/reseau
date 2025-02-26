#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

#define SERV_PORT 2400

int main () {

// création fichier FD
int serv_fd = socket (AF_INET, SOCK_STREAM, 0); 

struct sockaddr_in addr = {
    .sin_port = htons (SERV_PORT), 
    .sin_family = AF_INET,
    .sin_addr.s_addr = INADDR_ANY // accepte  n'importe quelle adresse IP
};

// relie IP et port 
bind (serv_fd, (struct sockaddr*) &addr, sizeof (addr)); perror("bind");

// écoute
listen (serv_fd, BUFSIZ); perror ("listen");

// accept = attendre et accepter les connexions client/ bloquer
int nb_clients_accepted = 0;

// étape accept en boucle
while (1) {

    struct sockaddr client_addr;
    socklen_t len = sizeof(client_addr);
    int client_fd = accept (serv_fd, &client_addr, &len); perror ("accept");
    nb_clients_accepted ++;
    printf ("%d" , nb_clients_accepted);
    
// pour envoyer requête sur serveur
    char * message = "HTTP/1.1 200 OK\n\n/\n\n<h1>Hello</h1>";
    send (client_fd, message, strlen(message), 0); perror ("send"); // 

    close (client_fd); perror ("close client");
}
    return 0;
}










