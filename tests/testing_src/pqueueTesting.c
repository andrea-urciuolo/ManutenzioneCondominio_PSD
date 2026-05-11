#include <stdio.h>
#include <stdlib.h>
#include "../include/PQueue.h"
#include "../include/request.h"

int run_test_suite_newPQ(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, oracle_val, actual_val;
    int failures = 0;
    int test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per newPQ.\n");
        return -1;
    }

    printf("Starting Test Suite: newPQ\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d", &scenario) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        
        PQueue q = newPQ();
        
        if (q != NULL && emptyPQ(q) == 1) {
            actual_val = 1; 
        } else {
            actual_val = 0; 
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Creazione PQueue eseguita con successo\n", test_count);
        } else {
            printf("[FAIL] Test %d: Atteso %d, Ottenuto %d\n", test_count, oracle_val, actual_val);
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

int run_test_suite_emptyPQ(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, oracle_val, actual_val;
    int failures = 0;
    int test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per emptyPQ.\n");
        return -1;
    }

    printf("Starting Test Suite: emptyPQ\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d", &scenario) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        PQueue q = NULL;

        if (scenario == -1) {
            actual_val = emptyPQ(NULL);
        } else {
            q = newPQ();
            
            if (scenario > 0 && scenario < 999) {
                for(int i = 0; i < scenario; i++) {
                    insert(q, (request)(size_t)i);
                }
            } else if (scenario == 999) {
                insert(q, (request)(size_t)1);
                deleteMax(q);
            }

            actual_val = emptyPQ(q);
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d | emptyPQ -> %d\n", test_count, scenario, actual_val);
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

int run_test_suite_getMax(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, oracle_val, actual_val;
    int failures = 0;
    int test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per getMax.\n");
        return -1;
    }

    printf("Starting Test Suite: getMax\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d", &scenario) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        PQueue q = NULL;
        request res = NULL;

        if (scenario == -1) {
            res = getMax(NULL);
        } else {
            q = newPQ();
            
            if (scenario > 0 && scenario < 999) {
                for(int i = 0; i < scenario; i++) {
                    insert(q, (request)(size_t)i);
                }
            } else if (scenario == 999) {
                insert(q, (request)(size_t)1);
                insert(q, (request)(size_t)2);
                deleteMax(q);
                deleteMax(q);
            }

            res = getMax(q);
        }

        actual_val = (res == NULL) ? 0 : 1;

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d | getMax -> %s\n", test_count, scenario, actual_val ? "VALID_PTR" : "NULL");
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

int run_test_suite_deleteMax(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, oracle_val, actual_val;
    int failures = 0;
    int test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per deleteMax.\n");
        return -1;
    }

    printf("Starting Test Suite: deleteMax\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d", &scenario) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        PQueue q = NULL;

        if (scenario == -1) {
            actual_val = deleteMax(NULL);
        } else {
            q = newPQ();
            
            for(int i = 0; i < scenario; i++) {
                insert(q, (request)(size_t)i);
            }

            actual_val = deleteMax(q);
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d | deleteMax -> %d\n", test_count, scenario, actual_val);
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

int run_test_suite_insert(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, oracle_val, actual_val;
    int failures = 0;
    int test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per insert.\n");
        return -1;
    }

    printf("Starting Test Suite: insert\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d", &scenario) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        actual_val = 0; 
        PQueue q = NULL;

        if (scenario == -1) {
            actual_val = insert(NULL, (request)(size_t)1);
        } else {
            q = newPQ();
            
            for(int i = 0; i < scenario; i++) {
                actual_val += insert(q, (request)(size_t)i);
            }
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d inserimenti | Successi -> %d\n", test_count, scenario, actual_val);
        } else {
            printf("[FAIL] Test %d: Scenario %d inserimenti | Attesi %d, Ottenuti %d\n", test_count, scenario, oracle_val, actual_val);
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

int run_test_suite_deallocatePQ(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, oracle_val, actual_val;
    int failures = 0;
    int test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per deallocatePQ.\n");
        return -1;
    }

    printf("Starting Test Suite: deallocatePQ\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d", &scenario) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        actual_val = 0; 
        PQueue q = NULL;

        if (scenario == -1) {
            deallocatePQ(NULL);
            actual_val = 1; 
        } else {
            q = newPQ();
            
            if (scenario > 0) {
                for(int i = 0; i < scenario; i++) {
                    insert(q, (request)(size_t)i);
                }
            }

            deallocatePQ(q);
            actual_val = 1; 
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d | deallocatePQ eseguita senza crash\n", test_count, scenario);
        } else {
            printf("[FAIL] Test %d: Scenario %d | Errore inaspettato\n", test_count, scenario);
            failures++;
        }
    }

    fclose(f_in);
    fclose(f_orc);

    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}