#include <stdio.h>
#include <stdlib.h>
#include "../../include/PQueue.h"
#include "../../include/opRequest.h"


int run_test_suite_printAllRequests(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, oracle_val, actual_val;
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");
    
    
    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per printAllRequests.\n");
        return -1;
    }

    printf("Starting Test Suite: printAllRequests\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d", &scenario) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        PQueue q = NULL;
        actual_val = 0;
        if (scenario == -1) {
            printAllRequests(NULL);
            actual_val = 1; 
        } else {
            q = newPQ();
            
            for(int i = 0; i < scenario; i++) {
                insert(q, NULL); 
            }
            
            printAllRequests(q);
            actual_val = 1; 
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d | Esecuzione completata in sicurezza\n", test_count, scenario);
        } else {
            printf("[FAIL] Test %d: Scenario %d | Atteso %d, Ottenuto %d\n", test_count, scenario, oracle_val, actual_val);
            failures++;
        }

        if (q != NULL) {
            deallocatePQ(q);
        }
    }

    fclose(f_in); 
    fclose(f_orc);
    
    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}

int run_test_suite_printRequestById(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, target_id, oracle_val, actual_val;
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");
    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per printRequestById.\n");
        return -1;
    }

    printf("Starting Test Suite: printRequestById\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d %d", &scenario, &target_id) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        PQueue q = NULL;
        actual_val = 0;

        if (scenario == -1) {
            printRequestById(NULL, target_id);
            actual_val = 1; 
        } else {
            q = newPQ();
            
            for(int i = 0; i < scenario; i++) {
                insert(q, NULL);
            }
            
            printRequestById(q, target_id);
            actual_val = 1; 
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d (Cerca ID %d) | Esecuzione completata\n", test_count, scenario, target_id);
        } else {
            printf("[FAIL] Test %d: Scenario %d (Cerca ID %d) | Atteso %d, Ottenuto %d\n", test_count, scenario, target_id, oracle_val, actual_val);
            failures++;
        }

        if (q != NULL) {
            deallocatePQ(q);
        }
    }

    fclose(f_in); 
    fclose(f_orc);
    
    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}

int run_test_suite_printRequestsByType(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, oracle_val, actual_val;
    char target_type;
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");
    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per printRequestsByType.\n");
        return -1;
    }

    printf("Starting Test Suite: printRequestsByType\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d %c", &scenario, &target_type) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        PQueue q = NULL;
        actual_val = 0;

        if (scenario == -1) {
            printRequestsByType(NULL, target_type);
            actual_val = 1; 
        } else {
            q = newPQ();
            
            for(int i = 0; i < scenario; i++) {
                insert(q, NULL);
            }
            
            printRequestsByType(q, target_type);
            actual_val = 1; 
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d (Cerca tipo '%c') | Esecuzione completata\n", test_count, scenario, target_type);
        } else {
            printf("[FAIL] Test %d: Scenario %d (Cerca tipo '%c') | Atteso %d, Ottenuto %d\n", test_count, scenario, target_type, oracle_val, actual_val);
            failures++;
        }

        if (q != NULL) {
            deallocatePQ(q);
        }
    }

    fclose(f_in); 
    fclose(f_orc);
    
    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}


int run_test_suite_printRequestsByApartment(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, target_apt, oracle_val, actual_val;
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");
    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per printRequestsByApartment.\n");
        return -1;
    }

    printf("Starting Test Suite: printRequestsByApartment\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d %d", &scenario, &target_apt) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        PQueue q = NULL;
        actual_val = 0;

        if (scenario == -1) {
            printRequestsByApartment(NULL, target_apt);
            actual_val = 1; 
        } else {
            q = newPQ();
            
            for(int i = 0; i < scenario; i++) {
                insert(q, NULL);
            }
            
            printRequestsByApartment(q, target_apt);
            actual_val = 1; 
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d (Cerca Apt %d) | Esecuzione completata\n", test_count, scenario, target_apt);
        } else {
            printf("[FAIL] Test %d: Scenario %d (Cerca Apt %d) | Atteso %d, Ottenuto %d\n", test_count, scenario, target_apt, oracle_val, actual_val);
            failures++;
        }

        if (q != NULL) {
            deallocatePQ(q);
        }
    }

    fclose(f_in); 
    fclose(f_orc);
    
    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}

int run_test_suite_getRequestById(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, target_id, oracle_val, actual_val;
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");
    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per getRequestById.\n");
        return -1;
    }

    printf("Starting Test Suite: getRequestById\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d %d", &scenario, &target_id) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        PQueue q = NULL;
        request res = NULL;

        if (scenario == -1) {
            res = getRequestById(NULL, target_id);
        } else {
            q = newPQ();
            
            for(int i = 0; i < scenario; i++) {
                insert(q, NULL);
            }
            
            res = getRequestById(q, target_id);
        }
        actual_val = (res != NULL) ? 1 : 0;

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d (Cerca ID %d) | Trovato: %s\n", test_count, scenario, target_id, actual_val ? "SI" : "NO");
        } else {
            printf("[FAIL] Test %d: Scenario %d (Cerca ID %d) | Atteso %d, Ottenuto %d\n", test_count, scenario, target_id, oracle_val, actual_val);
            failures++;
        }

        if (q != NULL) {
            deallocatePQ(q);
        }
    }

    fclose(f_in); 
    fclose(f_orc);
    
    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}