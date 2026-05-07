#include <stdio.h>
#include <stdlib.h>
#include "../include/opTechnician.h"
#include "../include/technician.h"

/* Prints all the technicians currently in the list */
void printAllTechnicians(list l) {
    // Check if the technician list is empty to avoid unnecessary operations
    if (emptyList(l)) { 
        printf("La lista dei tecnici è vuota.\n");
        return;
    }

    printf("\n=== Lista Completa dei Tecnici ===\n");
    list current = l;
    
    // Iterate through the linked list until the end is reached
    while (!emptyList(current)) {
        /* Cast the generic void* item back to a specific technician type */
        technician tech = (technician)getFirst(current);
        printTechnician(tech);
        current = tailList(current); // Move to the next node
    }
}

/* Searches for a technician by their ID code and prints their details */
void printTechnicianById(list l, int idCode) {
    // Input validation for the ID
    if (idCode <= 0) {
        printf("Errore: L'ID non è valido.\n");
        return;
    }

    if (emptyList(l)) { 
        printf("La lista dei tecnici è vuota.\n");
        return;
    }

    list current = l;
    
    // Linearly scan the list to find the matching ID
    while (!emptyList(current)) {
        technician tech = (technician)getFirst(current);
        if (getIdCode(tech) == idCode) {
            printf("\n=== Tecnico Trovato ===\n");
            printTechnician(tech);
            return; // Early exit since IDs are unique
        }
        current = tailList(current);
    }

    // If the loop finishes without returning, the ID does not exist
    printf("Errore: Tecnico con ID %d non trovato.\n", idCode);
}

/* Prints all technicians that match a specific specialization character */
void printTechniciansBySpecialization(list l, char spec) {
    // Input validation for the specialization character range
    if (spec < 'a' || spec > 'f') {
        printf("Errore: Questa specializzazione non esiste.\n");
        return;
    }

    if (emptyList(l)) {
        printf("La lista dei tecnici è vuota.\n");
        return;
    }

    printf("\n=== Tecnici con Specializzazione '%c' ===\n", spec);
    list currentNode = l;
    int matchCount = 0; // Counter to check if at least one technician was found
    
    // Iterate through the list and print only those matching the specialization
    while (!emptyList(currentNode)) {
        technician tech = (technician)getFirst(currentNode);
        if (getSpecialization(tech) == spec) {
            printTechnician(tech);
            matchCount++;
        }
        currentNode = tailList(currentNode);
    }

    if (matchCount == 0) {
        printf("Nessun tecnico trovato con la specializzazione '%c'.\n", spec);
    }
}

/* Finds and prints the technician with the highest number of interventions */
void printMostActiveTechnician(list l) {
    if (emptyList(l)) {
        printf("Nessun tecnico disponibile per la valutazione.\n");
        return;
    }

    list current = l;
    
    // Assume the first technician is the most active initially
    technician mostActive = (technician)getFirst(current);
    int maxInterventions = getInterventionCount(mostActive);

    current = tailList(current);
    
    // Traverse the rest of the list to find the actual maximum
    while (!emptyList(current)) {
        technician tech = (technician)getFirst(current);
        if (getInterventionCount(tech) > maxInterventions) {
            mostActive = tech;
            maxInterventions = getInterventionCount(tech);
        }
        current = tailList(current);
    }

    printf("\n=== Tecnico Più Attivo ===\n");
    printTechnician(mostActive);
}

/* Prints all technicians sorted descending by their number of interventions (workload) */
void printTechniciansByWorkload(list l) {
    int size = sizeList(l);
    if (size == 0) {
        printf("La lista dei tecnici è vuota.\n");
        return;
    }

    /* Dynamically allocate an array of pointers to sort the technicians without altering the original list structure */
    technician* techArray = (technician*)malloc(size * sizeof(technician));
    if (techArray == NULL) {
        printf("Errore: Allocazione di memoria fallita durante l'ordinamento.\n");
        return;
    }

    /* Copy pointers from the linked list into the array for easier index-based sorting */
    list current = l;
    for (int i = 0; i < size; i++) {
        techArray[i] = (technician)getFirst(current);
        current = tailList(current);
    }

    /* Bubble sort algorithm implementation (Descending order based on intervention count) */
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (getInterventionCount(techArray[j]) < getInterventionCount(techArray[j + 1])) {
                // Swap the pointers
                technician temp = techArray[j];
                techArray[j] = techArray[j + 1];
                techArray[j + 1] = temp;
            }
        }
    }

    printf("\n=== Tecnici Ordinati per Carico di Lavoro ===\n");
    for (int i = 0; i < size; i++) {
        printTechnician(techArray[i]);
    }

    /* Free the temporary array to prevent memory leaks */
    free(techArray);
}

/* Returns the technician corresponding to the specified ID. Returns NULL if not found. */
technician getTechnicianById(list l, int idCode) {
    // Validate parameters before starting the search
    if (idCode <= 0 || emptyList(l)) {
        return NULL;
    }

    list current = l;
    
    // Linearly search the list
    while (!emptyList(current)) {
        technician tech = (technician)getFirst(current);
        
        // If the ID matches, return the pointer to the technician immediately
        if (getIdCode(tech) == idCode) {
            return tech;
        }
        
        current = tailList(current);
    }
    
    // Return NULL if the list gets exhausted without finding the target ID
    return NULL;
}