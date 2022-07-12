#include <stdio.h>


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