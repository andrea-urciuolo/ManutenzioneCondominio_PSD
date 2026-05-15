#ifndef REQUEST_H
#define REQUEST_H

// Pointer to the request structure
typedef struct c_request *request;

/*
 * Function: newRequest
 * ----------------------
 * Creates a new request initialized by the user via input
 *
 * Parameters:
 *   id: The ID of the request we want to create
 *
 * Pre-conditions:
 *   None
 *
 * Post-conditions:
 *   Returns a pointer to a request initialized by the user.
 *   If memory allocation fails, returns NULL
 *
 * Returns:
 *   The created request or NULL if allocation fails
 */
request newRequest(int Id);

// GETTERS

/*
 * Function: getIdRequest
 * ----------------------
 * Returns the ID of the request
 *
 * Parametes:
 *   r: The request of which we need the ID
 *
 * Pre-conditions:
 *   r != NULL
 *
 * Post-conditions:
 *    Returns an integer n >= 0, which rapresents the ID of the request
 *
 * Returns:
 *   The ID of the request
 */
int getIdRequest(request r);

/*
 * Function: getType
 * ----------------------
 * Returns the character identifying the type of the request
 *
 * Parameters:
 *   r: The request of which we need the type
 *
 * Pre-conditions:
 *   None
 *
 * Post-conditions:
 *   Returns a char c € {'a', 'b', 'c', 'd', 'e', 'f'} if r != NULL, otherwise returns 'z'
 *
 * Returns:
 *   The character representing the request type (or 'z' on error)
 */
char getType(request r);

/*
 * Function: getUrgency
 * ----------------------
 * Returns the urgency level of the request
 *
 * Parameters:
 *   r: The request of which we need the urgency
 *
 * Pre-conditions:
 *   None
 *
 * Post-conditions:
 *   If r != NULL, returns an integer n where 1 <= n <= 5.
 *   Otherwise, returns -1
 *
 * Returns:
 *   The urgency level of the request or -1 in case of error
 */
int getUrgency(request r);

/*
 * Function: getApartment
 * ----------------------
 * Returns the apartment number associated with the request
 *
 * Parameters:
 *   r: The request of which we need the apartment number
 *
 * Pre-conditions:
 *   None
 *
 * Post-conditions:
 *   If r != NULL, returns the apartment number (n >= 0).
 *   Otherwise, returns -1
 *
 * Returns:
 *   The apartment number or -1 in case of error
 */
int getApartment(request r);

/*
 * Function: getSubmissionDate
 * ----------------------
 * Returns the pointer to the string conteining the submission date of the request
 *
 * Parameters:
 *   r: The request of which we need the submission date
 *
 * Pre-conditions:
 *   None
 *
 * Post-conditions:
 *   If r != NULL, returns the date as a string in the format "YYYY/MM/DD".
 *   Otherwise, returns NULL
 *
 * Returns:
 *   The string representing the submission date or NULL in case of error
 */
char* getSubmissionDate(request r);

/*
 * Function: getDescription
 * ----------------------
 * Returns the pointer to the string containing the request description
 *
 * Parameters:
 *   r: The request of which we need the description
 *
 * Pre-conditions:
 *   r != NULL
 *
 * Post-conditions:
 *   Returns the pointer to the string containing the description of r
 *
 * Returns:
 *   The pointer to the string containing the description of the request
 */
char* getDescription(request r);

/*
 * Function: printRequest
 * ----------------------
 * Prints a formatted summary of all the request data
 *
 * Parameters:
 *   r: The request to be printed
 *
 * Pre-conditions:
 *   r != NULL
 *
 * Post-conditions:
 *   None (void)
 *
 * Side-effect:
 *   Prints the formatted summary of all data in r
 *
 * Returns:
 *   void
 */
void printRequest(request r);

/*
 * Function: deallocateRequest
 * ----------------------
 * Deallocates the memory previously allocated for a request
 *
 * Parameters:
 *   r: The request to be deallocated
 *
 * Pre-conditions:
 *   r != NULL
 *
 * Post-conditions:
 *   None (void)
 *
 * Side-effect:
 *   Frees the memory occupied by the request r
 *
 * Returns:
 *   void
 */
void deallocateRequest(request r);

// BUILDER (for testing and --dev mode)

// Creates a request directly from parameters (bypasses user input)
request createRequest_TESTING(int id, char type, int urgency, int apartment, const char* date, const char* desc);

#endif
