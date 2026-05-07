#ifndef TESTINGTECHNICIAN_H
#define TESTINGTECHNICIAN_H

int run_test_suite_deleteTechnician(const char* input_path);
int run_test_suite_addIntervention(const char* input_path, const char* oracle_path);
int run_test_suite_getIdCode(const char* input_path, const char* oracle_path);
int run_test_suite_getInterventionCount(const char* input_path, const char* oracle_path);
int run_test_suite_getSpecialization(const char* input_path, const char* oracle_path);
int run_test_suite_getName(const char* input_path, const char* oracle_path);

#endif