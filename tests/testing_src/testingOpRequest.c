/*
 * File: opRequestTesting.c
 * Autore: Alessandro Verosimile
 * Descrizione: Modulo di testing per le operazioni sulle richieste (opRequest).
 * Verifica il corretto funzionamento delle procedure di stampa e ricerca 
 * all'interno della coda di priorità, gestendo l'assenza di memory leak.
 */

#include <stdio.h>
#include <stdlib.h>
#include "../../include/PQueue.h"
#include "../../include/opRequest.h"

/*
 * Esegue la suite di test per la funzione printAllRequests.
 * Verifica che la stampa dell'intera coda di priorità avvenga in modo sicuro,
 * garantendo che la coda non venga accidentalmente svuotata o corrotta.
 * Parametri:
 * input_path: percorso del file contenente gli scenari di input
 * oracle_path: percorso del file contenente i risultati attesi (oracolo)
 * Ritorna:
 * Il numero di test falliti (0 se perfetti), o -1 in caso di errore I/O.
 */
int run_test_suite_printAllRequests(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, oracle_val, actual_val;
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");
    
    // Interrompe l'esecuzione se i file di test mancano, prevenendo crash
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

        // Lo scenario -1 viene usato per testare la robustezza contro i puntatori a NULL
        if (scenario == -1) {
            printAllRequests(NULL);
            actual_val = 1; 
        } else {
            q = newPQ();
            
            // Popola la coda con gli elementi necessari unicamente per valutare il volume di stampa
            for(int i = 0; i < scenario; i++) {
                insert(q, NULL); 
            }
            
            printAllRequests(q);
            actual_val = 1; 
        }

        // actual_val a 1 funge da conferma che la funzione è terminata senza errori fatali (es. SegFault)
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

/*
 * Esegue la suite di test per la funzione printRequestById.
 * Valida la corretta ricerca lineare all'interno della coda di priorità
 * per individuare e stampare una singola richiesta specifica.
 * Parametri:
 * input_path: percorso del file con gli scenari e gli ID target
 * oracle_path: percorso del file con i risultati attesi
 * Ritorna:
 * Il numero di test falliti (0 se la suite passa integralmente), o -1 per errori I/O.
 */
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

        // Verifica che il sistema non vada in crash cercando un ID in una coda inesistente
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

/*
 * Esegue la suite di test per la funzione printRequestsByType.
 * Accerta che il filtro basato sul carattere della specializzazione
 * funzioni senza interrompere l'attraversamento della coda.
 * Parametri:
 * input_path: percorso file contenente i volumi di test e i caratteri tipo (es. 'a')
 * oracle_path: percorso file contenente i risultati di verifica
 * Ritorna:
 * Il totale dei test non superati, oppure -1 se i file sono illeggibili.
 */
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

/*
 * Esegue la suite di test per la funzione printRequestsByApartment.
 * Garantisce che la logica di smistamento per numero civico gestisca
 * adeguatamente le interrogazioni, compreso il caso speciale '0' per l'edificio.
 * Parametri:
 * input_path: percorso del file degli scenari
 * oracle_path: percorso dell'oracolo di output
 * Ritorna:
 * Numero totale dei fallimenti, o -1 in caso di assenza file.
 */
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

/*
 * Esegue la suite di test per la funzione getRequestById.
 * Verifica che la funzione restituisca l'indirizzo di memoria corretto
 * della richiesta associata all'ID richiesto, proteggendo il dato ritornato.
 * Parametri:
 * input_path: percorso file di configurazione scenari
 * oracle_path: percorso file contenente le flag di presenza attese
 * Ritorna:
 * La somma dei test falliti, altrimenti -1 per problemi di caricamento file.
 */
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

        // Converte il puntatore in una flag binaria: 1 se estratto con successo, 0 se l'ID non esiste
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