#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/technician.h"
#include "../testing_include/testingTechnician.h"

int run_test_suite_deleteTechnician(const char* input_path) {
    FILE *f_in;
    char buffer[256];
    int failures = 0, test_count = 0;
    int id;
    char name[50], spec;

    f_in = fopen(input_path, "r");
    if (!f_in) {
        printf("Error: Could not open %s\n", input_path);
        return -1;
    }

    printf("Starting Test Suite: deleteTechnician\n");
    printf("-------------------------------------------\n");

    test_count++;
    deleteTechnician(NULL);
    printf("[PASS] Test %d: NULL pointer handled (no crash).\n", test_count);

    while (fgets(buffer, sizeof(buffer), f_in)) {
        test_count++;
        if (sscanf(buffer, "%d;%[^;];%c", &id, name, &spec) == 3) {
            technician tech = buildTechnician(id, name, spec);
            if (tech != NULL) {
                deleteTechnician(tech);
                printf("[PASS] Test %d: Technician %s deleted correctly.\n", test_count, name);
            } else {
                failures++;
            }
        }
    }
    fclose(f_in);
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}

int run_test_suite_getIdCode(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    char buffer[256];
    int id, oracle_val, actual_val;
    char name[50], spec;
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) return -1;

    printf("Starting Test Suite: getIdCode\n");
    printf("-------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), f_in) && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        if (sscanf(buffer, "%d;%[^;];%c", &id, name, &spec) == 3) {
            technician tech = buildTechnician(id, name, spec);
            actual_val = getIdCode(tech);

            if (actual_val == oracle_val) {
                printf("[PASS] Test %d: Got %d as expected.\n", test_count, actual_val);
            } else {
                printf("[FAIL] Test %d: Expected %d, Got %d\n", test_count, oracle_val, actual_val);
                failures++;
            }
            deleteTechnician(tech);
        }
    }
    fclose(f_in); fclose(f_orc);
    return failures;
}

int run_test_suite_addIntervention(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    char buffer[256];
    int id, oracle_val, actual_val;
    char name[50], spec;
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) return -1;

    printf("Starting Test Suite: addIntervention\n");
    printf("-------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), f_in) && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        if (sscanf(buffer, "%d;%[^;];%c", &id, name, &spec) == 3) {
            technician tech = buildTechnician(id, name, spec);

            addIntervention(tech);
            actual_val = getInterventionCount(tech);

            if (actual_val == oracle_val) {
                printf("[PASS] Test %d: Count incremented to %d.\n", test_count, actual_val);
            } else {
                printf("[FAIL] Test %d: Expected %d, Got %d\n", test_count, oracle_val, actual_val);
                failures++;
            }
            deleteTechnician(tech);
        }
    }
    fclose(f_in); fclose(f_orc);
    return failures;
}

int run_test_suite_getSpecialization(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    char buffer[256];
    int id;
    char name[50], spec, oracle_val, actual_val;
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) return -1;

    printf("Starting Test Suite: getSpecialization\n");
    printf("-------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), f_in) && fscanf(f_orc, " %c", &oracle_val) != EOF) {
        test_count++;
        if (sscanf(buffer, "%d;%[^;];%c", &id, name, &spec) == 3) {
            technician tech = buildTechnician(id, name, spec);
            actual_val = getSpecialization(tech);

            if (actual_val == oracle_val) {
                printf("[PASS] Test %d: Spec '%c' correct.\n", test_count, actual_val);
            } else {
                printf("[FAIL] Test %d: Expected '%c', Got '%c'\n", test_count, oracle_val, actual_val);
                failures++;
            }
            deleteTechnician(tech);
        }
    }
    fclose(f_in); fclose(f_orc);
    return failures;
}

int run_test_suite_getInterventionCount(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    char buffer[256];
    int id, oracle_val, actual_val;
    char name[50], spec;
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("[ERROR] Could not open test files for getInterventionCount.\n");
        return -1;
    }

    printf("Starting Test Suite: getInterventionCount\n");
    printf("-------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), f_in) && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;

        /* Parsing: ID;Nome;Specializzazione */
        if (sscanf(buffer, "%d;%[^;];%c", &id, name, &spec) == 3) {
            /* buildTechnician inizializza interventionCount a 0 */
            technician tech = buildTechnician(id, name, spec);

            if (tech != NULL) {
                actual_val = getInterventionCount(tech);

                if (actual_val == oracle_val) {
                    printf("[PASS] Test %d: Expected %d, Got %d\n", test_count, oracle_val, actual_val);
                } else {
                    printf("[FAIL] Test %d: Expected %d, Got %d\n", test_count, oracle_val, actual_val);
                    failures++;
                }
                deleteTechnician(tech);
            }
        }
    }

    fclose(f_in);
    fclose(f_orc);
    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n\n", test_count, failures);
    return failures;
}

int run_test_suite_printTechnician(const char* input_path) {
    FILE *f_in;
    char buffer[256];
    int id;
    char name[50], spec;
    int test_count = 0;

    f_in = fopen(input_path, "r");
    if (!f_in) {
        printf("[ERROR] Could not open input file for printTechnician.\n");
        return -1;
    }

    printf("Starting Test Suite: printTechnician (Visual Inspection)\n");
    printf("-------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), f_in)) {
        test_count++;
        if (sscanf(buffer, "%d;%[^;];%c", &id, name, &spec) == 3) {
            technician tech = buildTechnician(id, name, spec);

            if (tech != NULL) {
                printf("[TEST %d] Visualizing Technician: %s\n", test_count, name);

                /* Chiamata alla funzione reale */
                printTechnician(tech);

                printf("[PASS] Execution completed for Test %d\n\n", test_count);
                deleteTechnician(tech);
            }
        }
    }

    fclose(f_in);
    printf("-------------------------------------------\n");
    printf("Visual Suite Completed for %d technicians.\n\n", test_count);
    return 0;
}