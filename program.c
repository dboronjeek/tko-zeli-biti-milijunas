#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#include "logo.c"

#define FILENAME_SIZE 1024
#define MAX_LINE 2048

typedef struct scoreTable{

    char nickname[11];
    int scoreNumber;

}SCORE;


void firstQuestion(int);
int randNumber(int);
int questRead(int);

void scoreTable(SCORE s){
    
    
    int money[] = {
        100, 200, 300, 500, 1000,
        2000, 4000, 8000, 16000, 32000,
        64000, 1250000, 250000, 500000, 1000000
    };

    printf("Unesi svoj nadimak (ne vise od 10 znakova): ");
    gets(s.nickname);
    gets(s.nickname);

    FILE* fp = NULL;
    fp = fopen("score.txt", "a");

    if(s.scoreNumber == -1){
        fprintf(fp, "%s - 0 HRK\n", s.nickname);
    }

    else{
        fprintf(fp, "%s - %d HRK\n", s.nickname, money[s.scoreNumber]);
    }
    
    fclose(fp);

    system("cls");
    int a = 0;
    menu(a);
}

void seeScoreTable(){
    
    char score[1024];
    FILE* fp = NULL;
    char ans[2];
    char da[] = {"da"};

    printf("********************* 'SCORE' TABLICA *********************\n");
    fp = fopen("score.txt", "r");

    while (fgets(score, 1024, fp) != NULL){
        
        printf("%s", score);
    }
    printf("\n***********************************************************");
    fclose(fp);

    printf("\nPovratak u izbornik (da/ne): ");
    gets(ans);
    gets(ans);

    if(strcmp(da, ans) == 0){
        menu(0);
    }

    else exit(0);
}

//PITANJA
char openQuestionsFile(){
    
    SCORE s;
    s.scoreNumber = -1;
    int r;

    system("cls");
    sleep(1);

    char ans;

    int question = 0;

    int money[] = {
        100, 200, 300, 500, 1000,
        2000, 4000, 8000, 16000, 32000,
        64000, 1250000, 250000, 500000, 1000000
    };
     
    for(int i = 0; i < 15; i++){
        
        r = randNumber(r);

        if(r == 1){
            
            if(question == 0){

                printLogo();
                questRead(1);
                questRead(2);
                questRead(3);
                
                printf("Vas odgovor: ");
                scanf(" %c", &ans);

                if(ans == 'a' || ans == 'A'){
                    
                    system("cls");
                    printf("Tocan odgovor, osvojili ste 100 HRK");
                    sleep(1);
                    system("cls");
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste 0 HRK");
                    sleep(1);
                    system("cls");
                    scoreTable(s);
                }

            }

            else if(question == 1){

                printLogo();
                questRead(1 + 16);
                questRead(2 + 16);
                questRead(3 + 16);
                
                printf("Vas odgovor: ");
                scanf(" %c", &ans);

                if(ans == 'a' || ans == 'A'){
                    
                    system("cls");
                    printf("Tocan odgovor, osvojili ste %d HRK", money[question]);
                    sleep(1);
                    system("cls");
    
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste %d HRK", money[question - 1]);
                    sleep(1);
                    system("cls");
                    scoreTable(s);
                }
            }

            else if(question == 15){
                
                printLogo();
                questRead(1 + 16 * question);
                questRead(2 + 16 * question);
                questRead(3 + 16 * question);
                
                printf("Vas odgovor: ");
                scanf(" %c", &ans);

                if(ans == 'a' || ans == 'A'){
                    
                    system("cls");
                    printf("Tocan odgovor, osvojili ste %d HRK", money[question]);
                    sleep(1);
                    system("cls");
                    scoreTable(s);
    
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste %d HRK", money[question - 1]);
                    sleep(1);
                    system("cls");
                    scoreTable(s);
                }

            }

            else{

                printLogo();
                questRead(1 + 16 * question);
                questRead(2 + 16 * question);
                questRead(3 + 16 * question);
                
                printf("Vas odgovor: ");
                scanf(" %c", &ans);

                if(ans == 'a' || ans == 'A'){
                    
                    system("cls");
                    printf("Tocan odgovor, osvojili ste %d HRK", money[question]);
                    sleep(1);
                    system("cls");
    
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste %d HRK", money[question - 1]);
                    sleep(1);
                    system("cls");
                    scoreTable(s);
                }

            }



        }

        if(r == 2){
            
            if(question == 0){

                printLogo();
                questRead(5);
                questRead(6);
                questRead(7);
                
                printf("Vas odgovor: ");
                scanf(" %c", &ans);

                if(ans == 'b' || ans == 'B'){
                    
                    system("cls");
                    printf("Tocan odgovor, osvojili ste 100 HRK");
                    sleep(1);
                    system("cls");
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste 0 HRK");
                    sleep(1);
                    system("cls");
                    scoreTable(s);
                }

            }

            else if(question == 1){

                printLogo();
                questRead(5 + 16);
                questRead(6 + 16);
                questRead(7 + 16);
                
                printf("Vas odgovor: ");
                scanf(" %c", &ans);

                if(ans == 'b' || ans == 'B'){
                    
                    system("cls");
                    printf("Tocan odgovor, osvojili ste %d HRK", money[question]);
                    sleep(1);
                    system("cls");
    
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste %d HRK", money[question - 1]);
                    sleep(1);
                    system("cls");
                    scoreTable(s);
                }
            }

            else if(question == 15){
                
                printLogo();
                questRead(5 + 16 * question);
                questRead(6 + 16 * question);
                questRead(7 + 16 * question);
                
                printf("Vas odgovor: ");
                scanf(" %c", &ans);

                if(ans == 'b' || ans == 'B'){
                    
                    system("cls");
                    printf("Tocan odgovor, osvojili ste %d HRK", money[question]);
                    sleep(1);
                    system("cls");
                    scoreTable(s);
    
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste %d HRK", money[question - 1]);
                    sleep(1);
                    system("cls");
                    scoreTable(s);
                }

            }

            else{

                printLogo();
                questRead(5 + 16 * question);
                questRead(6 + 16 * question);
                questRead(7 + 16 * question);
                
                printf("Vas odgovor: ");
                scanf(" %c", &ans);

                if(ans == 'b' || ans == 'B'){
                    
                    system("cls");
                    printf("Tocan odgovor, osvojili ste %d HRK", money[question]);
                    sleep(1);
                    system("cls");
    
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste %d HRK", money[question - 1]);
                    sleep(1);
                    system("cls");
                    scoreTable(s);
                }

            }
        }

        if(r == 3){
            
            if(question == 0){

                printLogo();
                questRead(9);
                questRead(10);
                questRead(11);
                
                printf("Vas odgovor: ");
                scanf(" %c", &ans);

                if(ans == 'c' || ans == 'C'){
                    
                    system("cls");
                    printf("Tocan odgovor, osvojili ste 100 HRK");
                    sleep(1);
                    system("cls");
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste 0 HRK");
                    sleep(1);
                    system("cls");
                    scoreTable(s);
                }

            }

            else if(question == 1){

                printLogo();
                questRead(9 + 16);
                questRead(10 + 16);
                questRead(11 + 16);
                
                printf("Vas odgovor: ");
                scanf(" %c", &ans);

                if(ans == 'c' || ans == 'C'){
                    
                    system("cls");
                    printf("Tocan odgovor, osvojili ste %d HRK", money[question]);
                    sleep(1);
                    system("cls");
    
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste %d HRK", money[question - 1]);
                    sleep(1);
                    system("cls");
                    scoreTable(s);
                }
            }

            else if(question == 15){
                
                printLogo();
                questRead(9 + 16 * question);
                questRead(10 + 16 * question);
                questRead(11 + 16 * question);
                
                printf("Vas odgovor: ");
                scanf(" %c", &ans);

                if(ans == 'c' || ans == 'C'){
                    
                    system("cls");
                    printf("Tocan odgovor, osvojili ste %d HRK", money[question]);
                    sleep(1);
                    system("cls");
                    scoreTable(s);
    
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste %d HRK", money[question - 1]);
                    sleep(1);
                    system("cls");
                    scoreTable(s);
                }

            }

            else{

                printLogo();
                questRead(9 + 16 * question);
                questRead(10 + 16 * question);
                questRead(11 + 16 * question);
                
                printf("Vas odgovor: ");
                scanf(" %c", &ans);

                if(ans == 'c' || ans == 'C'){
                    
                    system("cls");
                    printf("Tocan odgovor, osvojili ste %d HRK", money[question]);
                    sleep(1);
                    system("cls");
    
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste %d HRK", money[question - 1]);
                    sleep(1);
                    system("cls");
                    scoreTable(s);
                }

            }

        }

        if(r == 4){
            
            if(question == 0){

                printLogo();
                questRead(13);
                questRead(14);
                questRead(15);
                
                printf("Vas odgovor: ");
                scanf(" %c", &ans);

                if(ans == 'd' || ans == 'D'){
                    
                    system("cls");
                    printf("Tocan odgovor, osvojili ste 100 HRK");
                    sleep(1);
                    system("cls");
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste 0 HRK");
                    sleep(1);
                    system("cls");
                    scoreTable(s);
                }

            }

            else if(question == 1){

                printLogo();
                questRead(13 + 16);
                questRead(14 + 16);
                questRead(15 + 16);
                
                printf("Vas odgovor: ");
                scanf(" %c", &ans);

                if(ans == 'd' || ans == 'D'){
                    
                    system("cls");
                    printf("Tocan odgovor, osvojili ste %d HRK", money[question]);
                    sleep(1);
                    system("cls");
    
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste %d HRK", money[question - 1]);
                    sleep(1);
                    system("cls");
                    scoreTable(s);
                }
            }

            else if(question == 15){
                
                printLogo();
                questRead(13 + 16 * question);
                questRead(14 + 16 * question);
                questRead(15 + 16 * question);
                
                printf("Vas odgovor: ");
                scanf(" %c", &ans);

                if(ans == 'd' || ans == 'D'){
                    
                    system("cls");
                    printf("Tocan odgovor, osvojili ste %d HRK", money[question]);
                    sleep(1);
                    system("cls");
                    scoreTable(s);
    
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste %d HRK", money[question - 1]);
                    sleep(1);
                    system("cls");
                    scoreTable(s);
                }

            }

            else{

                printLogo();
                questRead(13 + 16 * question);
                questRead(14 + 16 * question);
                questRead(15 + 16 * question);
                
                printf("Vas odgovor: ");
                scanf(" %c", &ans);

                if(ans == 'd' || ans == 'D'){
                    
                    system("cls");
                    printf("Tocan odgovor, osvojili ste %d HRK", money[question]);
                    sleep(1);
                    system("cls");
    
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste %d HRK", money[question - 1]);
                    sleep(1);
                    system("cls");
                    scoreTable(s);
                }

            }

            

        }

        question++;
        s.scoreNumber++;

    }
}
//PITANJA


int randNumber(int r){

    srand((unsigned) time(NULL));

    r = (rand() % (4 - 1 + 1)) + 1;

    return r;
}



int questRead(int lineNumber){
   
   FILE *fp;
   fp= fopen("pitanja.txt", "r");
   int count = 1;
   
    if ( fp != NULL )
    {   
    char questLine[1024];
    while (fgets(questLine, sizeof questLine, fp) != NULL) 
        {   
            if (count == lineNumber)
            {   
                
            printf("%s\n", questLine);
            fclose(fp);
            return 0;

            }   
            else
            {   
                count++;
            }   
           
        }
   
    fclose(fp);
    
    
    return 0;
    }
}
