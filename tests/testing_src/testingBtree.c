#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/Btree.h"
#include "../../include/technician.h"
#include "../testing_include/testingTechnician.h"


static technician create_dummy_technician(char specialization) {

    return createTechnician_TESTING(1, "Mario", "Rossi", specialization, 2026);
}

int run_test_suite_newBtree(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, oracle_val, actual_val;
    int failures = 0;
    int test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per newBtree.\n");
        return -1;
    }

    printf("Starting Test Suite: newBtree\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d", &scenario) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        
        Btree T = newBtree();

        if (T == NULL && emptyBtree(T) == 1) {
            actual_val = 1;
        } else {
            actual_val = 0;
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Inizializzazione Btree eseguita con successo\n", test_count);
        } else {
            printf("[FAIL] Test %d: Atteso %d, Ottenuto %d\n", test_count, oracle_val, actual_val);
            failures++;
        }

        if (T != NULL) {
            clearTreeNodes(T);
        }
    }

    fclose(f_in);
    fclose(f_orc);

    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}

int run_test_suite_emptyBtree(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, oracle_val, actual_val;
    int failures = 0;
    int test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per emptyBtree.\n");
        return -1;
    }

    printf("Starting Test Suite: emptyBtree\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d", &scenario) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        Btree T = newBtree();
        technician t1 = NULL;

        if (scenario == -1) {

            actual_val = emptyBtree(NULL);
        } else if (scenario == 0) {
            actual_val = emptyBtree(T);
        } else {
            t1 = create_dummy_technician('B');
            T = insertTechnician(T, t1);
            actual_val = emptyBtree(T);
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d | emptyBtree -> %d\n", test_count, scenario, actual_val);
        } else {
            printf("[FAIL] Test %d: Scenario %d | Atteso %d, Ottenuto %d\n", test_count, scenario, oracle_val, actual_val);
            failures++;
        }

        if (T != NULL) {
            clearTreeNodes(T);
        }
        if (t1 != NULL) {
            deallocateTechnician(t1);
        }
    }

    fclose(f_in);
    fclose(f_orc);

    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}

int run_test_suite_insertTechnician(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    char buffer[256];
    int oracle_val, actual_val;
    int failures = 0;
    int test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per insertTechnician.\n");
        return -1;
    }

    printf("Starting Test Suite: insertTechnician\n");
    printf("-------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), f_in) && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        buffer[strcspn(buffer, "\r\n")] = 0;

        Btree T = newBtree();

        technician allocated_techs[20];
        int tech_idx = 0;

        char* token = strtok(buffer, ";");
        while (token != NULL && tech_idx < 20) {
            char spec = token[0];
            if (spec != '\0') {
                technician t = create_dummy_technician(spec);
                allocated_techs[tech_idx++] = t;
                T = insertTechnician(T, t);
            }
            token = strtok(NULL, ";");
        }

        actual_val = sizeBtree(T);

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Inseriti correttamente %d nodi nell'albero.\n", test_count, actual_val);
        } else {
            printf("[FAIL] Test %d: Attesi %d nodi, Rilevati %d\n", test_count, oracle_val, actual_val);
            failures++;
        }

        if (T != NULL) {
            clearTreeNodes(T);
        }

        for (int i = 0; i < tech_idx; i++) {
            deallocateTechnician(allocated_techs[i]);
        }
    }

    fclose(f_in);
    fclose(f_orc);

    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}

int run_test_suite_sizeBtree(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, oracle_val, actual_val;
    int failures = 0;
    int test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per sizeBtree.\n");
        return -1;
    }

    printf("Starting Test Suite: sizeBtree\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d", &scenario) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        Btree T = newBtree();
        technician allocated_techs[10];

        if (scenario == -1) {
            actual_val = sizeBtree(NULL);
        } else {
            for (int i = 0; i < scenario; i++) {
                technician t = create_dummy_technician('A' + i);
                allocated_techs[i] = t;
                T = insertTechnician(T, t);
            }
            actual_val = sizeBtree(T);
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d elementi | sizeBtree -> %d\n", test_count, scenario, actual_val);
        } else {
            printf("[FAIL] Test %d: Scenario %d elementi | Atteso %d, Ottenuto %d\n", test_count, scenario, oracle_val, actual_val);
            failures++;
        }

        if (T != NULL) {
            clearTreeNodes(T);
        }
        if (scenario > 0) {
            for (int i = 0; i < scenario; i++) {
                deallocateTechnician(allocated_techs[i]);
            }
        }
    }

    fclose(f_in);
    fclose(f_orc);

    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}

int run_test_suite_clearTreeNodes(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, oracle_val, actual_val;
    int failures = 0;
    int test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per clearTreeNodes.\n");
        return -1;
    }

    printf("Starting Test Suite: clearTreeNodes\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d", &scenario) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        Btree T = newBtree();
        technician allocated_techs[5];

        if (scenario == -1) {
            clearTreeNodes(NULL);
            actual_val = 1;
        } else {
            for (int i = 0; i < scenario; i++) {
                technician t = create_dummy_technician('M');
                allocated_techs[i] = t;
                T = insertTechnician(T, t);
            }
            clearTreeNodes(T);
            actual_val = 1;
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d | clearTreeNodes completata in sicurezza\n", test_count, scenario);
        } else {
            printf("[FAIL] Test %d: Scenario %d | Errore inatteso\n", test_count, scenario);
            failures++;
        }

        if (scenario > 0) {
            for (int i = 0; i < scenario; i++) {
                deallocateTechnician(allocated_techs[i]);
            }
        }
    }

    fclose(f_in);
    fclose(f_orc);

    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}