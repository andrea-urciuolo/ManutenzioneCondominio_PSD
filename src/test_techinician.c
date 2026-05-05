

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/test_techinician.h"
#include "../include/technician.h"

void runTechnicianTests(){
    printf ("\n--- Starting Technician Test ---\n");

    /*open the file in read mode
    FILE *file = fopen("test/data_technician.csv", "r");
    if (file == NULL){
        printf("[ERROR] Unable to open file tests/data_technician.csv.\n");
        printf("Make sure you run the program from the project's root folder.\n");
        return;
    }

    char line[100];
    int testPassed = 0;
    int testTotal = 0;

    /*Read the file line by line
    while (fgets(line, sizeof(line), file)){
        char expectedName[50];
        char expectedSpec;

        /* Removes the newline character at the end of the line
        line[strcspn(line, "\n")] = 0;

        /*Skip the blanck line
        if (strlen(line) == 0) continue;

        /* Split the line using a comma as a separator
        char* token = strtok(line, ",");
        if (token != NULL) {
            strncpy(expectedName, token, sizeof(expectedName) - 1);
            expectedName[sizeof(expectedName) - 1] = '\0';
            
            token = strtok(NULL, ",");
            if (token != NULL) {
                expectedSpec = token[0];
            }
        }
        /* EXECUTION: Create the technician with the extracted data using the constructor
        testTotal++;
        technician t = buildTechnician(expectedName, expectedSpec);

        /* ASSERTION: Check that getters return the correct data
        if (t != NULL && 
            strcmp(getName(t), expectedName) == 0 && 
            getSpecialization(t) == expectedSpec &&
            getInterventionCount(t) == 0) {
            
            printf("[PASS] Test %d: Tecnico creato correttamente -> %s (Spec: %c, ID: %d)\n", 
                   testTotal, getName(t), getSpecialization(t), getIdCode(t));
            testPassed++;
        } else {
            printf("[FAIL] Test %d: Creazione fallita per i dati -> %s, %c\n", testTotal, expectedName, expectedSpec);
        }
        
       /* Deallocate the technician at the end of the single test
        deleteTechnician(t);
    }

    fclose(file);
    printf("--- TECHNICIAN TESTS COMPLETED: %d/%d PASSED ---\n\n", testPassed, testTotal);
}

*/