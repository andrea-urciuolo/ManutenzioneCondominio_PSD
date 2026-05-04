#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/intervention.h"
#include "../include/utils.h"

struct c_intervention {
    request r;
    technician t;
    char dateAppointment[11];
    char timeAppointment[6];
};

intervention newIntervention(request r, technician t) {
    // Checks the preconditions
    if (r == NULL || t == NULL) return NULL;

    intervention inter = malloc(sizeof(struct c_intervention));
    if (inter == NULL) return NULL;

    // Flag variable to check user input
    int error = 0;

    inter->r = r;
    inter->t = t;

    char dateAppointment[11];
    do {
        clearBuffer();
        if (!error) printf("Inserire la data per l'intervento (YYYY/MM/DD): ");
        else printf("ERRORE! Formato non valido. Riprova (YYYY/MM/DD): ");
        error = 1;
    } while (scanf("%10s", dateAppointment) != 1);

    strncpy(inter->dateAppointment, dateAppointment, sizeof(inter->dateAppointment) - 1);
    inter->dateAppointment[sizeof(inter->dateAppointment) - 1] = '\0';

    error = 0;
    char timeAppointment[6];
    do {
        clearBuffer();
        if (!error) printf("Inserire l'orario per l'intervento (HH:MM): ");
        else printf("ERRORE! Formato non valido. Riprova (HH:MM): ");
        error = 1;
    } while (scanf("%5s", timeAppointment) != 1);

    strncpy(inter->timeAppointment, timeAppointment, sizeof(inter->timeAppointment) - 1);
    inter->timeAppointment[sizeof(inter->timeAppointment) - 1] = '\0';

    return inter;
}

request getRequestIntervention(intervention inter) {
    if (inter == NULL) return NULL; // Precondition
    return inter->r;
}

technician getTechnicianIntervention(intervention inter) {
    if (inter == NULL) return NULL; // Precondition
    return inter->t;
}

char* getDateAppointment(intervention inter) {
    if (inter == NULL) return NULL; // Precondition
    return inter->dateAppointment;
}

char* getTimeAppointment(intervention inter) {
    if (inter == NULL) return NULL; // Precondition
    return inter->timeAppointment;
}

void printIntervention(intervention inter) {
    if (inter == NULL) return; // Precondition
    printf("--- INTERVENTO ---\n");
    printf("-- RICHIESTA --\n");
    printRequest(getRequestIntervention(inter));
    printf("-- TECNICO --\n");
    printTechnician(getTechnicianIntervention(inter));
    printf("-- DATA --\n");
    printf("%s", getDateAppointment(inter));
    printf("-- ORARIO --\n");
    printf("%s", getTimeAppointment(inter));
}

void deallocateIntervention(intervention inter) {
    if (inter == NULL) return; // Precondition
    // Only deallocates the intervention, not the request and the technician
    free(inter);
}