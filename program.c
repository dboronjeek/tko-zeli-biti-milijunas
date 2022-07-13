#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>
#include <stdbool.h>


typedef struct Table{

    char nickname[11];
    int scoreNumber;

}SCORE;

void scoreTable(SCORE s);
char openQuestionsFile();
void seeScoreTable();

void loadingScreen(){

    Sleep(1000);
    system("cls");
    printf("\t\t*****************************\n");
    printf("\t\t******* Ucitavanje **********\n");
    printf("\t\t*****************************\n\n");
    printf("\t\t");

    for(int i = 0; i < 5; i++){

        printf(" [|]  ");
        Sleep(500);

    }

    system("cls");
    printf("\t********************************************\n");
    printf("\t*** Ucitavanje uspjesno, igra se pokrece ***\n");
    printf("\t********************************************");
    Sleep(2000);
    system("cls");
}

int menu(int choice){

    choice = 0;
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
                    openQuestionsFile();
                    
            break;

            case 2:
                    //Pogledaj score tablicu
                    system("cls");
                    seeScoreTable();
            break;

            case 3:
                    system("cls");
                    exit(0);
                
            break;

            default:
                    system("cls");
                    printf("**********************************\n");   
                    printf("**** Krivi odabir ponovi unos ****\n");
                    printf("**********************************\n");  
                    Sleep(2000);
                    system("cls");
                  
            break;
        }

        if(choice == 1 ||choice == 2 || choice == 3) break;

    }while(choice > 1 || choice < 3);
    return 0;
}

char printLogo(){
    
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
    printf("****************************************************************\n");

}

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
    Sleep(1000);

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
                    Sleep(1000);
                    system("cls");
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste 0 HRK");
                    Sleep(1000);
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
                    Sleep(1000);
                    system("cls");
    
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste %d HRK", money[question - 1]);
                    Sleep(1000);
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
                    Sleep(1000);
                    system("cls");
                    scoreTable(s);
    
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste %d HRK", money[question - 1]);
                    Sleep(1000);
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
                    Sleep(1000);
                    system("cls");
    
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste %d HRK", money[question - 1]);
                    Sleep(1000);
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
                    Sleep(1000);
                    system("cls");
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste 0 HRK");
                    Sleep(1000);
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
                    Sleep(1000);
                    system("cls");
    
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste %d HRK", money[question - 1]);
                    Sleep(1000);
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
                    Sleep(1000);
                    system("cls");
                    scoreTable(s);
    
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste %d HRK", money[question - 1]);
                    Sleep(1000);
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
                    Sleep(1000);
                    system("cls");
    
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste %d HRK", money[question - 1]);
                    Sleep(1000);
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
                    Sleep(1000);
                    system("cls");
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste 0 HRK");
                    Sleep(1000);
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
                    Sleep(1000);
                    system("cls");
    
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste %d HRK", money[question - 1]);
                    Sleep(1000);
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
                    Sleep(1000);
                    system("cls");
                    scoreTable(s);
    
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste %d HRK", money[question - 1]);
                    Sleep(1000);
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
                    Sleep(1000);
                    system("cls");
    
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste %d HRK", money[question - 1]);
                    Sleep(1000);
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
                    Sleep(1000);
                    system("cls");
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste 0 HRK");
                    Sleep(1000);
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
                    Sleep(1000);
                    system("cls");
    
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste %d HRK", money[question - 1]);
                    Sleep(1000);
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
                    Sleep(1000);
                    system("cls");
                    scoreTable(s);
    
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste %d HRK", money[question - 1]);
                    Sleep(1000);
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
                    Sleep(1000);
                    system("cls");
    
                }

                else{
                    system("cls");
                    printf("Krivi odgovor, osvojili ste %d HRK", money[question - 1]);
                    Sleep(1000);
                    system("cls");
                    scoreTable(s);
                }

            }

            

        }

        question++;
        s.scoreNumber++;
        Sleep(1000);
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



