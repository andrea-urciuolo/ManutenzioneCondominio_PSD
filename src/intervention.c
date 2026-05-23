#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/intervention.h"
#include "../include/utils.h"


// It acts as an associative entity linking a specific request to an assigned technician.
struct c_intervention {
    request r;                  // Pointer to the underlying maintenance request
    technician t;               // Pointer to the assigned technician
    char dateAppointment[11];   // Scheduled date string (Format: YYYY/MM/DD)
    char timeAppointment[6];    // Scheduled time string (Format: HH:MM)
};

intervention newIntervention(request r, technician t) {
    // Checks the preconditions to ensure we are not linking null pointers
    if (r == NULL || t == NULL) return NULL;

    // Dynamically allocate memory for the new intervention envelope
    intervention inter = malloc(sizeof(struct c_intervention));
    if (inter == NULL) return NULL;

    // Flag variable to track user input validation state
    int error = 0;

    // Link the request and technician pointers to this intervention
    inter->r = r;
    inter->t = t;

    // Date input loop: ensures format correctness and valid calendar dates
    char dateAppointment[11];
    char checkRequestAppointment[11];
    int flagCheck;
    do {
        flagCheck = 0;
        if (!error) {
            printf("Inserire la data per l'intervento (YYYY/MM/DD): ");
        } else {
            printf("ERRORE! Formato non valido. Riprova (YYYY/MM/DD): ");
        }
        scanf("%10s", dateAppointment);
        clearBuffer();
        strcpy(checkRequestAppointment, getSubmissionDate(r));
        if (StrToInt(checkRequestAppointment) > StrToInt(dateAppointment)) {
            printf("Data inserita non valida\n");
            flagCheck = 1;
        }
        error = 1;
    } while (flagCheck == 1 || !checkDateValidity(dateAppointment));

    // Safely copy the validated date into the struct
    strncpy(inter->dateAppointment, dateAppointment, sizeof(inter->dateAppointment) - 1);
    inter->dateAppointment[sizeof(inter->dateAppointment) - 1] = '\0';

    // Time input loop: ensures the user enters the time in the specified format
    error = 0;
    char timeAppointment[6];
    do {
        clearBuffer();
        if (!error) printf("Inserire l'orario per l'intervento (HH:MM): ");
        else printf("ERRORE! Formato non valido. Riprova (HH:MM): ");
        error = 1;
    } while (scanf("%5s", timeAppointment) != 1 || !checkTimeValidity(timeAppointment));

    // Safely copy the validated time string
    strncpy(inter->timeAppointment, timeAppointment, sizeof(inter->timeAppointment) - 1);
    inter->timeAppointment[sizeof(inter->timeAppointment) - 1] = '\0';

    return inter;
}

// Retrieves the request object linked to this intervention
request getRequestIntervention(intervention inter) {
    if (inter == NULL) return NULL; // Precondition check
    return inter->r;
}

// Retrieves the technician object linked to this intervention
technician getTechnicianIntervention(intervention inter) {
    if (inter == NULL) return NULL; // Precondition check
    return inter->t;
}

// Retrieves the scheduled appointment date
char* getDateAppointment(intervention inter) {
    if (inter == NULL) return NULL; // Precondition check
    return inter->dateAppointment;
}

// Retrieves the scheduled appointment time
char* getTimeAppointment(intervention inter) {
    if (inter == NULL) return NULL; // Precondition check
    return inter->timeAppointment;
}

// Prints the complete details of the intervention, cascading down to print the linked request and technician
void printIntervention(intervention inter) {
    if (inter == NULL) return; // Precondition check
    
    printf("--- INTERVENTO ---\n");
    
    printf("-- RICHIESTA --\n");
    printRequest(getRequestIntervention(inter)); // Calls the print module of the request
    
    printf("-- TECNICO --\n");
    printTechnician(getTechnicianIntervention(inter)); // Calls the print module of the technician
    
    printf("-- DATA --\n");
    printf("%s\n", getDateAppointment(inter)); // Added \n for proper formatting
    
    printf("-- ORARIO --\n");
    printf("%s\n", getTimeAppointment(inter)); // Added \n for proper formatting
}

// Safely frees the memory allocated strictly for the intervention wrapper
void deallocateIntervention(intervention inter) {
    if (inter == NULL) return; // Precondition check
    
    // CRITICAL: We only deallocate the intervention container itself.
    // The underlying request and technician objects must remain intact in memory 
    // as they belong to the main data structures (PQueue and List).
    free(inter);
}

// Test builder function that initializes an intervention directly bypassing standard input
intervention buildIntervention(request r, technician t, const char* date, const char* time) {
    if (r == NULL || t == NULL) return NULL;

    intervention inter = malloc(sizeof(struct c_intervention));
    if (inter == NULL) return NULL;

    inter->r = r;
    inter->t = t;

    strncpy(inter->dateAppointment, date, sizeof(inter->dateAppointment) - 1);
    inter->dateAppointment[sizeof(inter->dateAppointment) - 1] = '\0';

    strncpy(inter->timeAppointment, time, sizeof(inter->timeAppointment) - 1);
    inter->timeAppointment[sizeof(inter->timeAppointment) - 1] = '\0';

    return inter;
}