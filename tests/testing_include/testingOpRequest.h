#ifndef MANUTENZIONECONDOMINIO_PSD_OPREQUEST_H
#define MANUTENZIONECONDOMINIO_PSD_OPREQUEST_H


int run_test_suite_printAllRequests(const char* input_path, const char* oracle_path);

int run_test_suite_printRequestById(const char* input_path, const char* oracle_path);

int run_test_suite_printRequestsByType(const char* input_path, const char* oracle_path);
#endif /*MANUTENZIONECONDOMINIO_PSD_OPREQUEST_H */