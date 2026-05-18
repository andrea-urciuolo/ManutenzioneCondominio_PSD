#ifndef TESTINGREQUEST_H
#define TESTINGREQUEST_H

int run_test_suite_getIdRequest(const char* input_path, const char* oracle_path);
int run_test_suite_getType(const char* input_path, const char* oracle_path);
int run_test_suite_getUrgency(const char* input_path, const char* oracle_path);
int run_test_suite_getApartment(const char* input_path, const char* oracle_path);
int run_test_suite_getSubmissionDate(const char* input_path, const char* oracle_path);
int run_test_suite_getDescription(const char* input_path, const char* oracle_path);
int run_test_suite_deallocateRequest(const char* input_path);

#endif