#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "testFramework.h"


void compareInt(char* name, int expected, int actual){
    if (expected == actual){
        printf("Pass: %s\n", name);
    }
    else{
        printf("Fail: %s\n", name);
    }
}

void compareChar(char* name, char expected, char actual){
    if (expected == actual){
        printf("Pass: %s\n", name);
    }
    else{
        printf ("Fail: %s\n", name);
    }
}

void runRequestTestSuite (char* filename){
    FILE* f = fopen(filename, "r");

    if (f == NULL){
        printf("Error opening file\n");
        return;
    }

    char name[50];
    char type[10];

    while (fscanf(f, "%s %s", name, type) != EOF){
        if(strcmp(type, "INT") == 0){
            int expected;
            fscanf(f, "%d", &expected);

            int actual = 1;

            compareInt(name, expected, actual);
        }

        else if (strcmp(type, "CHAR") == 0){
            char expected;
            fscanf(f, " %c", &expected);

            char actual = 'a';

            compareChar(name, expected, actual);
        }
    }

    fclose(f);
}

void runTechnicianTestSuite (char* filename){
    FILE* f = fopen(filename, "r");

    if (f == NULL){
        printf("Error opening file\n");
        return;
    }

    char name[50];
    char type[10];

    while (fscanf(f, "%s %s", name, type) != EOF){
        if (strcmp(type, "INT") == 0){
            int expected; 
            fscanf(f, "%d", &expected);

            int actual = 1;
            compareInt(name, expected, actual);
        }
    }

    fclose(f);
}