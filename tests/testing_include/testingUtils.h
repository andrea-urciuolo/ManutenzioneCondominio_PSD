#ifndef TESTINGUTILS_H
#define TESTINGUTILS_H

int run_test_suite_checkDateValidity(const char* input_path, const char* oracle_path);

int run_test_suite_checkTimeValidity(const char* input_path, const char* oracle_path);

int run_test_suite_StrToInt(const char* input_path, const char* oracle_path);

#endif