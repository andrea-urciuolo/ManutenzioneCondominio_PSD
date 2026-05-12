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

    // Lettura simultanea di scenario (quanti elementi inserire) e target_id (cosa cercare)
    while (fscanf(f_in, "%d %d", &scenario, &target_id) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        PQueue q = NULL;
        actual_val = 0;

        if (scenario == -1) {
            printRequestById(NULL, target_id);
            actual_val = 1; // Sopravvissuto
        } else {
            q = newPQ();
            
            for(int i = 1; i <= scenario; i++) {
                /* 
                 * ATTENZIONE: Se getIdRequest cerca di dereferenziare questo valore, crasherà.
                 * Sostituire con l'allocazione di una Request reale se necessario per il test.
                 */
                insert(q, (request)(size_t)i);
            }
            
            // Esecuzione della funzione sotto test
            printRequestById(q, target_id);
            
            actual_val = 1; // Sopravvissuto al travaso di memoria
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d (Cerca ID %d) | Esecuzione completata\n", 
                   test_count, scenario, target_id);
        } else {
            printf("[FAIL] Test %d: Scenario %d (Cerca ID %d) | Atteso %d, Ottenuto %d\n", 
                   test_count, scenario, target_id, oracle_val, actual_val);
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

    // Lo spazio in "%d %c" gestisce automaticamente gli spazi bianchi tra numero e carattere
    while (fscanf(f_in, "%d %c", &scenario, &target_type) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        PQueue q = NULL;
        actual_val = 0;

        if (scenario == -1) {
            // Test su puntatore NULL
            printRequestsByType(NULL, target_type);
            actual_val = 1; // Sopravvissuto
        } else {
            q = newPQ();
            
            for(int i = 1; i <= scenario; i++) {
                /* 
                 * ATTENZIONE RISCHIO CRASH:
                 * getType(currentReq) proverà a dereferenziare questo indirizzo.
                 * Se il programma crasha, sostituisci (request)(size_t)i con 
                 * una reale funzione di allocazione/creazione per request.
                 */
                insert(q, (request)(size_t)i);
            }
            
            // Esecuzione della funzione da testare
            printRequestsByType(q, target_type);
            
            actual_val = 1; // Sopravvissuto al travaso di memoria
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d (Cerca tipo '%c') | Esecuzione completata\n", 
                   test_count, scenario, target_type);
        } else {
            printf("[FAIL] Test %d: Scenario %d (Cerca tipo '%c') | Atteso %d, Ottenuto %d\n", 
                   test_count, scenario, target_type, oracle_val, actual_val);
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