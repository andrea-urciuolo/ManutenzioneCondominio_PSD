#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/request.h"

struct c_request {
    int idCode;                  // Id code for the request   Es: 10000
    char type;                   // Type of request   Es: Fixing the plumbering
    int urgency;                 // Level of urgency  1 (low) - 5 (high)
    int apartment;               // Civic number who sent the request
    int idAssignedTechnician;    // Id code of the Technician Assigned
    char submissionDate[11];     // Format: XX/XX/XXXX   day/month/year
    char* description;           // Description of the problem
    int isCompleted;             // 1 = Yes | 0 = No
};

request newRequest(char type, int urgency, int apartment, int idAssignedTechnician, char submissionDate[], char* description) {
    request *r;
    r = malloc(sizeof(struct c_request));
    if (r == NULL) return NULL;

    r->idCode = 0;
    switch (type) {
        case 'a':
            r->idCode += 10000;
            break;
        case 'e':
            r->idCode += 20000;
            break;
        case 'i':
            r->idCode += 30000;
            break;
        case 'o':
            r->idCode += 40000;
            break;
        case 'u':
            r->idCode += 50000;
            break;
        default:
            return NULL;
    }

    r->type = type;
    r->urgency = urgency;
    r->apartment = apartment;

    if (idAssignedTechnician != 0) {
        r->idCode += (rand() % 9999) + 1;   //  TODO: add <time.h> to main and srand(time(NULL)) 
        r->idAssignedTechnician = idAssignedTechnician;
    }

    strcpy(r->submissionDate, submissionDate);
    
    r->description = malloc(strlen(description) + 1);
    if (r->description == NULL) return NULL;

    strcpy(r->description, description);

    r->isCompleted = 0;

    return r;
}

int getIdCode(request r) {
    if (r == NULL) return -1;
    return r->idCode;
}

char getType(request r) {
    if (r == NULL) return 'z';
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

int getIdAssignedTechnician(request r) {
    if (r == NULL) return -1;
    return r->idAssignedTechnician;
}

char* getSubmissionDate(request r) {
    if (r == NULL) return NULL;
    return r->submissionDate;
}

char* getDescription(request r) {
    if (r == NULL) return NULL;
    return r->description;
}

int getIsCompleted(request r) {
    return r->isCompleted;
}