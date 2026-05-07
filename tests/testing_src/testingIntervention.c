#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/intervention.h"
#include "../../include/request.h"
#include "../testing_include/testingIntervention.h"

int run_test_suite_getDateAppointment(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    char buffer[256], orc_date[11];
    char in_date[11], in_time[6];
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) return -1;

    printf("Starting Test Suite: getDateAppointment\n");
    printf("-------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), f_in) && fscanf(f_orc, "%10s", orc_date) != EOF) {
        test_count++;

        if (sscanf(buffer, "%s %s", in_date, in_time) == 2) {
            request dummy_r = (request)malloc(1);
            technician dummy_t = (technician)malloc(1);

            intervention inter = buildIntervention(dummy_r, dummy_t, in_date, in_time);
            char* actual_date = getDateAppointment(inter);

            if (actual_date != NULL && strcmp(actual_date, orc_date) == 0) {
                printf("[PASS] Test %d: Expected Date %s, Got %s\n", test_count, orc_date, actual_date);
            } else {
                printf("[FAIL] Test %d: Expected Date %s, Got %s\n", test_count, orc_date, actual_date ? actual_date : "NULL");
                failures++;
            }

            free(inter); free(dummy_r); free(dummy_t);
        }
    }
    fclose(f_in); fclose(f_orc);
    printf("Total Tests: %d | Failures: %d\n\n", test_count, failures);
    return failures;
}

int run_test_suite_getTimeAppointment(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    char buffer[256], orc_time[6];
    char in_date[11], in_time[6];
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) return -1;

    printf("Starting Test Suite: getTimeAppointment\n");
    printf("-------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), f_in) && fscanf(f_orc, "%5s", orc_time) != EOF) {
        test_count++;

        if (sscanf(buffer, "%s %s", in_date, in_time) == 2) {
            request dummy_r = (request)malloc(1);
            technician dummy_t = (technician)malloc(1);

            intervention inter = buildIntervention(dummy_r, dummy_t, in_date, in_time);
            char* actual_time = getTimeAppointment(inter);

            if (actual_time != NULL && strcmp(actual_time, orc_time) == 0) {
                printf("[PASS] Test %d: Expected Time %s, Got %s\n", test_count, orc_time, actual_time);
            } else {
                printf("[FAIL] Test %d: Expected Time %s, Got %s\n", test_count, orc_time, actual_time ? actual_time : "NULL");
                failures++;
            }

            free(inter); free(dummy_r); free(dummy_t);
        }
    }
    fclose(f_in); fclose(f_orc);
    printf("Total Tests: %d | Failures: %d\n\n", test_count, failures);
    return failures;
}

int run_test_suite_getRequestIntervention(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    char buffer[256];
    int id_req_in, id_tech_in, oracle_id;
    char date[11], time[6];
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("[ERROR] Could not open test files for getRequestIntervention.\n");
        return -1;
    }

    printf("Starting Test Suite: getRequestIntervention\n");
    printf("-------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), f_in) && fscanf(f_orc, "%d", &oracle_id) != EOF) {
        test_count++;

        if (sscanf(buffer, "%d;%d;%[^;];%s", &id_req_in, &id_tech_in, date, time) == 4) {
            request req = createRequest_TESTING(id_req_in, 'a', 3, 10, "2026/01/01", "Test");
            technician tech = buildTechnician(id_tech_in, "TestName", 'a');
            intervention inter = buildIntervention(req, tech, date, time);

            request actual_req = getRequestIntervention(inter);
            int actual_id = (actual_req != NULL) ? getIdRequest(actual_req) : -1;

            if (actual_id != -1 && actual_id == oracle_id) {
                printf("[PASS] Test %d: Request ID %d linked correctly.\n", test_count, oracle_id);
            } else {
                printf("[FAIL] Test %d: Expected Request ID %d, Got %d\n",
                        test_count, oracle_id, actual_id);
                failures++;
            }

            deallocateIntervention(inter);
            deallocateRequest(req);
            deleteTechnician(tech);
        }
    }

    fclose(f_in); fclose(f_orc);
    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n\n", test_count, failures);
    return failures;
}

int run_test_suite_getTechnicianIntervention(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    char buffer[256];
    int id_req_in, id_tech_in, oracle_id;
    char date[11], time[6];
    int failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("[ERROR] Could not open test files for getTechnicianIntervention.\n");
        return -1;
    }

    printf("Starting Test Suite: getTechnicianIntervention\n");
    printf("-------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), f_in) && fscanf(f_orc, "%d", &oracle_id) != EOF) {
        test_count++;

        if (sscanf(buffer, "%d;%d;%[^;];%s", &id_req_in, &id_tech_in, date, time) == 4) {
            request req = createRequest_TESTING(id_req_in, 'a', 3, 10, "2026/01/01", "Test");
            technician tech = buildTechnician(id_tech_in, "TestName", 'a');
            intervention inter = buildIntervention(req, tech, date, time);

            technician actual_tech = getTechnicianIntervention(inter);
            int actual_id = (actual_tech != NULL) ? getIdCode(actual_tech) : -1;

            if (actual_id != -1 && actual_id == oracle_id) {
                printf("[PASS] Test %d: Technician ID %d linked correctly.\n", test_count, oracle_id);
            } else {
                printf("[FAIL] Test %d: Expected Technician ID %d, Got %d\n",
                        test_count, oracle_id, actual_id);
                failures++;
            }

            deallocateIntervention(inter);
            deallocateRequest(req);
            deleteTechnician(tech);
        }
    }

    fclose(f_in); fclose(f_orc);
    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n\n", test_count, failures);
    return failures;
}

int run_test_suite_deallocateIntervention() {
    printf("Starting Test Suite: deallocateIntervention\n");
    printf("-------------------------------------------\n");

    deallocateIntervention(NULL);
    printf("[PASS] Test 1: NULL pointer handled correctly.\n");

    return 0;
}