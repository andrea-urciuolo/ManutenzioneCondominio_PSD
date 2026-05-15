#ifndef MANUTENZIONECONDOMINIO_PSD_OPREQUEST_H
#define MANUTENZIONECONDOMINIO_PSD_OPREQUEST_H

/*
 * Function: run_test_suite_printAllRequests
 * ----------------------
 * Executes the test suite for the printAllRequests function.
 * Verifies that printing the entire priority queue occurs safely,
 * ensuring that the queue is not accidentally emptied or corrupted.
 *
 * Parameters:
 * input_path: The path to the file containing the input scenarios
 * oracle_path: The path to the file containing the expected results (oracle)
 *
 * Pre-conditions:
 * None
 *
 * Post-conditions:
 * Returns an integer representing the test suite outcome.
 *
 * Returns:
 * The number of failed tests (0 if perfect), or -1 in case of I/O error
 */
int run_test_suite_printAllRequests(const char* input_path, const char* oracle_path);

/*
 * Function: run_test_suite_printRequestById
 * ----------------------
 * Executes the test suite for the printRequestById function.
 * Validates the correct linear search within the priority queue
 * to identify and print a single specific request.
 *
 * Parameters:
 * input_path: The path to the file with the scenarios and target IDs
 * oracle_path: The path to the file with the expected results
 *
 * Pre-conditions:
 * None
 *
 * Post-conditions:
 * Returns an integer representing the test suite outcome.
 *
 * Returns:
 * The number of failed tests (0 if the suite passes entirely), or -1 for I/O errors
 */
int run_test_suite_printRequestById(const char* input_path, const char* oracle_path);

/*
 * Function: run_test_suite_printRequestsByType
 * ----------------------
 * Executes the test suite for the printRequestsByType function.
 * Ensures that the filter based on the specialization character
 * works without interrupting the traversal of the queue.
 *
 * Parameters:
 * input_path: The path to the file containing the test volumes and type characters (e.g., 'a')
 * oracle_path: The path to the file containing the verification results
 *
 * Pre-conditions:
 * None
 *
 * Post-conditions:
 * Returns an integer representing the test suite outcome.
 *
 * Returns:
 * The total number of failed tests, or -1 if the files are unreadable
 */
int run_test_suite_printRequestsByType(const char* input_path, const char* oracle_path);

/*
 * Function: run_test_suite_printRequestsByApartment
 * ----------------------
 * Executes the test suite for the printRequestsByApartment function.
 * Guarantees that the sorting logic by apartment number adequately 
 * handles the queries, including the special case '0' for the building.
 *
 * Parameters:
 * input_path: The path to the scenario file
 * oracle_path: The path to the output oracle
 *
 * Pre-conditions:
 * None
 *
 * Post-conditions:
 * Returns an integer representing the test suite outcome.
 *
 * Returns:
 * Total number of failures, or -1 if the files are missing
 */
int run_test_suite_printRequestsByApartment(const char* input_path, const char* oracle_path);

/*
 * Function: run_test_suite_getRequestById
 * ----------------------
 * Executes the test suite for the getRequestById function.
 * Verifies that the function returns the correct memory address of the 
 * request associated with the requested ID, protecting the returned data.
 *
 * Parameters:
 * input_path: The path to the scenario configuration file
 * oracle_path: The path to the file containing the expected presence flags
 *
 * Pre-conditions:
 * None
 *
 * Post-conditions:
 * Returns an integer representing the test suite outcome.
 *
 * Returns:
 * The sum of failed tests, otherwise -1 for file loading problems
 */
int run_test_suite_getRequestById(const char* input_path, const char* oracle_path);

#endif /* MANUTENZIONECONDOMINIO_PSD_OPREQUEST_H */