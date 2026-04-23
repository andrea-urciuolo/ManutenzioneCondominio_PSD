#include <stdio.h>
#include <stdlib.h>
#include "report.h"
#include "request.h"

struct c_report{
    request* list;
    int size;
};

report newReport(request* requests, int size){
    if(requests == NULL || size <= 0){
        return NULL;
    }

    report r = malloc(sizeof(struct c_report));
    
    if (r == NULL){
        return NULL;
    }
     
     r->list = requests;
     r->size = size;

     return r;
}

void deleteReport (report r){
    if(r != NULL){
        free(r);
    }
}

int getOpenRequestsCount(report r){
    if (r == NULL){
        return 0;
    }

    int open = 0;

    for (int i = 0; i < r->size; i++){
        if (getIsCompleted(r->list[i]) == 0){
            open++;
        }
    }
    return open;
}

int getClosedRequestsCount(report r){
    if (r == NULL){
        return 0;
    }
    int closed = 0;
    for (int i = 0; i < r->size; i++){
        if (getIsCompleted(r->list[i]) == 1){
            closed++;
        }
    }
    return closed;
}

int getMostActiveTechnician(report r){
    if (r == NULL || r->size == 0){
        return -1;
    }

    int mostActiveId = -1;
    int maxCount = 0;

    for (int i = 0; i < r->size; i++){
        int currentId = getIdAssignedTechnician(r->list[i]);
        int count = 0;

    for (int j = 0; j < r->size; j++){
        if(getIdAssignedTechnician(r->list[j]) == currentId){
            count++;
        }
    }

    if(count > maxCount){
        maxCount = count;
        mostActiveId = currentId;
    }
   }

    return mostActiveId;
}

int getMostCriticalArea(report r){
    if(r == NULL || r->size == 0){
        return -1;
    }

    int mostCriticalArea = -1;
    int maxCount = 0;

    for(int i = 0; i <r->size; i++){
        int currentArea = getApartment(r->list[i]);
        int count = 0;

        for(int j = 0; j < r->size; j++){
            if(getApartment(r->list[j]) == currentArea){
                count++;
            }
        }
        if(count > maxCount){
            maxCount = count;
            mostCriticalArea = currentArea;
        }
    }
    return mostCriticalArea;
}

double getAverageCompletionTime(report r){
    int count = 0;
    double total = 0.0;

    for(int i = 0; i < r->size; i++){
        if (getIsCompleted(r->list[i]) == 1){
            total += 1;
            count++;
        }
    }

    if(count == 0){
        return 0.0;
    }

    return total / count;
}

void printRequestsByType(report r){
    if(r == NULL){
        return;
    }

    int typeA = 0;
    int typeE = 0;
    int typeI = 0;
    int typeO = 0;
    int typeU = 0;

    for(int i = 0; i < r->size; i++){
        char type = getType(r->list[i]);

        switch (type) {
            case 'a': typeA++; 
             break;
            case 'e': typeE++;
             break;
            case 'i': typeI++;
             break;
            case 'o': typeO++;
             break;
            case 'u': typeU++;
             break;
        }
    }

    printf("Requests by type:\n");
    printf("A: %d\n", typeA);
    printf("E: %d\n", typeE);
    printf("I: %d\n", typeI);
    printf("O: %d\n", typeO);
    printf("U: %d\n", typeU);
}