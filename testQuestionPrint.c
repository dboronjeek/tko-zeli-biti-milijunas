#include <stdio.h>
#include <stdlib.h>

int main(){

    char score[1024];
    FILE* fp = NULL;
    char ans[2];
    char da[] = {"da"};

    fp = fopen("pitanja.txt", "r");

    while (fgets(score, 1024, fp) != NULL){
        
        printf("%s", score);
    }
    fclose(fp);

}