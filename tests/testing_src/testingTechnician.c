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

int run_test_suite_printTechnician(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    char buffer[512];
    int failures = 0;
    int test_count = 0;

    int idCode, interventions;
    char name[100];
    char specialization;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("Error: Could not open test files for printTechnician.\n");
        return -1;
    }

    printf("Starting Test Suite: printTechnician\n");
    printf("-------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), f_in)) {
        test_count++;

        if (sscanf(buffer, "%d;%[^;];%c;%d", &idCode, name, &specialization, &interventions) >= 4) {
            
            technician tech = createTechnician_TESTING(idCode, name, specialization, interventions);

            if (tech != NULL) {
                fflush(stdout);
                freopen("temp_output.txt", "w", stdout);

                printTechnician(tech);

                #ifdef _WIN32
                    freopen("CON", "w", stdout);
                #else
                    freopen("/dev/tty", "w", stdout);
                #endif

                FILE *f_res = fopen("temp_output.txt", "r");
                int match = 1;
                char res_line[256], orc_line[256];

                while (fgets(orc_line, sizeof(orc_line), f_orc)) {
                    if (test_count > 1 && strstr(orc_line, "--- Technician Details ---")) {
                        fseek(f_orc, -strlen(orc_line), SEEK_CUR);
                        break;
                    }
                    if (!fgets(res_line, sizeof(res_line), f_res) || strcmp(res_line, orc_line) != 0) {
                        match = 0;
                    }
                }
                fclose(f_res);

                if (match) {
                    printf("[PASS] Test %d: Technician output matches oracle.\n", test_count);
                } else {
                    printf("[FAIL] Test %d: Output mismatch.\n", test_count);
                    failures++;
                }

                deleteTechnician(tech);
            } else {
                printf("[ERROR] Failed to allocate memory in test %d\n", test_count);
                failures++;
            }
        }
    }

    fclose(f_in);
    fclose(f_orc);
    remove("temp_output.txt");

    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}

int run_test_suite_addIntervention(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    char buffer[256];
    int failures = 0;
    int test_count = 0;

    int idCode, interventions, oracle_val, actual_val;
    char name[100];
    char specialization;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("Error: Could not open test files for addIntervention.\n");
        return -1;
    }

    printf("Starting Test Suite: addIntervention\n");
    printf("-------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), f_in) && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;

        if (sscanf(buffer, "%d;%[^;];%c;%d", &idCode, name, &specialization, &interventions) >= 4) {

            technician tech = createTechnician_TESTING(idCode, name, specialization, interventions);

            if (tech != NULL) {
                addIntervention(tech);
                actual_val = getInterventionCount(tech);

                if (actual_val == oracle_val) {
                    printf("[PASS] Test %d: Intervention count incremented to %d.\n", test_count, actual_val);
                } else {
                    printf("[FAIL] Test %d: Expected %d, Got %d\n", test_count, oracle_val, actual_val);
                    failures++;
                }

                deleteTechnician(tech);
            } else {
                printf("[ERROR] Failed to allocate memory in test %d\n", test_count);
                failures++;
            }
        }
    }

    fclose(f_in);
    fclose(f_orc);

    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}

int run_test_suite_getIdCode(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    char buffer[256];
    int failures = 0;
    int test_count = 0;

    int idCode, interventions, oracle_val, actual_val;
    char name[100];
    char specialization;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("Error: Could not open test files for getIdCode.\n");
        return -1;
    }

    printf("Starting Test Suite: getIdCode\n");
    printf("-------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), f_in) && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;

        if (sscanf(buffer, "%d;%[^;];%c;%d", &idCode, name, &specialization, &interventions) >= 1) {

            technician tech = createTechnician_TESTING(idCode, name, specialization, interventions);

            if (tech != NULL) {
                actual_val = getIdCode(tech);

                if (actual_val == oracle_val) {
                    printf("[PASS] Test %d: ID Code %d processed correctly.\n", test_count, actual_val);
                } else {
                    printf("[FAIL] Test %d: Expected %d, Got %d\n", test_count, oracle_val, actual_val);
                    failures++;
                }

                deleteTechnician(tech);
            } else {
                printf("[ERROR] Failed to allocate memory in test %d\n", test_count);
                failures++;
            }
        }
    }

    fclose(f_in);
    fclose(f_orc);

    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}