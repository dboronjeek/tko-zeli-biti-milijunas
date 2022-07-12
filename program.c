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

char QFF2(int scoreNumber);

//PRVO PITANJE
char openFirstQuestionsFile(){

    int r;
    int scoreNumber = 1;
    system("cls");
    sleep(1);
    flushall
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
                    exit(0);
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
                    exit(0);
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
                    exit(0);
                }
            }
        }
//PRVO PITANJE 

//DRUGO PITANJE
char QFF2(){
    
    int scoreNumber = 2;
    int r;
    system("cls");
    sleep(1);
    flushall
        r = randNumber(r);
        char ans;
                
      
            if(r == 1){
                printLogo();
                questRead(13);
                questRead(14);
                questRead(15);
            
                printf("Vas odgovor: ");
                scanf(" %c", &ans);
                if(ans == 'a' || ans == 'A'){
                    system("cls");
                    printf("Tocan odgovor, osvojili ste 200 HRK");
                }
                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste 100 HRK");
                    exit(0);
                }
            }
            
            else if(r == 2){
                printLogo();
                questRead(17);
                questRead(18);
                questRead(19);
            
                printf("Vas odgovor: ");
                scanf(" %c", &ans);
                if(ans == 'c' || ans == 'C'){
                    system("cls");
                    printf("Tocan odgovor, osvojili ste 200 HRK");
                }
                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste 100 HRK");
                    exit(0);
                }
            }
      
            else if(r == 3){
                printLogo();
                questRead(21);
                questRead(22);
                questRead(23);
            
                printf("Vas odgovor: ");
                scanf(" %c", &ans);
                if(ans == 'b' || ans == 'B'){
                    system("cls");
                    printf("Tocan odgovor, osvojili ste 200 HRK");
                }
                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste 100 HRK");
                    exit(0);
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


int scoreTable(){


}