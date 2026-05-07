#include <stdio.h>
#include <string.h>
#include "../testing_include/testingUtils.h"
#include "../../include/utils.h"

int run_test_suite_checkDateValidity(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    char buffer[256];
    int oracle_val, actual_val;
    int failures = 0;
    int test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per checkDateValidity.\n");
        return -1;
    }

    printf("Starting Test Suite: checkDateValidity\n");
    printf("-------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), f_in) && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;

        buffer[strcspn(buffer, "\r\n")] = 0;

        actual_val = checkDateValidity(buffer);

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Input '%s' | Risultato %d\n", test_count, buffer, actual_val);
        } else {
            printf("[FAIL] Test %d: Input '%s' | Atteso %d, Ottenuto %d\n",
                    test_count, buffer, oracle_val, actual_val);
            failures++;
        }
    }

    fclose(f_in);
    fclose(f_orc);

    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}

int run_test_suite_checkTimeValidity(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    char buffer[256];
    int oracle_val, actual_val;
    int failures = 0;
    int test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per checkTimeValidity.\n");
        return -1;
    }

    printf("Starting Test Suite: checkTimeValidity\n");
    printf("-------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), f_in) && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;

        buffer[strcspn(buffer, "\r\n")] = 0;

        actual_val = checkTimeValidity(buffer);

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Input '%s' | Risultato %d\n", test_count, buffer, actual_val);
        } else {
            printf("[FAIL] Test %d: Input '%s' | Atteso %d, Ottenuto %d\n",
                    test_count, buffer, oracle_val, actual_val);
            failures++;
        }
    }

    fclose(f_in);
    fclose(f_orc);

    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}

int run_test_suite_StrToInt(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    char buffer[256];
    int oracle_val, actual_val;
    int failures = 0;
    int test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per StrToInt.\n");
        return -1;
    }

    printf("Starting Test Suite: StrToInt\n");
    printf("-------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), f_in) && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;

        buffer[strcspn(buffer, "\r\n")] = 0;

        actual_val = StrToInt(buffer);

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Input '%s' | Risultato %d\n", test_count, buffer, actual_val);
        } else {
            printf("[FAIL] Test %d: Input '%s' | Atteso %d, Ottenuto %d\n",
                    test_count, buffer, oracle_val, actual_val);
            failures++;
        }
    }

    fclose(f_in);
    fclose(f_orc);

    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}