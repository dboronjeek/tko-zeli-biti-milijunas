#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <unistd.h>

void loadingScreen(){

    system("cls");

    int i;
    int prec[] = {25, 50, 75, 100};

    printf("\t*****************************\n");
    printf("\t******* Ucitavanje **********\n");
    printf("\t*****************************\n\n");
    printf("\t");

    for(i = 0; i < 5; i++){

        printf(" [|]  ");
        sleep(1);

    }

    system("cls");
    printf("\t*******************************************\n");
    printf("\t* Ucitavanje uspjesno, program se pokrece *\n");
    printf("\t*******************************************");
    sleep(2);
    system("cls");
}