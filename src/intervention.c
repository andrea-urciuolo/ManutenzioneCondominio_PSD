#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intervention.h"
#include "request.h"
#include "tecnico.h"

struct c_intervention {
    request r;
    tecnico t;
    char dateAppointment[11];
    char timeAppointment[6];
    int estimatedTime;                       // Necessary time for the intervention in hours, MIN = 1, MAX = 4;
};

intervention newIntervention(request r, tecnico t, char dateAppointment[], char timeAppointment[], int estimatedTime) {
    // Allocate memory for the intervention adt
    intervention inter = malloc(sizeof(struct intervention));
    if (inter == NULL) return NULL;

    // Assign parameter values
    inter->r = r;
    inter->t = t;
    inter->estimatedTime = estimatedTime;

    //Copying dateAppointment and timeAppointment avoiding a Buffer Overflow
    strncpy(inter->dateAppointment, dateAppointment, sizeof(inter->dateAppointment) - 1);
    inter->dateAppointment[sizeof(inter->dateAppointment) - 1] = '\0';
    strncpy(inter->timeAppointment, timeAppointment, sizeof(inter->timeAppointment) - 1);
    inter->timeAppointment[sizeof(inter->timeAppointment) - 1] = '\0';

    return inter;
}

request getRequestIntervention(intervention inter) {
    return inter->r;
}

tecnico getTecnicoIntervention(intervention inter) {
    return inter->t;
}

char* getDateAppointment(intervention inter) {
    return inter->dateAppointment;
}

char* getTimeAppointment(intervention inter) {
    return inter->timeAppointment;
}

int getEstimatedTime(intervention inter) {
    return inter->estimatedTime;
}