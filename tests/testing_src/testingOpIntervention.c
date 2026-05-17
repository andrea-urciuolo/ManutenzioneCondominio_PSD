#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/opIntervention.h"
#include "../../include/intervention.h"
#include "../../include/request.h"
#include "../../include/technician.h"
#include "../../include/list.h"

// Include della funzione factory di testing per le richieste
#include "../testing_include/testingRequest.h"


static intervention create_dummy_intervention(int requestId, char type, int techId, const char* date, const char* time) {
    request r = createRequest_TESTING(requestId, type, 3, 101, "2026/01/01", "Richiesta Test");
    technician t = buildTechnician(techId, "Nome Cognome", 'A');
    intervention inter = buildIntervention(r, t, date, time);

    return inter;
}


static void deep_deallocate_intervention(intervention inter) {
    if (inter == NULL) return;

    request r = getRequestIntervention(inter);
    technician t = getTechnicianIntervention(inter);

    if (r != NULL) deallocateRequest(r);
    if (t != NULL) deleteTechnician(t);

    deallocateIntervention(inter);
}


static void deep_clear_list(list l) {
    list current = l;
    while (!emptyList(current)) {
        intervention inter = (intervention)getFirst(current);
        deep_deallocate_intervention(inter);

        list next_node = tailList(current);
        free(current);
        current = next_node;
    }
}


int run_test_suite_printAllInterventions(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, oracle_val, actual_val;
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per printAllInterventions.\n");
        return -1;
    }

    printf("Starting Test Suite: printAllInterventions\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d", &scenario) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        list l = newList();
        actual_val = 0;

        if (scenario == -1) {
            printAllInterventions(NULL);
            actual_val = 1;
        } else {
            for(int i = 0; i < scenario; i++) {
                intervention inter = create_dummy_intervention(i, 'A', 100 + i, "2026/05/16", "10:00");
                l = consList(l, inter);
            }
            printAllInterventions(l);
            actual_val = 1;
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d | Esecuzione completata in sicurezza\n", test_count, scenario);
        } else {
            printf("[FAIL] Test %d: Scenario %d | Atteso %d, Ottenuto %d\n", test_count, scenario, oracle_val, actual_val);
            failures++;
        }

        if (scenario > 0) {
            deep_clear_list(l);
        }
    }

    fclose(f_in);
    fclose(f_orc);
    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}

int run_test_suite_printInterventionById(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, target_id, oracle_val, actual_val;
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");
    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per printInterventionById.\n");
        return -1;
    }

    printf("Starting Test Suite: printInterventionById\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d %d", &scenario, &target_id) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        list l = newList();
        actual_val = 0;

        if (scenario == -1) {
            printInterventionById(NULL, target_id);
            actual_val = 1;
        } else {
            for(int i = 1; i <= scenario; i++) {
                intervention inter = create_dummy_intervention(i, 'A', 100 + i, "2026/05/16", "10:00");
                l = consList(l, inter);
            }
            printInterventionById(l, target_id);
            actual_val = 1;
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d (Cerca ID Richiesta %d) | Esecuzione completata\n", test_count, scenario, target_id);
        } else {
            printf("[FAIL] Test %d: Scenario %d (Cerca ID Richiesta %d) | Atteso %d, Ottenuto %d\n", test_count, scenario, target_id, oracle_val, actual_val);
            failures++;
        }

        if (scenario > 0) {
            deep_clear_list(l);
        }
    }

    fclose(f_in);
    fclose(f_orc);
    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}

int run_test_suite_printInterventionsByDate(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, oracle_val, actual_val;
    char target_date[20];
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");
    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per printInterventionsByDate.\n");
        return -1;
    }

    printf("Starting Test Suite: printInterventionsByDate\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d %s", &scenario, target_date) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        list l = newList();
        actual_val = 0;

        if (scenario == -1) {
            printInterventionsByDate(NULL, target_date);
            actual_val = 1;
        } else {
            for(int i = 0; i < scenario; i++) {
                const char* d = (i % 2 == 0) ? "2026/05/16" : "2026/12/25";
                intervention inter = create_dummy_intervention(i, 'A', 50, d, "09:00");
                l = consList(l, inter);
            }
            printInterventionsByDate(l, target_date);
            actual_val = 1;
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d (Data %s) | Esecuzione completata\n", test_count, scenario, target_date);
        } else {
            printf("[FAIL] Test %d: Scenario %d (Data %s) | Atteso %d, Ottenuto %d\n", test_count, scenario, target_date, oracle_val, actual_val);
            failures++;
        }

        if (scenario > 0) {
            deep_clear_list(l);
        }
    }

    fclose(f_in);
    fclose(f_orc);
    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}

int run_test_suite_printInterventionsByTech(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, target_tech_id, oracle_val, actual_val;
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");
    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per printInterventionsByTech.\n");
        return -1;
    }

    printf("Starting Test Suite: printInterventionsByTech\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d %d", &scenario, &target_tech_id) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        list l = newList();
        actual_val = 0;

        if (scenario == -1) {
            printInterventionsByTech(NULL, target_tech_id);
            actual_val = 1;
        } else {
            for(int i = 0; i < scenario; i++) {
                int t_id = (i % 2 == 0) ? 7 : 9;
                intervention inter = create_dummy_intervention(i, 'B', t_id, "2026/05/16", "11:30");
                l = consList(l, inter);
            }
            printInterventionsByTech(l, target_tech_id);
            actual_val = 1;
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d (ID Tecnico %d) | Esecuzione completata\n", test_count, scenario, target_tech_id);
        } else {
            printf("[FAIL] Test %d: Scenario %d (ID Tecnico %d) | Atteso %d, Ottenuto %d\n", test_count, scenario, target_tech_id, oracle_val, actual_val);
            failures++;
        }

        if (scenario > 0) {
            deep_clear_list(l);
        }
    }

    fclose(f_in);
    fclose(f_orc);
    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}

int run_test_suite_printInterventionsByType(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, oracle_val, actual_val;
    char target_type;
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");
    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per printInterventionsByType.\n");
        return -1;
    }

    printf("Starting Test Suite: printInterventionsByType\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d %c", &scenario, &target_type) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        list l = newList();
        actual_val = 0;

        if (scenario == -1) {
            printInterventionsByType(NULL, target_type);
            actual_val = 1;
        } else {
            for(int i = 0; i < scenario; i++) {
                char t = (i % 2 == 0) ? 'X' : 'Y';
                intervention inter = create_dummy_intervention(i, t, 12, "2026/05/16", "14:15");
                l = consList(l, inter);
            }
            printInterventionsByType(l, target_type);
            actual_val = 1;
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Scenario %d (Tipo Problema '%c') | Esecuzione completata\n", test_count, scenario, target_type);
        } else {
            printf("[FAIL] Test %d: Scenario %d (Tipo Problema '%c') | Atteso %d, Ottenuto %d\n", test_count, scenario, target_type, oracle_val, actual_val);
            failures++;
        }

        if (scenario > 0) {
            deep_clear_list(l);
        }
    }

    fclose(f_in);
    fclose(f_orc);
    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}

int run_test_suite_checkConflict(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int scenario, target_tech_id, oracle_val, actual_val;
    char target_date[20], target_time[10];
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");
    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per checkConflict.\n");
        return -1;
    }

    printf("Starting Test Suite: checkConflict\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d %d %s %s", &scenario, &target_tech_id, target_date, target_time) != EOF &&
           fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        list l = newList();

        if (scenario == -1) {
            actual_val = checkConflict(NULL, target_tech_id, target_date, target_time);
        } else {
            if (scenario > 0) {
                intervention inter1 = create_dummy_intervention(1, 'A', 10, "2026/05/16", "10:30");
                l = consList(l, inter1);
            }
            if (scenario > 1) {
                intervention inter2 = create_dummy_intervention(2, 'B', 20, "2026/12/25", "18:00");
                l = consList(l, inter2);
            }
            
            actual_val = checkConflict(l, target_tech_id, target_date, target_time);
        }

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Conflitto rilevato coerentemente -> %d\n", test_count, actual_val);
        } else {
            printf("[FAIL] Test %d: Atteso %d, Ottenuto %d\n", test_count, oracle_val, actual_val);
            failures++;
        }

        if (scenario > 0) {
            deep_clear_list(l);
        }
    }

    fclose(f_in); 
    fclose(f_orc);
    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}