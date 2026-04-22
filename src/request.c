#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/request.h"

struct c_request {
    int idCode;                  // Id code for the request
    char type;                   // Type of request   Es: Fixing the plumbering
    int urgency;                 // Level of urgency  1 (low) - 5 (high)
    int apartment;               // Civic number who sent the request
    char submissionDate[11];     // Format: YYYY/MM/DD
    char* description;           // Description of the problem
};

request newRequest(int idCode, char type, int urgency, int apartment, char submissionDate[], char* description) {
    // Allocate memory for the request adt
    request r = malloc(sizeof(struct c_request));
    if (r == NULL) return NULL;

    // Assign parameter values
    r->idCode = idCode;
    r->type = type;
    r->urgency = urgency;
    r->apartment = apartment;

    // Copying submissionDate avoiding a Buffer Overflow
    strncpy(r->submissionDate, submissionDate, sizeof(r->submissionDate) - 1);
    r->submissionDate[sizeof(r->submissionDate) - 1] = '\0';

    // Error handling in case of missing description
    if (description == NULL) {
        free(r);
        return NULL;
    }

    // Allocate memory for the description of the request
    r->description = malloc(strlen(description) + 1);
    if (r->description == NULL) {
        free(r);
        return NULL;
    }
    strcpy(r->description, description);

    return r;
}

int getIdCode(request r) {
    if (r == NULL) return -1;
    return r->idCode;
}

char getType(request r) {
    if (r == NULL) return 'z'; // Return Default value for the type parameter
    return r->type;
}

int getUrgency(request r) {
    if (r == NULL) return -1;
    return r->urgency;
}

int getApartment(request r) {
    if (r == NULL) return -1;
    return r->apartment;
}

char* getSubmissionDate(request r) {
    if (r == NULL) return NULL;
    return r->submissionDate;
}

char* getDescription(request r) {
    if (r == NULL) return NULL;
    return r->description;
}

void deallocateRequest(request r) {
    if (r == NULL) return;
    free(r->description);
    free(r);
}