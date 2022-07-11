#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <unistd.h>
#include <string.h>

void loadingScreen(){

    system("cls");

    int i;
    
    printf("\t*****************************\n");
    printf("\t******* Ucitavanje **********\n");
    printf("\t*****************************\n\n");
    printf("\t");

    for(i = 0; i < 5; i++){

        printf(" [|]  ");
        usleep(500000);

    }

    system("cls");
    printf("\t********************************************\n");
    printf("\t*** Ucitavanje uspjesno, igra se pokrece ***\n");
    printf("\t********************************************");
    sleep(2);
    system("cls");
}