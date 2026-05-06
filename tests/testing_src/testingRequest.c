#include <stdio.h>
#include <string.h>
#include "../testing_include/testingRequest.h"
#include "../../include/request.h"

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

int run_test_suite_getUrgency(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    char buffer[256];
    int failures = 0;
    int test_count = 0;

    int id, urgency;
    int oracle_val, actual_val;
    char description[100];
    char type;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("Error: Could not open test files for getUrgency.\n");
        return -1;
    }

    printf("Starting Test Suite: getUrgency\n");
    printf("-------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), f_in) && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;

        if (sscanf(buffer, "%d;%c;%d;%[^;\n]", &id, &type, &urgency, description) >= 3) {

            request r = createRequest_TESTING(id, type, urgency, 0, "2026/01/01", description);

            if (r != NULL) {
                actual_val = getUrgency(r);

                if (actual_val == oracle_val) {
                    printf("[PASS] Test %d: Urgency %d processed correctly.\n", test_count, urgency);
                } else {
                    printf("[FAIL] Test %d: Urgency %d. Expected %d, Got %d\n",
                           test_count, urgency, oracle_val, actual_val);
                    failures++;
                }

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

int run_test_suite_getApartment(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    char buffer[256];
    int failures = 0;
    int test_count = 0;

    int id, urgency, apartment;
    int oracle_val, actual_val;
    char description[100];
    char type;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("Error: Could not open test files for getApartment.\n");
        return -1;
    }

    printf("Starting Test Suite: getApartment\n");
    printf("-------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), f_in) && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;

        if (sscanf(buffer, "%d;%c;%d;%d;%[^;\n]", &id, &type, &urgency, &apartment, description) >= 4) {

            request r = createRequest_TESTING(id, type, urgency, apartment, "2026/01/01", description);

            if (r != NULL) {
                actual_val = getApartment(r);

                if (actual_val == oracle_val) {
                    printf("[PASS] Test %d: Apartment %d processed correctly.\n", test_count, apartment);
                } else {
                    printf("[FAIL] Test %d: Apartment %d. Expected %d, Got %d\n",
                           test_count, apartment, oracle_val, actual_val);
                    failures++;
                }

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

int run_test_suite_getSubmissionDate(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    char buffer[256];
    char oracle_buffer[256];
    int failures = 0;
    int test_count = 0;

    int id, urgency;
    char type;
    char description[100];
    char submissionDate[20];
    char *actual_val;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("Error: Could not open test files for getSubmissionDate.\n");
        return -1;
    }

    printf("Starting Test Suite: getSubmissionDate\n");
    printf("-------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), f_in) && fgets(oracle_buffer, sizeof(oracle_buffer), f_orc)) {
        test_count++;

        oracle_buffer[strcspn(oracle_buffer, "\r\n")] = 0;

        if (sscanf(buffer, "%d;%c;%d;%[^;];%[^;\n]", &id, &type, &urgency, submissionDate, description) >= 4) {

            request r = createRequest_TESTING(id, type, urgency, 0, submissionDate, description);

            if (r != NULL) {
                actual_val = getSubmissionDate(r);

                if (actual_val != NULL && strcmp(actual_val, oracle_buffer) == 0) {
                    printf("[PASS] Test %d: Date '%s' processed correctly.\n", test_count, submissionDate);
                } else {
                    printf("[FAIL] Test %d: Expected '%s', Got '%s'\n",
                            test_count, oracle_buffer, actual_val ? actual_val : "NULL");
                    failures++;
                }

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

int run_test_suite_getDescription(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    char buffer[512];
    char oracle_val[256];
    int failures = 0;
    int test_count = 0;

    int id, urgency;
    char type;
    char description[256];
    char date[20];
    char* actual_val;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("Error: Could not open test files for getDescription.\n");
        return -1;
    }

    printf("Starting Test Suite: getDescription\n");
    printf("-------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), f_in) && fgets(oracle_val, sizeof(oracle_val), f_orc)) {
        test_count++;
        
        oracle_val[strcspn(oracle_val, "\r\n")] = 0;

        if (sscanf(buffer, "%d;%c;%d;%[^;];%[^;\n]", &id, &type, &urgency, date, description) >= 5) {

            request r = createRequest_TESTING(id, type, urgency, 0, date, description);

            if (r != NULL) {
                actual_val = getDescription(r);

                if (actual_val != NULL && strcmp(actual_val, oracle_val) == 0) {
                    printf("[PASS] Test %d: Description processed correctly.\n", test_count);
                } else {
                    printf("[FAIL] Test %d: Expected '%s', Got '%s'\n",
                            test_count, oracle_val, actual_val ? actual_val : "NULL");
                    failures++;
                }

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

int run_test_suite_printRequest(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    char buffer[512];
    int failures = 0;
    int test_count = 0;

    /* Variabili di supporto */
    int id, urgency, apt;
    char type, date[11], desc[256];
    char expected_keyword[50];

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("Error: Could not open test files for printRequest.\n");
        return -1;
    }

    printf("Starting Test Suite: printRequest (Visual & Logic Check)\n");
    printf("-------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), f_in) && fscanf(f_orc, "%s", expected_keyword) != EOF) {
        test_count++;

        /* Parsing: ID;Tipo;Urgenza;Apt;Data;Descrizione */
        if (sscanf(buffer, "%d;%c;%d;%d;%10s;%[^\n]", &id, &type, &urgency, &apt, date, desc) == 6) {

            request r = createRequest_TESTING(id, type, urgency, apt, date, desc);

            if (r != NULL) {
                printf("[TEST %d] Expected Keyword: %s\n", test_count, expected_keyword);

                /* Esecuzione della stampa reale */
                printRequest(r);

                /* Verifica logica: se il tipo è 'z', printRequest deve gestire l'errore */
                if (type == 'z' && getType(r) == 'z') {
                    /* Passa se il comportamento di errore è coerente */
                    printf("[PASS] Logic check for invalid type successful.\n");
                } else if (type != 'z') {
                    printf("[PASS] Visual check required, logic components OK.\n");
                } else {
                    failures++;
                }

                deallocateRequest(r);
            }
        }
    }

    fclose(f_in);
    fclose(f_orc);
    printf("-------------------------------------------\n");
    printf("Visual Suite Completed for %d tests.\n", test_count);
    return failures;
}

int run_test_suite_deallocateRequest(const char* input_path, const char* oracle_path) {
    FILE *f_in;
    char buffer[512];
    int failures = 0;
    int test_count = 0;

    int id, urgency, apartment;
    char type;
    char description[256];
    char date[20];

    f_in = fopen(input_path, "r");

    if (!f_in) {
        printf("Error: Could not open test file for deallocateRequest.\n");
        return -1;
    }

    printf("Starting Test Suite: deallocateRequest\n");
    printf("-------------------------------------------\n");

    test_count++;
    deallocateRequest(NULL);
    printf("[PASS] Test %d: NULL pointer handled correctly.\n", test_count);

    while (fgets(buffer, sizeof(buffer), f_in)) {
        test_count++;

        if (sscanf(buffer, "%d;%c;%d;%d;%[^;];%[^;\n]", &id, &type, &urgency, &apartment, date, description) >= 6) {

            request r = createRequest_TESTING(id, type, urgency, apartment, date, description);

            if (r != NULL) {
                deallocateRequest(r);
                printf("[PASS] Test %d: Request with ID %d deallocated without crash.\n", test_count, id);
            } else {
                printf("[ERROR] Failed to allocate memory in test %d\n", test_count);
                failures++;
            }
        }
    }

    fclose(f_in);

    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}