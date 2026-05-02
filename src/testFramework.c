#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "testFramework.h"

typedef enum {
    INT_TEST,
    CHAR_TEST
} testType;

struct testCase {
    char name[50];
    testType type;
    int expectedInt;
    char expectedChar;
};

testCase* createRequestTestSuite(int* size){
    *size = 2;
    testCase* suite = malloc(sizeof(testCase) * (*size));

    strcpy(suite[0].name, "Request ID test");
    suite[0].type = INT_TEST;
    suite[0].expectedInt = 1;

    strcpy(suite[1].name, "Request TYPE test");
    suite[1].type = CHAR_TEST;
    suite[1].expectedChar = 'a';

    return suite;
}

testCase* createtechnicianTestSuite(int* size) {
    *size = 2;
    testCase* suite = malloc(sizeof(testCase) * (*size));

    strcpy(suite[0].name, "Availability test");
    suite[0].type = INT_TEST;
    suite[0].expectedInt = 1;

    strcpy(suite[1].name, "Interventions Test");
    suite[1].type = INT_TEST;
    suite[1].expectedInt = 1;

    return suite;
}

testCase getTest(testCase* suite, int index){
    return suite[index];
}

void compareInt (testCase t, int actual){
    if (t.expectedInt == actual){
        printf("PASS %s\n", t.name);
    }
    else {
        printf("FAIL %s -> Expected: %d, got: %d\n", t.name, t.expectedInt, actual);
    }
}

void compareChar(testCase t, char actual){
    if(t.expectedChar == actual){
        printf("PASS %s\n", t.name);
    }
    else{
        printf("FAIL %s -> Expected: %c, got: %c\n", t.name, t.expectedChar, actual);
    }
}

void freeTestSuite (testCase* suite){
    free(suite);
}