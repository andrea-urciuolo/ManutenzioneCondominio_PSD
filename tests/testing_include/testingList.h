#ifndef TESTINGLIST_H
#define TESTINGLIST_H

int run_test_suite_emptyList(const char* input_path, const char* oracle_path);

int run_test_suite_tailList(const char* input_path, const char* oracle_path);

int run_test_suite_getFirst(const char* input_path, const char* oracle_path);

int run_test_suite_consList(const char* input_path, const char* oracle_path);

int run_test_suite_sizeList(const char* input_path, const char* oracle_path);

#endif