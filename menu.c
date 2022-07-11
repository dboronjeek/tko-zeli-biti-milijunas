#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>


int menu(int choice){

    
    system("cls");

    do{
        int kosa = 47;
        int kosaObrnuta = 92;
        int kObrnuta = 92;

        printf("****************************************************************\n");
        printf("* __  __ _____ _      _____     _ _    _ _   _           _____ *\n");
        printf("*|  %c%c  |_   _| |    |_   _|   | | |  | | %c | |   /%c    / ____|*\n", kosaObrnuta, kosa, kObrnuta);
        printf("*| %c  %c | | | | |      | |     | | |  | |  %c| |  /  %c  | (___  *\n", kosaObrnuta, kosa, kObrnuta);
        printf("*| |%c%c| | | | | |      | | _   | | |  | | . ` | / /%c %c  %c___ %c *\n", kosaObrnuta, kosa, kosaObrnuta, kosaObrnuta, kosaObrnuta, kosaObrnuta);
        printf("*| |  | |_| |_| |____ _| || |__| | |__| | |%c  |/ ____ %c ____) |*\n", kosaObrnuta, kosaObrnuta);
        printf("*|_|  |_|_____|______|_____%c____/ %c____/|_| %c_/_/    %c_%c_____/ *\n", kosaObrnuta, kosaObrnuta, kosaObrnuta, kosaObrnuta, kosaObrnuta);
        
        printf("**************************IZBORNIK******************************\n");
        printf("*       \t1.)\tPokreni igru.                          *\n");
        printf("*       \t2.)\tPogledaj 'score' tablicu.              *\n");
        printf("*       \t3.)\tIzadji iz igre                         *\n");
        printf("****************************************************************\n");
        printf("\nTvoj odabir: "); 
        scanf("%d", &choice);
        
        
        switch(choice){

            case 1:
                    //Pokreni igru
                    system("cls");
            break;

            case 2:
                    //Pogledaj score tablicu
                    exit(0);
                    system("cls");
            break;

            case 3:
                    system("cls");
                    exit(0);
                
            break;

            default:
                    system("cls");    
                    printf("Krivi odabir ponovi unos\n\n");
            break;
        }

    }while(choice != 3);
    return 0;
}
