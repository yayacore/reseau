#pragma once
#include "global.h"

/*
mise en place du socket serveur, 
liaison et écoute sur le port choisi
*/

int initSocket() {

    int serv_fd = socket(AF_INET, SOCK_STREAM, 0); perror("socket");
    if(serv_fd == -1) return EXIT_FAILURE;

    struct sockaddr_in serv = {
        .sin_family = AF_INET,
        .sin_port = htons(SERV_PORT),
        .sin_addr.s_addr = INADDR_ANY

    };

    int error = bind(serv_fd, (struct sockaddr*) &serv, sizeof(serv)); perror("bind");
    if(error == -1) return EXIT_FAILURE;

    error = listen(serv_fd, BUFSIZ); perror("listen");
    if(error == -1) return EXIT_FAILURE;

    printf("\nÉcoute en cours sur le port %d\n", SERV_PORT);

    return(serv_fd);
}

/*
boucle pour obtenir les "recv" des clients en boucle
+ thread ? 
*/

void * recv_routine(void *arg)
{
    printf("recv_routine\n");
    
    int fd = *(int*) arg;   // transtypage void* arg en int

    t_delivery user;
    char buf[255]; memset(buf, 0, 255);
    strcpy(user.message, buf);
    
    while(1) 
    {
        
        int nb_data_recved = recv(fd, &user, sizeof(t_delivery), 0); perror("rcv"); // *fd pour accéder à la valeur pointée
        
        if(nb_data_recved == -1)
        {
            printf("erreur rcv//\n");
            continue;
        }
        
        if(nb_data_recved == 0)
        {
            printf("utilisateur gone  :'(\n");continue;
            //s ici entrer le code en cas d'utilisateur parti
            // nb_users_quittants ++ ?
        }
        
        printf("%s\n", user.message);
    }
}

/*
fonction "accept" pour pouvoir modifier le fd client, 

*/

void * accept_routine(void *arg)
{
    // "struct" client
    struct sockaddr_in user;
    socklen_t len;
    printf("accept_routine\n");

    for(int i = 0; i < MAX_USERS; i++) {

        int fd = accept(serv_fd, (struct sockaddr*)&user, &len); perror("accept");  // fd = valeur tampon
        int client_fd = fd;
        compteur_clients ++;
        pthread_t recv_thread;
        pthread_create(&recv_thread, NULL, recv_routine, &client_fd);
        pthread_join(recv_thread,NULL);
    }    
}

/*
commentaire 
multiligne 
pour expliquer à quoi sert la fonction
*/

void * traitement_rcv(void *arg)
{
    
    
// recup rcv client pour send au bon destinataire.


}