#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <unistd.h>
#include <string.h>

#include "menu.c"
#include "loadingScreen.c"

int main(){

    int choice;
    
    loadingScreen();
    menu(choice);
    
    return 0;
}