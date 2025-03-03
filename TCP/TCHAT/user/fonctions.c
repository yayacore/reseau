#pragma once
#include "global.h"

int initSocket() 
{
    int user_fd = socket(AF_INET, SOCK_STREAM, 0); perror("socket");
    if(user_fd == -1) return EXIT_FAILURE;
    
    struct sockaddr_in user = {
        .sin_family = AF_INET,
        .sin_port = htons(USER_PORT),
        .sin_addr.s_addr = INADDR_ANY

    };
    
    int error = bind(user_fd, (struct sockaddr*) &user, sizeof(user)); perror("bind");
    if(error == -1) return EXIT_FAILURE; 
    
    struct sockaddr_in serv = {
        .sin_family = AF_INET,
        .sin_port = htons(SERV_PORT),
        .sin_addr.s_addr = inet_addr("127.0.0.1")
    };
    
    error = connect(user_fd, (struct sockaddr*) &serv, sizeof(serv)); perror("connect");
    if(error == -1) return EXIT_FAILURE;

    return(user_fd);
}


void * send_routine(void *arg)
{
   t_delivery user;
   // int* user_fd= (int*)arg;
    while(1) {
        char buf[255];memset(buf, 0, 255);
        printf("send_routine\n");
        fgets(buf,sizeof(buf),stdin);
        strcpy(user.message, buf);
        
        int error = send(user_fd, &user, sizeof(t_delivery), 0); perror("send");
        if (error == -1) printf("erreur\n"); 
    }
}

void * recv_routine(void *arg)
{
    while(1)
    {
       t_delivery user;
        int error = recv(user_fd, &user, sizeof(t_delivery), 0); perror("recv");
        if(error == -1) printf("erreur\n");

        // printf("début du thread RCV\n");
        // pthread_t recv_thread;
        // pthread_create(&recv_thread, NULL, recv_routine, &serv_fd);
        // printf("fin du thread RCV \n");

        printf("%s\n", user.message);
    }
}