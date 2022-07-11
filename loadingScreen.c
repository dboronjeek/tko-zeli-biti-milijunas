#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <unistd.h>

void loadingScreen(){

    system("cls");

    int i;
    int prec[] = {25, 50, 75, 100};

    printf("*****************************\n");
    printf("******* Ucitavanje **********\n");
    printf("*****************************\n\n");

    for(i = 0; i < 5; i++){

        printf(" [|]  ");
        sleep(1);

    }

    system("cls");

    printf("\tUcitavanje uspjesno, program se pokrece");
    sleep(1);
    system("cls");
}