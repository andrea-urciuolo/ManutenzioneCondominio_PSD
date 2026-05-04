#include <stdio.h>
#include <stdlib.h>
#include "../include/opTechnician.h"
#include "../include/technician.h"

/* Prints all the technicians currently in the list */
void printAllTechnicians(list l) {
    if (emptyList(l)) {
        printf("The list of technicians is empty.\n");
        return;
    }

    printf("\n=== Full List of Technicians ===\n");
    list current = l;
    while (!emptyList(current)) {
        /* Cast the void* item back to technician */
        technician tech = (technician)getFirst(current);
        printTechnician(tech);
        current = tailList(current);
    }
}

/* Searches for a technician by their ID code and prints their details */
void printTechnicianById(list l, int idCode) {
    if (idCode <= 0) {
        printf("The id is not valid.\n");
        return;
    }

    if (emptyList(l)) {
        printf("The list of technicians is empty.\n");
        return;
    }

    list current = l;
    int found = 0;
    
    while (!emptyList(current) && !found) {
        technician tech = (technician)getFirst(current);
        if (getIdCode(tech) == idCode) {
            printf("\n=== Technician Found ===\n");
            printTechnician(tech);
            found = 1;
        }
        current = tailList(current);
    }

    if (!found) {
        printf("Error: Technician with ID %d not found.\n", idCode);
    }
}

/* Prints all technicians that match a specific specialization character */
void printTechniciansBySpecialization(list l, char spec) {
    if (spec < 'a' || spec > 'f') {
        printf("This specialization does not exist.\n");
        return;
    }

    if (emptyList(l)) {
        printf("The list of technicians is empty.\n");
        return;
    }

    printf("\n=== Technicians with Specialization '%c' ===\n", spec);
    list current = l;
    int found = 0;
    
    while (!emptyList(current)) {
        technician tech = (technician)getFirst(current);
        if (getSpecialization(tech) == spec) {
            printTechnician(tech);
            found = 1;
        }
        current = tailList(current);
    }

    if (!found) {
        printf("No technicians found with specialization '%c'.\n", spec);
    }
}

/* Finds and prints the technician with the highest number of interventions */
void printMostActiveTechnician(list l) {
    if (emptyList(l)) {
        printf("No technicians available to evaluate.\n");
        return;
    }

    list current = l;
    technician mostActive = (technician)getFirst(current);
    int maxInterventions = getInterventionCount(mostActive);

    current = tailList(current);
    while (!emptyList(current)) {
        technician tech = (technician)getFirst(current);
        if (getInterventionCount(tech) > maxInterventions) {
            mostActive = tech;
            maxInterventions = getInterventionCount(tech);
        }
        current = tailList(current);
    }

    printf("\n=== Most Active Technician ===\n");
    printTechnician(mostActive);
}

/* Prints all technicians sorted descending by their number of interventions (workload) */
void printTechniciansByWorkload(list l) {
    int size = sizeList(l);
    if (size == 0) {
        printf("The list of technicians is empty.\n");
        return;
    }

    /* Dynamically allocate an array to sort the technicians */
    technician* techArray = (technician*)malloc(size * sizeof(technician));
    if (techArray == NULL) {
        printf("Error: Memory allocation failed during sorting.\n");
        return;
    }

    /* Copy pointers from the list to the array */
    list current = l;
    for (int i = 0; i < size; i++) {
        techArray[i] = (technician)getFirst(current);
        current = tailList(current);
    }

    /* Bubble sort algorithm (Descending order by intervention count) */
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (getInterventionCount(techArray[j]) < getInterventionCount(techArray[j + 1])) {
                technician temp = techArray[j];
                techArray[j] = techArray[j + 1];
                techArray[j + 1] = temp;
            }
        }
    }

    printf("\n=== Technicians Ordered by Workload ===\n");
    for (int i = 0; i < size; i++) {
        printTechnician(techArray[i]);
    }

    /* Free the temporary array */
    free(techArray);
}