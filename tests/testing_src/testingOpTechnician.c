#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/opTechnician.h"
#include "../../include/technician.h"
#include "../../include/Btree.h"

static technician create_dummy_tech_with_workload(int id, char spec, int workload) {
    technician t = buildTechnician(id, "Tech_Test", spec);
    for (int i = 0; i < workload; i++) {
        addIntervention(t);
    }
    return t;
}

int run_test_suite_printAllTechnicians(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, oracle_val, actual_val;
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per printAllTechnicians.\n");
        return -1;
    }

    printf("Starting Test Suite: printAllTechnicians\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d", &scenario) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        Btree T = newBtree();
        
        // Array per salvare i puntatori e pulire la memoria a fine ciclo
        technician arr[50];
        for(int k=0; k<50; k++) arr[k] = NULL; 

        actual_val = 0;

        if (scenario == -1) {
            printAllTechnicians(NULL);
            actual_val = 1;
        } else {
            char specializations[] = {'a', 'b', 'c', 'd', 'e', 'f'};
            for (int i = 0; i < scenario; i++) {
                char spec = specializations[i % 6]; // Stessa logica usata nel tuo main.c!
                arr[i] = create_dummy_tech_with_workload(i, spec, i);
                T = insertTechnician(T, arr[i]);
            }
            printAllTechnicians(T);
            actual_val = 1;
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d | Esecuzione completata in sicurezza\n", test_count, scenario);
        } else {
            printf("[FAIL] Test %d: Scenario %d | Atteso %d, Ottenuto %d\n", test_count, scenario, oracle_val, actual_val);
            failures++;
        }

        clearTreeNodes(T);
        for (int i = 0; i < scenario; i++) {
            if (arr[i] != NULL) {
                deleteTechnician(arr[i]);
            }
        }
    }

    fclose(f_in);
    fclose(f_orc);
    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}

int run_test_suite_printTechniciansBySpecialization(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, oracle_val, actual_val;
    char target_spec;
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per printTechniciansBySpecialization.\n");
        return -1;
    }

    printf("Starting Test Suite: printTechniciansBySpecialization\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d %c", &scenario, &target_spec) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        Btree T = newBtree();
        technician arr[50];
        for(int k=0; k<50; k++) arr[k] = NULL;
        actual_val = 0;

        if (scenario == -1) {
            printTechniciansBySpecialization(NULL, target_spec);
            actual_val = 1;
        } else {
            for (int i = 0; i < scenario; i++) {
                char spec;
                if (i % 2 == 0) spec = 'a';
                else spec = 'b';
                
                arr[i] = create_dummy_tech_with_workload(i, spec, i);
                T = insertTechnician(T, arr[i]);
            }
            printTechniciansBySpecialization(T, target_spec);
            actual_val = 1;
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d (Spec '%c') | Esecuzione completata\n", test_count, scenario, target_spec);
        } else {
            printf("[FAIL] Test %d: Scenario %d (Spec '%c') | Atteso %d, Ottenuto %d\n", test_count, scenario, target_spec, oracle_val, actual_val);
            failures++;
        }

        clearTreeNodes(T);
        for (int i = 0; i < scenario; i++) {
            if (arr[i] != NULL) {
                deleteTechnician(arr[i]);
            }
        }
    }

    fclose(f_in);
    fclose(f_orc);
    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}

int run_test_suite_printTechniciansByWorkload(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, oracle_val, actual_val;
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per printTechniciansByWorkload.\n");
        return -1;
    }

    printf("Starting Test Suite: printTechniciansByWorkload\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d", &scenario) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        Btree T = newBtree();
        technician arr[50];
        for(int k=0; k<50; k++) arr[k] = NULL;
        actual_val = 0;

        if (scenario == -1) {
            printTechniciansByWorkload(NULL);
            actual_val = 1;
        } else {
            char specializations[] = {'a', 'b', 'c', 'd', 'e', 'f'};
            for (int i = 0; i < scenario; i++) {
                int workload = (i % 3) * 5; 
                char spec = specializations[i % 6];
                
                arr[i] = create_dummy_tech_with_workload(i, spec, workload);
                T = insertTechnician(T, arr[i]);
            }
            printTechniciansByWorkload(T);
            actual_val = 1;
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d | Esecuzione completata in sicurezza\n", test_count, scenario);
        } else {
            printf("[FAIL] Test %d: Scenario %d | Atteso %d, Ottenuto %d\n", test_count, scenario, oracle_val, actual_val);
            failures++;
        }

        clearTreeNodes(T);
        for (int i = 0; i < scenario; i++) {
            if (arr[i] != NULL) {
                deleteTechnician(arr[i]);
            }
        }
    }

    fclose(f_in);
    fclose(f_orc);
    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}

int run_test_suite_printMostActiveTechnician(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, oracle_val, actual_val;
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per printMostActiveTechnician.\n");
        return -1;
    }

    printf("Starting Test Suite: printMostActiveTechnician\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d", &scenario) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        Btree T = newBtree();
        technician arr[50];
        for(int k=0; k<50; k++) arr[k] = NULL;
        actual_val = 0;

        if (scenario == -1) {
            printMostActiveTechnician(NULL);
            actual_val = 1;
        } else {
            for (int i = 0; i < scenario; i++) {
                int workload = i * 2;
                arr[i] = create_dummy_tech_with_workload(i, 'c', workload);
                T = insertTechnician(T, arr[i]);
            }
            printMostActiveTechnician(T);
            actual_val = 1;
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d | Esecuzione completata in sicurezza\n", test_count, scenario);
        } else {
            printf("[FAIL] Test %d: Scenario %d | Atteso %d, Ottenuto %d\n", test_count, scenario, oracle_val, actual_val);
            failures++;
        }

        clearTreeNodes(T);
        for (int i = 0; i < scenario; i++) {
            if (arr[i] != NULL) {
                deleteTechnician(arr[i]);
            }
        }
    }

    fclose(f_in);
    fclose(f_orc);
    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}

int run_test_suite_findTechnicianByType(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, oracle_val, actual_val;
    char target_spec;
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per findTechnicianByType.\n");
        return -1;
    }

    printf("Starting Test Suite: findTechnicianByType\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d %c", &scenario, &target_spec) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        Btree T = newBtree();
        technician arr[50];
        for(int k=0; k<50; k++) arr[k] = NULL;
        technician res = NULL;

        if (scenario == -1) {
            res = findTechnicianByType(NULL, target_spec);
        } else {
            for (int i = 0; i < scenario; i++) {
                char spec;
                if (i == 0) spec = 'e';
                else spec = 'f';

                arr[i] = create_dummy_tech_with_workload(i, spec, 1);
                T = insertTechnician(T, arr[i]);
            }
            res = findTechnicianByType(T, target_spec);
        }

        actual_val = (res != NULL) ? 1 : 0;

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d (Spec '%c') | Trovato: %s\n", test_count, scenario, target_spec, actual_val ? "SI" : "NO");
        } else {
            printf("[FAIL] Test %d: Scenario %d (Spec '%c') | Atteso %d, Ottenuto %d\n", test_count, scenario, target_spec, oracle_val, actual_val);
            failures++;
        }

        clearTreeNodes(T);
        for (int i = 0; i < scenario; i++) {
            if (arr[i] != NULL) {
                deleteTechnician(arr[i]);
            }
        }
    }

    fclose(f_in);
    fclose(f_orc);
    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}