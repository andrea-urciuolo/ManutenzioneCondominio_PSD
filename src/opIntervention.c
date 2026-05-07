#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/opIntervention.h"
#include "../include/intervention.h"
#include "../include/request.h"
#include "../include/technician.h"

/* Prints all the interventions currently in the list */
void printAllInterventions(list l) {
    // Check if the list is empty to avoid unnecessary processing
    if (emptyList(l)) {
        printf("La lista degli interventi è vuota.\n");
        return;
    }

    printf("\n=== Lista Completa degli Interventi ===\n");
    list current = l;
    
    // Traverse the linked list until the end
    while (!emptyList(current)) {
        // Cast the generic item to an intervention type
        intervention inter = (intervention)getFirst(current);
        printIntervention(inter);
        // Move to the next node in the list
        current = tailList(current);
    }
}

/* Searches for an intervention by the ID of its associated request and prints it */
void printInterventionById(list l, int requestId) {
    if (emptyList(l)) {
        printf("La lista degli interventi è vuota.\n");
        return;
    }

    list current = l;
    int found = 0; // Flag to track if the target was found, allowing an early stop
    
    while (!emptyList(current) && !found) {
        intervention inter = (intervention)getFirst(current);
        
        // Extract the nested request object to access its ID
        request r = getRequestIntervention(inter);
        
        // Check if the extracted request ID matches the target ID
        if (getIdRequest(r) == requestId) {
            printf("\n=== Intervento Trovato ===\n");
            printIntervention(inter);
            found = 1; // Update flag to break the loop
        }
        current = tailList(current);
    }

    // If the loop finishes and nothing was found, notify the user
    if (!found) {
        printf("Errore: Nessun intervento trovato collegato all'ID Richiesta %d.\n", requestId);
    }
}

/* Prints all interventions scheduled for a specific date (format YYYY/MM/DD) */
void printInterventionsByDate(list l, const char* date) {
    if (emptyList(l)) {
        printf("La lista degli interventi è vuota.\n");
        return;
    }

    printf("\n=== Interventi Programmati per il %s ===\n", date);
    list current = l;
    int found = 0;
    
    // Linearly scan the list comparing the appointment date strings
    while (!emptyList(current)) {
        intervention inter = (intervention)getFirst(current);
        
        // Use strcmp to compare the strings; returns 0 if they are identical
        if (strcmp(getDateAppointment(inter), date) == 0) {
            printIntervention(inter);
            found = 1;
        }
        current = tailList(current);
    }

    if (!found) {
        printf("Nessun intervento programmato per il %s.\n", date);
    }
}

/* Prints all interventions assigned to a specific technician (by technician ID) */
void printInterventionsByTechnician(list l, int techId) {
    if (emptyList(l)) {
        printf("La lista degli interventi è vuota.\n");
        return;
    }

    printf("\n=== Interventi per il Tecnico con ID %d ===\n", techId);
    list current = l;
    int found = 0;
    
    while (!emptyList(current)) {
        intervention inter = (intervention)getFirst(current);
        
        // Extract the nested technician object to check their ID
        technician t = getTechnicianIntervention(inter);
        
        // Compare the technician's ID with the target ID
        if (getIdCode(t) == techId) {
            printIntervention(inter);
            found = 1;
        }
        current = tailList(current);
    }

    if (!found) {
        printf("Nessun intervento assegnato al Tecnico con ID %d.\n", techId);
    }
}

/* Prints all interventions based on the type of the problem (extracted from the request) */
void printInterventionsByType(list l, char problemType) {
    if (emptyList(l)) {
        printf("La lista degli interventi è vuota.\n");
        return;
    }

    printf("\n=== Interventi per la Tipologia di Problema '%c' ===\n", problemType);
    list current = l;
    int found = 0;
    
    while (!emptyList(current)) {
        intervention inter = (intervention)getFirst(current);
        
        // Extract the nested request to read its problem type character
        request r = getRequestIntervention(inter);
        
        if (getType(r) == problemType) {
            printIntervention(inter);
            found = 1;
        }
        current = tailList(current);
    }

    if (!found) {
        printf("Nessun intervento trovato per la tipologia di problema '%c'.\n", problemType);
    }
}

/* Checks if a specific technician is already busy on a given date and time. */
int checkConflict(list l, int techId, const char* date, const char* time) {
    if (emptyList(l)) {
        return 0; // List is empty, so no schedule conflict is possible by definition
    }

    list current = l;
    
    // Traverse the list to check for any overlapping appointments
    while (!emptyList(current)) {
        intervention inter = (intervention)getFirst(current);
        technician t = getTechnicianIntervention(inter);
        
        // First, check if the intervention is assigned to the target technician
        if (getIdCode(t) == techId) {
            // Then, check if both the date AND the time string match exactly
            if (strcmp(getDateAppointment(inter), date) == 0 && strcmp(getTimeAppointment(inter), time) == 0) {
                return 1; // Conflict found: the technician is already busy!
            }
        }
        current = tailList(current);
    }

    return 0; // The loop finished without finding any overlapping schedule; safe to proceed
}