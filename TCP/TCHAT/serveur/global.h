#pragma once

#define MAX_USERS 50
int users[MAX_USERS];
int serv_fd; 
int user_fd[MAX_USERS];
int compteur_clients = 0;
int nb_data_recved;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
// #include <dirent.h> // listing des fichiers
// #include <fcntl.h>  // gérer ls fichiers
#include <sys/stat.h> 
#include <pthread.h> // pr ls threads

#define SERV_PORT 8965
#define BUF_SIZE 500

typedef struct delivery {
    int id_user;
    char message[255];
int salon;
}t_delivery; 

typedef struct room {
    int id_room;
    char name;
    int nb_users;
}t_room;
#include "fonctions.c"