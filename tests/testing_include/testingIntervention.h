#ifndef TESTINGINTERVENTION_H
#define TESTINGINTERVENTION_H

int run_test_suite_getDateAppointment(const char* input_path, const char* oracle_path);
int run_test_suite_getTimeAppointment(const char* input_path, const char* oracle_path);
int run_test_suite_getRequestIntervention(const char* input_path, const char* oracle_path);
int run_test_suite_getTechnicianIntervention(const char* input_path, const char* oracle_path);
int run_test_suite_deallocateIntervention();

#endif