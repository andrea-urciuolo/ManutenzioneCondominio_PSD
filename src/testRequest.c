/*

#include <stdio.h>
#include "../include/request.h"
#include "testFramework.h"

void input_createRequest(request* r);

int output_requestId(request r);
char output_requestType(request r);

void runRequestTests(){
    printf("REQUEST TEST \n");

    request r;
    input_createRequest(&r);

    if(r == NULL){
        printf("FAIL request allocation\n");
        return;
    }

    int size;
    testCase* suite = createRequestTestSuite(&size);

    compareInt(getTest(suite, 0), output_requestId(r));

    compareChar(getTest(suite, 1), output_requestType(r));

    freeTestSuite(suite);
    deallocateRequest(r);

    printf("\n");
}

*/