#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/PQueue.h"
#include "../include/request.h"


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
            // Test Error Handling: Passaggio diretto di NULL
            actual_val = emptyPQ(NULL);
        } else {
            q = newPQ();
            
            // Dummy request per simulare i test di stato.
            // Nota: potresti dover inizializzare correttamente i campi di 'dummy' 
            // in base a come è definita la struct in request.h
            request dummy; 
            memset(&dummy, 0, sizeof(request)); 

            if (scenario > 0 && scenario < 999) {
                // Inseriamo 'scenario' numero di elementi
                for(int i = 0; i < scenario; i++) {
                    insert(q, dummy);
                }
            } else if (scenario == 999) {
                // Inseriamo e rimuoviamo per testare l'azzeramento di numel
                insert(q, dummy);
                deleteMax(q);
            }

            actual_val = emptyPQ(q);
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d | emptyPQ -> %d\n", test_count, scenario, actual_val);
        } else {
            printf("[FAIL] Test %d: Scenario %d | Atteso %d, Ottenuto %d\n",
                    test_count, scenario, oracle_val, actual_val);
            failures++;
        }

        // Cleanup rigoroso per evitare memory leak
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
            // Test su coda NULL
            res = getMax(NULL);
        } else {
            q = newPQ();
            
            // Creiamo un'area di memoria generica riempita di zeri per simulare una request.
            // Questo previene crash se 'getUrgency' chiamata dentro 'insert' dereferenzia il puntatore.
            char dummy_mem[256];
            memset(dummy_mem, 0, sizeof(dummy_mem));
            request dummy = (request)dummy_mem;

            if (scenario > 0 && scenario < 999) {
                // Inseriamo elementi
                for(int i = 0; i < scenario; i++) {
                    insert(q, dummy);
                }
            } else if (scenario == 999) {
                // Riempiamo e svuotiamo completamente
                insert(q, dummy);
                insert(q, dummy);
                deleteMax(q);
                deleteMax(q);
            }

            res = getMax(q);
        }

        // Mappiamo il risultato: 0 se res è NULL, 1 se res è valido
        actual_val = (res == NULL) ? 0 : 1;

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d | getMax -> %s\n", 
                   test_count, scenario, actual_val ? "VALID_PTR" : "NULL");
        } else {
            printf("[FAIL] Test %d: Scenario %d | Atteso %d, Ottenuto %d\n",
                    test_count, scenario, oracle_val, actual_val);
            failures++;
        }

        // Cleanup
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
            // Test su coda non allocata
            actual_val = deleteMax(NULL);
        } else {
            q = newPQ();
            
            // Dummy request memory block per superare i controlli in down() e up()
            char dummy_mem[256];
            memset(dummy_mem, 0, sizeof(dummy_mem));
            request dummy = (request)dummy_mem;

            // Prepariamo la coda per lo scenario
            for(int i = 0; i < scenario; i++) {
                insert(q, dummy);
            }

            // Eseguiamo la funzione da testare
            actual_val = deleteMax(q);
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d | deleteMax -> %d\n", test_count, scenario, actual_val);
        } else {
            printf("[FAIL] Test %d: Scenario %d | Atteso %d, Ottenuto %d\n",
                    test_count, scenario, oracle_val, actual_val);
            failures++;
        }

        // Cleanup rigoroso: deallocatePQ libererà anche l'array interno
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
        actual_val = 0; // Conterrà la somma dei ritorni (successi) di insert()
        PQueue q = NULL;

        // Prepariamo una request fittizia e sicura per la memoria
        char dummy_mem[256];
        memset(dummy_mem, 0, sizeof(dummy_mem));
        request dummy = (request)dummy_mem;

        if (scenario == -1) {
            // Test su puntatore nullo
            actual_val = insert(NULL, dummy);
        } else {
            q = newPQ();
            
            // Loop di inserimento: sommiamo i risultati di ogni singola chiamata
            for(int i = 0; i < scenario; i++) {
                actual_val += insert(q, dummy);
            }
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d inserimenti | Successi -> %d\n", 
                   test_count, scenario, actual_val);
        } else {
            printf("[FAIL] Test %d: Scenario %d inserimenti | Attesi %d, Ottenuti %d\n",
                    test_count, scenario, oracle_val, actual_val);
            failures++;
        }

        // Pulizia: verifica che la memoria scalata da realloc non vada in leak
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