#include <stdio.h>
#include <string.h>
#include "../testing_include/testingTechnician.h"
#include "../../include/technician.h"

int run_test_suite_deleteTechnician(const char* input_path, const char* oracle_path) {
    FILE *f_in;
    char buffer[256];
    int failures = 0;
    int test_count = 0;

    int id;
    char specialization;
    
    f_in = fopen(input_path, "r");

    if (!f_in) {
        printf("Error: Could not open test file for deleteTechnician.\n");
        return -1;
    }

    printf("Starting Test Suite: deleteTechnician\n");
    printf("-------------------------------------------\n");

    test_count++;
    deleteTechnician(NULL);
    printf("[PASS] Test %d: NULL pointer handled correctly.\n", test_count);

    while (fgets(buffer, sizeof(buffer), f_in)) {
        test_count++;

        if (sscanf(buffer, "%d;%c", &id, &specialization) >= 2) {

            technician tech = createTechnician_TESTING(id, specialization);

            if (tech != NULL) {
  
                deleteTechnician(tech);
   
                printf("[PASS] Test %d: Technician ID %d deleted without crash.\n", test_count, id);
            } else {
                printf("[ERROR] Failed to allocate memory for technician in test %d\n", test_count);
                failures++;
            }
        }
    }

    fclose(f_in);

    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}

