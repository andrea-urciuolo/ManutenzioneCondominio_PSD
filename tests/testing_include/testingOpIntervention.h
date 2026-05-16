#ifndef TESTINGOPINTERVENTION_H
#define TESTINGOPINTERVENTION_H

int run_test_suite_printAllInterventions(const char* input_path, const char* oracle_path);
int run_test_suite_printInterventionById(const char* input_path, const char* oracle_path);
int run_test_suite_printInterventionsByDate(const char* input_path, const char* oracle_path);
int run_test_suite_printInterventionsByTech(const char* input_path, const char* oracle_path);
int run_test_suite_printInterventionsByType(const char* input_path, const char* oracle_path);
int run_test_suite_checkConflict(const char* input_path, const char* oracle_path);

#endif