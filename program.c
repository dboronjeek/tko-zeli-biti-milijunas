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

void bubbleSort();
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
                    bubbleSort();
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
void bubbleSort();

void scoreTable(SCORE s){
    
    char crta = '-';
    char mn[3] = "HRK";
    int zero = 0;

    int money[] = {
        100, 200, 300, 500, 1000,
        2000, 4000, 8000, 16000, 32000,
        64000, 1250000, 250000, 500000, 1000000
    };

    printf("Unesi svoj nadimak (ne vise od 10 znakova): ");
    scanf("%s", s.nickname);


    FILE* fp = NULL;
    fp = fopen("score.txt", "a");

    if(s.scoreNumber == -1){
        fprintf(fp, "%s %d\n", s.nickname, zero);
    }

    else{
        fprintf(fp, "%s %d\n", s.nickname, money[s.scoreNumber]);
    }
    
    fclose(fp);

    system("cls");
    menu(0);
}

void seeScoreTable(){
    
    char score[1024];
    FILE* fp = NULL;
    char ans[2];
    char da[] = {"da"};
    SCORE s;
    int money;

    printf("********************* 'SCORE' TABLICA *********************\n");
    fp = fopen("scoreSorted.txt", "r");

    while (fscanf(fp, "%s%d", s.nickname, &money) != EOF){
        
        printf("%s - %d HRK\n", s.nickname, money);
    }
    printf("***********************************************************");
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

int numberOfLines(){

    FILE *fp;
    fp= fopen("score.txt", "r");
    int count = 0;
   
    if ( fp != NULL ){   
        char questLine[1024];
        
        while (fgets(questLine, sizeof questLine, fp) != NULL){     
        
            count++;

        }
    }

    fclose(fp);
    
    return count;
}

void bubbleSort(){

    int size;
    int array[1024];
    char string[1024][11];
    FILE *fp = NULL;
    FILE *fc = NULL;

    size = numberOfLines();

    fp = fopen("score.txt", "r");

    int i, j;
    int fi = 0;
    int swap;
    char temp[1024];
    

    while (fscanf(fp, "%s %d", string[fi], &array[fi]) != EOF){
        
        //printf("%s - %d HRK\n", string[fi], array[fi]);
        fi++;
    }

    for(i = 0; i < (size - 1); i++){
        for(j = 0; j < size - i - 1; j++){
            if(array[j] < array[j + 1]){
                
                swap = array[j];
                array[j] = array[j + 1];
                array[j + 1] = swap;

                strcpy(temp, string[j]);
                strcpy(string[j], string[j + 1]);
                strcpy(string[j + 1], temp);
            }
        }
    }
    printf("\n");
    for(j = 0; j < size; j++){
        //printf("%s - %d HRK\n", string[j], array[j]);
    }

    fclose(fp);

    fc = fopen("scoreSorted.txt", "w");
    
    for(j = 0; j < size; j++){
        fprintf(fc, "%s %d\n", string[j], array[j]);
    }

    fclose(fc);
}


