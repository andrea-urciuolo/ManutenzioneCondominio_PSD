#include <stdio.h>
#include <stdlib.h>
#include "../include/PQueue.h"
#include "../include/opRequest.h"

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
            // Test su puntatore NULL
            printAllRequests(NULL);
            actual_val = 1; // Sopravvissuto al test senza crash
        } else {
            q = newPQ();
            
            // Popolamento della coda in base allo scenario
            for(int i = 1; i <= scenario; i++) {
            
                insert(q, (request)(size_t)i); 
            }
            
            // Esecuzione della funzione sotto test
            printAllRequests(q);
            
            // Se arriviamo qui, il travaso avanti e indietro tra q e tempQ 
            // è avvenuto senza causare errori fatali di memoria.
            actual_val = 1; 
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d | Esecuzione completata in sicurezza\n", test_count, scenario);
        } else {
            // Ramo teorico in caso di asincronie nell'oracolo
            printf("[FAIL] Test %d: Scenario %d | Atteso %d, Ottenuto %d\n", test_count, scenario, oracle_val, actual_val);
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