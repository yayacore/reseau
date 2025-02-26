#include "global.h"

int main () 
{
    
    serv_fd = initSocket();
    
    pthread_t accept_thread;
    pthread_create(&accept_thread, NULL, accept_routine, NULL);
    pthread_join(accept_thread,NULL);
    
    char buf[255]; memset(buf, 0, 255);

    close(serv_fd);

    return 0;
}