#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <unistd.h>

#include "menu.c"
#include "loadingScreen.c"
#include "program.c"

int main(){

    int choice;

    char c;
    scanf("%c", &c);
    system("cls");

    loadingScreen();
    menu(choice);
    
    return 0;
}