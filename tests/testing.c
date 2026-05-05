#include <stdio.h>
#include <string.h>
#include "../tests/testing.h"
#include "../include/request.h"

/**
 * Executes a test suite by comparing input data against an oracle file.
 * Returns the number of failed tests.
 */
int run_test_suite_getIdRequest(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    char buffer[256];
    int failures = 0;
    int test_count = 0;

    /* Test Data Variables (Adjust based on your chosen track) */
    int id, urgency, oracle_val, actual_val;
    char description[100];

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("Error: Could not open test files.\n");
        return -1;
    }

    printf("Starting Test Suite...\n");
    printf("-------------------------------------------\n");

    /* Read input and oracle line by line */
    while (fgets(buffer, sizeof(buffer), f_in) && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;

        /* Parsing Input: ID;Description;Urgency (assicurati che il formato nel file sia questo) */
        if (sscanf(buffer, "%d;%[^;];%d", &id, description, &urgency) == 3) {

            /* 1. Crea l'oggetto usando la tua funzione TESTING */
            /* Nota: aggiungi valori fittizi per gli altri campi che non stiamo testando ora */
            request r = createRequest_TESTING(id, 'a', urgency, 0, "2026/01/01", description);

            if (r != NULL) {
                /* 2. CHIAMA LA FUNZIONE REALE */
                actual_val = getIdRequest(r);

                /* 3. Confronta */
                if (actual_val == oracle_val) {
                    printf("[PASS] Test %d: ID %d processed correctly.\n", test_count, id);
                } else {
                    printf("[FAIL] Test %d: ID %d. Expected %d, Got %d\n",
                            test_count, id, oracle_val, actual_val);
                    failures++;
                }

                /* 4. Dealloca sempre per evitare memory leak (importante per il voto!) */
                deallocateRequest(r);
            } else {
                printf("[ERROR] Failed to allocate memory for request in test %d\n", test_count);
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

int run_test_suite_getType(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    char buffer[256];
    int failures = 0;
    int test_count = 0;

    /* Variabili per i dati di test */
    int id, urgency;
    char oracle_val, actual_val;
    char description[100];
    char type; /* Carattere letto dall'input per creare la richiesta */

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("Error: Could not open test files for getType.\n");
        return -1;
    }

    printf("Starting Test Suite: getType\n");
    printf("-------------------------------------------\n");

    /* Legge input e oracolo (usa %c con uno spazio davanti per ignorare eventuali invii/spazi) */
    while (fgets(buffer, sizeof(buffer), f_in) && fscanf(f_orc, " %c", &oracle_val) != EOF) {
        test_count++;

        /* Parsing Input: ID;Type;Urgency;Description */
        /* Nota: Ho aggiunto il campo type nel parsing per testarlo correttamente */
        if (sscanf(buffer, "%d;%c;%d;%[^;\n]", &id, &type, &urgency, description) >= 3) {

            /* 1. Crea l'oggetto usando il tipo letto dal file */
            request r = createRequest_TESTING(id, type, urgency, 0, "2026/01/01", description);

            if (r != NULL) {
                /* 2. CHIAMA LA FUNZIONE REALE */
                actual_val = getType(r);

                /* 3. Confronta i caratteri */
                if (actual_val == oracle_val) {
                    printf("[PASS] Test %d: Type '%c' processed correctly.\n", test_count, type);
                } else {
                    printf("[FAIL] Test %d: Type '%c'. Expected '%c', Got '%c'\n",
                            test_count, type, oracle_val, actual_val);
                    failures++;
                }

                /* 4. Cleanup */
                deallocateRequest(r);
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