#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "global.h"

int main (int argc, char** argv)
{

    char prenom [255];
    strcpy(prenom, argv[1]);
    printf("%s\n", prenom);



    return 0;

}