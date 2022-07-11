#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <unistd.h>

char openFirstQuestionsFile(){

    FILE *fp = NULL;
    const char *fileName = "1.txt";

    fp = fopen(fileName, "r");

    if(fp == NULL) printf("Error, datoteka ne postoji!");
    //else printf("Datoteka postoji");

    int id;
    char questions[250] = {'\0'}, ansA[50] = {'\0'}, ansB[50] = {'\0'}, ansC[50] = {'\0'}, ansD[50] = {'\0'};

    fscanf(fp, "%d %s")
    fclose(fp);

}