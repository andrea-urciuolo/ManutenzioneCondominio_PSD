#ifndef REQUEST_H
#define REQUEST_H

/* Pointer to the concrete request structure, hiding the implementation details (Opaque pointer) */
typedef struct c_request *request;

/* Dynamically allocates a new request in memory and prompts the user for its details */
request newRequest(int Id);

/* Getters */

/* Returns the unique identification code of the request */
int getIdRequest(request r);

/* Returns the character representing the category/type of the request */
char getType(request r);

/* Returns the urgency level of the request (1 to 5) */
int getUrgency(request r);

/* Returns the apartment number associated with the request (0 for the whole building) */
int getApartment(request r);

/* Returns a pointer to the string containing the submission date (Format: YYYY/MM/DD) */
char* getSubmissionDate(request r);

/* Returns a pointer to the string containing the description of the problem */
char* getDescription(request r);

/* Prints all the details of the request to the standard output */
void printRequest(request r);

/* Frees the dynamically allocated memory for the request and its internal description string */
void deallocateRequest(request r);

/* Test Builder */

/* Creates a request directly from parameters for testing purposes (bypasses user input) */
request createRequest_TESTING(int id, char type, int urgency, int apartment, const char* date, const char* desc);

#endif
