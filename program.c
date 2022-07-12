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
        menu(ans);
    }

    else exit(0);
}
char QFF2();

//PRVO PITANJE
char openFirstQuestionsFile(){
    
    SCORE s;
    s.scoreNumber = -1;
    int r;
    system("cls");
    sleep(1);
        
    r = randNumber(r);
    char ans;
                
      
    if(r == 1){
        printLogo();
        questRead(1);
        questRead(2);
        questRead(3);
            
        printf("Vas odgovor: ");
        scanf(" %c", &ans);

        if(ans == 'a' || ans == 'A'){
            system("cls");
            printf("Tocan odgovor, osvojili ste 100 HRK");
        }

        else{
            system("cls");
            printf("Krivi odgovor, osvojili ste 0 HRK");
            sleep(1);
            system("cls");
            scoreTable(s);
        }
    }
            
    else if(r == 2){
        printLogo();
        questRead(5);
        questRead(6);
        questRead(7);
            
        printf("Vas odgovor: ");
        scanf(" %c", &ans);
                
        if(ans == 'b' || ans == 'B'){
            system("cls");
            printf("Tocan odgovor, osvojili ste 100 HRK");
            char QFF2();

        }

        else{
            system("cls");
            printf("Krivi odgovor, osvojili ste 0 HRK");
            sleep(1);
            system("cls");
            scoreTable(s);
        }
    }


      
    else if(r == 3){
        printLogo();
        questRead(9);
        questRead(10);
        questRead(11);
            
        printf("Vas odgovor: ");
        scanf(" %c", &ans);

        if(ans == 'd' || ans == 'D'){
            system("cls");
            printf("Tocan odgovor, osvojili ste 100 HRK");
            char QFF2();
        }
            
        else{
            system("cls");
            printf("Krivi odgovor, osvojili ste 0 HRK");
            sleep(2);
            system("cls");
            scoreTable(s);
            }
    }
}
//PRVO PITANJE 

//DRUGO PITANJE
char QFF2(){
    
    SCORE s;
    s.scoreNumber = -1;
    int r;
    //int scoreNumber = -1;
    system("cls");
    sleep(1);
        
    r = randNumber(r);
    char ans;
                
      
    if(r == 1){
        printLogo();
        questRead(1);
        questRead(2);
        questRead(3);
            
        printf("Vas odgovor: ");
        scanf(" %c", &ans);

        if(ans == 'a' || ans == 'A'){
            system("cls");
            printf("Tocan odgovor, osvojili ste 100 HRK");
        }

        else{
            system("cls");
            printf("Krivi odgovor, osvojili ste 0 HRK");
            sleep(2);
            system("cls");
            scoreTable(s);
        }
    }
            
    else if(r == 2){
        printLogo();
        questRead(5);
        questRead(6);
        questRead(7);
            
        printf("Vas odgovor: ");
        scanf(" %c", &ans);
                
        if(ans == 'b' || ans == 'B'){
            system("cls");
            printf("Tocan odgovor, osvojili ste 100 HRK");
            char QFF2();

        }

        else{
            system("cls");
            printf("Krivi odgovor, osvojili ste 0 HRK");
            sleep(1);
            system("cls");
            scoreTable(s);
        }
    }


      
    else if(r == 3){
        printLogo();
        questRead(9);
        questRead(10);
        questRead(11);
            
        printf("Vas odgovor: ");
        scanf(" %c", &ans);

        if(ans == 'd' || ans == 'D'){
            system("cls");
            printf("Tocan odgovor, osvojili ste 100 HRK");
            char QFF2();
        }
            
        else{
            system("cls");
            printf("Krivi odgovor, osvojili ste 0 HRK");
            sleep(1);
            system("cls");
            scoreTable(s);
            }
    }
}
//DRUGO PITANJE
    

        

    


int randNumber(int r){

    srand((unsigned) time(NULL));

    r = (rand() % (3 - 1 + 1)) + 1;

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
