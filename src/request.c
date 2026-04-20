#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
}

request newRequest(char type, int urgency, int apartment, int idAssignedTechnician, char submissionDate[], char* description) {
    srand(time(NULL));
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
        r->idCode += (rand() % 9999) + 1;
        r->idAssignedTechnician = idAssignedTechnician;
    }

    strcpy(r->submissionDate, submissionDate);
    strcpy(r->description, description);

    r->isCompleted = 0;

    return r;
}

