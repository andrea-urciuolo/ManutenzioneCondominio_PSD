#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/opIntervention.h"
#include "../include/intervention.h"
#include "../include/request.h"
#include "../include/technician.h"

/* Prints all the interventions currently in the list */
void printAllInterventions(list l) {
    if (emptyList(l)) {
        printf("The list of interventions is empty.\n");
        return;
    }

    printf("\n=== Full List of Interventions ===\n");
    list current = l;
    while (!emptyList(current)) {
        intervention inter = (intervention)getFirst(current);
        printIntervention(inter);
        current = tailList(current);
    }
}

/* Searches for an intervention by the ID of its associated request and prints it */
void printInterventionById(list l, int requestId) {
    if (emptyList(l)) {
        printf("The list of interventions is empty.\n");
        return;
    }

    list current = l;
    int found = 0;
    
    while (!emptyList(current) && !found) {
        intervention inter = (intervention)getFirst(current);
        request r = getRequestIntervention(inter);
        
        if (getIdRequest(r) == requestId) {
            printf("\n=== Intervention Found ===\n");
            printIntervention(inter);
            found = 1;
        }
        current = tailList(current);
    }

    if (!found) {
        printf("Error: No intervention found linked to Request ID %d.\n", requestId);
    }
}

/* Prints all interventions scheduled for a specific date (format YYYY/MM/DD) */
void printInterventionsByDate(list l, const char* date) {
    if (emptyList(l)) {
        printf("The list of interventions is empty.\n");
        return;
    }

    printf("\n=== Interventions Scheduled on %s ===\n", date);
    list current = l;
    int found = 0;
    
    while (!emptyList(current)) {
        intervention inter = (intervention)getFirst(current);
        
        if (strcmp(getDateAppointment(inter), date) == 0) {
            printIntervention(inter);
            found = 1;
        }
        current = tailList(current);
    }

    if (!found) {
        printf("No interventions scheduled for %s.\n", date);
    }
}

/* Prints all interventions assigned to a specific technician (by technician ID) */
void printInterventionsByTechnician(list l, int techId) {
    if (emptyList(l)) {
        printf("The list of interventions is empty.\n");
        return;
    }

    printf("\n=== Interventions for Technician ID %d ===\n", techId);
    list current = l;
    int found = 0;
    
    while (!emptyList(current)) {
        intervention inter = (intervention)getFirst(current);
        technician t = getTechnicianIntervention(inter);
        
        if (getIdCode(t) == techId) {
            printIntervention(inter);
            found = 1;
        }
        current = tailList(current);
    }

    if (!found) {
        printf("No interventions assigned to Technician ID %d.\n", techId);
    }
}

/* Prints all interventions based on the type of the problem (extracted from the request) */
void printInterventionsByType(list l, char problemType) {
    if (emptyList(l)) {
        printf("The list of interventions is empty.\n");
        return;
    }

    printf("\n=== Interventions for Problem Type '%c' ===\n", problemType);
    list current = l;
    int found = 0;
    
    while (!emptyList(current)) {
        intervention inter = (intervention)getFirst(current);
        request r = getRequestIntervention(inter);
        
        if (getType(r) == problemType) {
            printIntervention(inter);
            found = 1;
        }
        current = tailList(current);
    }

    if (!found) {
        printf("No interventions found for problem type '%c'.\n", problemType);
    }
}

/* Checks if a specific technician is already busy on a given date and time. */
int checkConflict(list l, int techId, const char* date, const char* time) {
    if (emptyList(l)) {
        return 0; // List is empty, so no conflict is possible
    }

    list current = l;
    
    while (!emptyList(current)) {
        intervention inter = (intervention)getFirst(current);
        technician t = getTechnicianIntervention(inter);
        
        // Check if it's the same technician
        if (getIdCode(t) == techId) {
            // Check if date AND time match
            if (strcmp(getDateAppointment(inter), date) == 0 && strcmp(getTimeAppointment(inter), time) == 0) {
                return 1; // Conflict found!
            }
        }
        current = tailList(current);
    }

    return 0; // No conflict found
}