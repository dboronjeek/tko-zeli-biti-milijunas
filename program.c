#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <unistd.h>
#include <string.h>

typedef struct scoreTable{

    char nickname[11];
    int scoreNumber;
    int questionNumber;

}SCORE;

typedef struct firstQuestionPossiblitiy{
    
    char questionOne[250];
    char ansAOne[50];
    char ansBOne[50];
    char ansCOne[50];
    char ansDOne[50];

}FIRST;

typedef struct secondQuestionPossiblitiy{
    
    char questionTwo[250];
    char ansATwo[50];
    char ansBTwo[50];
    char ansCTwo[50];
    char ansDTwo[50];

}SECOND;

typedef struct thirdQuestionPossiblitiy{
    
    char questionThree[250];
    char ansAThree[50];
    char ansBThree[50];
    char ansCThree[50];
    char ansDThree[50];

}THIRD;


int score(){

    int money[] = {

        100, 200, 300, 500, 1000,
        2000, 4000, 8000, 16000, 32000,
        64000, 1250000, 250000, 500000, 1000000
    };
}

char openQuestionsFile(){

    SCORE st;
    FILE *fp = NULL;
    st.questionNumber = 1;
    st.scoreNumber = -1;

    printf("Unesi nadimak (max 10 znakova): ");
    gets(st.nickname);
    gets(st.nickname);
    printf("\n");

    if(st.questionNumber == 1) fp = fopen("1.txt", "r");

    else if(st.questionNumber == 2) fp = fopen("2.txt", "r");

    else if(st.questionNumber == 3) fp = fopen("3.txt", "r");

    else if(st.questionNumber == 4) fp = fopen("4.txt", "r");

    else if(st.questionNumber == 5) fp = fopen("5.txt", "r");

    else if(st.questionNumber == 6) fp = fopen("6.txt", "r");

    else if(st.questionNumber == 7) fp = fopen("7.txt", "r");

    else if(st.questionNumber == 8) fp = fopen("8.txt", "r");

    else if(st.questionNumber == 9) fp = fopen("9.txt", "r");

    else if(st.questionNumber == 10) fp = fopen("10.txt", "r");

    else if(st.questionNumber == 11) fp = fopen("11.txt", "r");

    else if(st.questionNumber == 12) fp = fopen("12.txt", "r");

    else if(st.questionNumber == 13) fp = fopen("13.txt", "r");

    else if(st.questionNumber == 14) fp = fopen("14.txt", "r");

    else if(st.questionNumber == 15) fp = fopen("15.txt", "r");

    else printf("Error");

    printf("%s\n", st.nickname);
    printf("test");
    
    fclose(fp);
}


