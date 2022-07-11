#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <unistd.h>

typedef struct firstQuestionPossiblitiy{
    
    char questionOne[250];
    char ansAOne[50];
    char ansBOne[50];
    char ansCOne[50];
    char ansDOne[50];

}FIRST;

typedef struct secondQuestionPossiblitiy{
    
    char questionOne[250];
    char ansAOne[50];
    char ansBOne[50];
    char ansCOne[50];
    char ansDOne[50];

}SECOND;

typedef struct thirdQuestionPossiblitiy{
    
    char questionOne[250];
    char ansAOne[50];
    char ansBOne[50];
    char ansCOne[50];
    char ansDOne[50];

}THIRD;



char openFirstQuestionsFile(){
    
    FILE *fp = NULL;
    const char *fileName = "1.txt";

    fp = fopen(fileName, "r");

    

}