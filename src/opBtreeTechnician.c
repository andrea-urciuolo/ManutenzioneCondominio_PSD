#include <stdio.h>
#include <stdlib.h>
#include "../include/technician.h"
#include "../include/Btree.h"

void printAllTechnicians(Btree T) {
    if (emptyBtree(T)) return;

    printAllTechnicians(figlioSX(T));

    technician t = getItem(getRoot(T));
    printTechnician(t);

    printAllTechnicians(figlioDX(T));
}

void printTechniciansBySpecialization(Btree T, char spec) {
    if (emptyBtree(T)) return;
    if (spec < 'a' || spec > 'f') return;

    technician rootTech = getItem(getRoot(T));
    char rootSpec = getSpecialization(rootTech);

    if (spec < rootSpec) {
        printTechniciansBySpecialization(figlioSX(T), spec);
    } else if (spec > rootSpec) {
        printTechniciansBySpecialization(figlioDX(T), spec);
    } else {
        printTechniciansBySpecialization(figlioSX(T), spec);
        printTechnician(rootTech);
    }
}

// Helper function for printTechniciansByWorkload
void fillArray(Btree T, technician* array, int* index) {
    if (emptyBtree(T)) return;

    fillArray(figlioSX(T), array, index);
    array[(*index)++] = getItem(getRoot(T));
    fillArray(figlioDX(T), array, index);
}


void printTechniciansByWorkload(Btree T) {
    int total = sizeBtree(T);
    if (total == 0) {
        printf("Nessun tecnico trovato.\n");
        return;
    }

    technician* array = (technician*)malloc(total * sizeof(technician));
    if (array == NULL) return;

    int index = 0;
    fillArray(T, array, &index);

    // Bubblesort for ordering the array
    technician temp;
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (getInterventionCount(array[j]) < getInterventionCount(array[j+1])) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    printf("\n--- Classifica Tecnici per Carico di Lavoro (Interventi) ---\n");
    for (int i = 0; i < total; i++) {
        printf("%d. ", i + 1);
        printTechnician(array[i]);
    }

    free(array);
}

// Helper function for printMostActiveTechnician
void findMaxInterventions(Btree T, technician* maxTech) {
    if (emptyBtree(T)) return;

    technician currentTech = getItem(getRoot(T));

    if (*maxTech == NULL || getInterventionCount(currentTech) > getInterventionCount(*maxTech)) {
        *maxTech = currentTech;
    }

    findMaxInterventions(figlioSX(T), maxTech);
    findMaxInterventions(figlioDX(T), maxTech);
}

void printMostActiveTechnician(Btree T) {
    if (emptyBtree(T)) {
        printf("\nNessun tecnico presente nel sistema.\n");
        return;
    }

    technician mostActive = NULL;

    findMaxInterventions(T, &mostActive);

    if (mostActive != NULL) {
        printf("\n=== TECNICO PIU' ATTIVO DEL SISTEMA ===\n");
        printTechnician(mostActive);
        printf("========================================\n");
    }
}