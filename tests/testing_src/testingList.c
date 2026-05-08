#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing_include/testingList.h"
#include "../../include/list.h"
#include "../../include/item.h"

int run_test_suite_emptyList(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int size_to_create, oracle_val, actual_val;
    int failures = 0;
    int test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) {
        printf("[ERROR] Impossibile aprire i file di test per emptyList.\n");
        return -1;
    }

    printf("Starting Test Suite: emptyList\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d", &size_to_create) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;

        list l = newList();
        for(int i = 0; i < size_to_create; i++) {
            l = consList(l, NULL);
        }

        actual_val = emptyList(l);

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Size %d | emptyList -> %d\n", test_count, size_to_create, actual_val);
        } else {
            printf("[FAIL] Test %d: Size %d | Atteso %d, Ottenuto %d\n",
                    test_count, size_to_create, oracle_val, actual_val);
            failures++;
        }

        while(!emptyList(l)) {
            l = removeList(l, 0);
        }
    }

    fclose(f_in);
    fclose(f_orc);

    printf("-------------------------------------------\n");
    printf("Total Tests: %d | Failures: %d\n", test_count, failures);
    return failures;
}

int run_test_suite_tailList(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int size_to_create, oracle_is_null, failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");

    if (!f_in || !f_orc) return -1;

    printf("Starting Test Suite: tailList\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d", &size_to_create) != EOF && fscanf(f_orc, "%d", &oracle_is_null) != EOF) {
        test_count++;

        list l = newList();
        for(int i = 0; i < size_to_create; i++) l = consList(l, NULL);

        list res = tailList(l);
        int actual_is_null = (res == NULL);

        if (actual_is_null == oracle_is_null) {
            printf("[PASS] Test %d: Size %d | tailList IS_NULL -> %d\n", test_count, size_to_create, actual_is_null);
        } else {
            printf("[FAIL] Test %d: Size %d | Expected IS_NULL %d, Got %d\n", test_count, size_to_create, oracle_is_null, actual_is_null);
            failures++;
        }

        while(!emptyList(l)) l = removeList(l, 0);
    }

    fclose(f_in); fclose(f_orc);
    printf("-------------------------------------------\n");
    return failures;
}

int run_test_suite_getFirst(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    char buffer[256];
    int oracle_val, failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");
    if (!f_in || !f_orc) return -1;

    printf("Starting Test Suite: getFirst (Void* Transparency)\n");
    printf("-------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), f_in) && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        list l = newList();
        int dummy_data = 42;

        if (strstr(buffer, "VALID_PTR_INT")) {
            l = consList(l, &dummy_data);
        } else if (strstr(buffer, "VALID_PTR_STR")) {
            l = consList(l, "TestString");
        } else if (strstr(buffer, "NULL_ITEM_IN_LIST")) {
            l = consList(l, NULLITEM);
        } else if (strstr(buffer, "LARGE_LIST")) {
            l = consList(l, &dummy_data);
            l = consList(l, "Altro");
        }

        item res = getFirst(l);
        int actual_val = (res == NULLITEM) ? 0 : 1;

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: %s | Result: %s\n",
                    test_count, buffer, (actual_val ? "VALID_ITEM" : "NULLITEM"));
        } else {
            printf("[FAIL] Test %d: %s | Expected %d, Got %d\n",
                    test_count, buffer, oracle_val, actual_val);
            failures++;
        }

        while(!emptyList(l)) l = removeList(l, 0);
    }

    fclose(f_in); fclose(f_orc);
    return failures;
}

int run_test_suite_consList(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    char buffer[256];
    int oracle_size, oracle_head_val, failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");
    if (!f_in || !f_orc) return -1;

    printf("Starting Test Suite: consList\n");
    printf("-------------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), f_in) && fscanf(f_orc, "%d;%d", &oracle_size, &oracle_head_val) != EOF) {
        test_count++;
        list l = newList();

        if (strstr(buffer, "LARGE_SEQUENCE")) {
            for(int i = 0; i < 100; i++) l = consList(l, (item)(size_t)i);
        } else if (strstr(buffer, "NULL")) {
            l = consList(l, NULLITEM);
        } else {
            char *token = strtok(buffer, ";");
            while(token != NULL) {
                l = consList(l, (item)(size_t)atoi(token));
                token = strtok(NULL, ";");
            }
        }

        int actual_size = sizeList(l);
        item head = getFirst(l);
        int actual_head_val = (head == NULLITEM) ? 0 : (int)(size_t)head;

        if (actual_size == oracle_size && actual_head_val == oracle_head_val) {
            printf("[PASS] Test %d: Size %d, Head %d\n", test_count, actual_size, actual_head_val);
        } else {
            printf("[FAIL] Test %d: Expected Size %d Head %d, Got Size %d Head %d\n",
                    test_count, oracle_size, oracle_head_val, actual_size, actual_head_val);
            failures++;
        }

        while(!emptyList(l)) l = removeList(l, 0);
    }
    fclose(f_in); fclose(f_orc);
    return failures;
}

int run_test_suite_sizeList(const char* input_path, const char* oracle_path) {
    FILE *f_in, *f_orc;
    int items_to_add, oracle_val, failures = 0, test_count = 0;

    f_in = fopen(input_path, "r");
    f_orc = fopen(oracle_path, "r");
    if (!f_in || !f_orc) return -1;

    printf("Starting Test Suite: sizeList\n");
    printf("-------------------------------------------\n");

    while (fscanf(f_in, "%d", &items_to_add) != EOF && fscanf(f_orc, "%d", &oracle_val) != EOF) {
        test_count++;
        list l = newList();

        if (items_to_add > 0) {
            for (int i = 0; i < items_to_add; i++) {
                l = consList(l, (item)(size_t)i);
            }
        }

        int actual_val = sizeList(l);

        if (actual_val == oracle_val) {
            printf("[PASS] Test %d: Added %d items | sizeList -> %d\n", test_count, items_to_add, actual_val);
        } else {
            printf("[FAIL] Test %d: Added %d items | Expected %d, Got %d\n",
                    test_count, items_to_add, oracle_val, actual_val);
            failures++;
        }

        while (!emptyList(l)) l = removeList(l, 0);
    }

    fclose(f_in); fclose(f_orc);
    printf("-------------------------------------------\n");
    return failures;
}