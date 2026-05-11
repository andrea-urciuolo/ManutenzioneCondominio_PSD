
#ifndef MANUTENZIONECONDOMINIO_PSD_PQUEUETESTING_H
#define MANUTENZIONECONDOMINIO_PSD_PQUEUETESTING_H

/* Function prototypes for testing the PQueue module */

/* Runs tests to verify the successful creation and initialization of a new Priority Queue */
int run_test_suite_newPQ(const char* input_path, const char* oracle_path);

/* Runs tests to check if the emptyPQ function correctly identifies empty and non-empty queues */
int run_test_suite_emptyPQ(const char* input_path, const char* oracle_path);

/* Runs tests to ensure getMax correctly retrieves the element with the highest priority without removing it */
int run_test_suite_getMax(const char* input_path, const char* oracle_path);

/* Runs tests to verify that deleteMax correctly removes the highest priority element and restores the heap property */
int run_test_suite_deleteMax(const char* input_path, const char* oracle_path);

/* Runs tests to validate the correct insertion of new elements and the dynamic resizing of the Priority Queue */
int run_test_suite_insert(const char* input_path, const char* oracle_path);

/* Runs tests to ensure deallocatePQ safely frees the allocated memory without causing crashes */
int run_test_suite_deallocatePQ(const char* input_path, const char* oracle_path);

#endif //MANUTENZIONECONDOMINIO_PSD_PQUEUETESTING_H
