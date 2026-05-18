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

    if (!f_in || !f_orc) {
        if (f_in) fclose(f_in);
        if (f_orc) fclose(f_orc);
        return -1;
    }

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
    fclose(f_in);
    fclose(f_orc);
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

int run_test_suite_getName(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    char buffer[512];
    int id;
    char spec;
    char name[100];         /* Buffer per leggere dal file di input */
    char oracle_name[100];  /* Buffer per leggere dall'oracolo */
    const char* actual_name;
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("[ERROR] Could not open test files for getName.\n");
        return -1;
    }

    printf("Starting Test Suite: getName\n");
    printf("-------------------------------------------\n");

    /* Legge input riga per riga e oracolo riga per riga */
    while (fgets(buffer, sizeof(buffer), f_in) && fgets(oracle_name, sizeof(oracle_name), f_orc)) {
        test_count++;

        /* Rimuove il newline (\n) dal nome dell'oracolo per il confronto */
        oracle_name[strcspn(oracle_name, "\r\n")] = '\0';

        /* Parsing input: ID;Nome;Specializzazione */
        if (sscanf(buffer, "%d;%[^;];%c", &id, name, &spec) == 3) {

            technician tech = buildTechnician(id, name, spec);

            if (tech != NULL) {
                actual_name = getName(tech);

                /* Confronto tra stringhe */
                if (actual_name != NULL && strcmp(actual_name, oracle_name) == 0) {
                    printf("[PASS] Test %d: Name matches oracle (\"%s\").\n", test_count, actual_name);
                } else {
                    printf("[FAIL] Test %d: Expected \"%s\", Got \"%s\"\n",
                            test_count, oracle_name, actual_name ? actual_name : "NULL");
                    failures++;
                }
                deleteTechnician(tech);
            } else {
                printf("[ERROR] Memory allocation failed in test %d\n", test_count);
                failures++;
            }
        }
    }

    /* Test di robustezza: Puntatore NULL */
    test_count++;
    if (getName(NULL) == NULL) {
        printf("[PASS] Test %d: NULL pointer handled correctly.\n", test_count);
    } else {
        printf("[FAIL] Test %d: NULL pointer did not return NULL.\n", test_count);
        failures++;
    }

    fclose(f_in);
    fclose(f_orc);
    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n\n", test_count, failures);
    return failures;
}