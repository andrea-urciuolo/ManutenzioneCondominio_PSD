#ifndef REQUEST_H
#define REQUEST_H

typedef struct c_request *request;

request newRequest();

int getIdRequest(request r);

char getType(request r);

int getUrgency(request r);

int getApartment(request r);

char* getSubmissionDate(request r);

char* getDescription(request r);

void printRequest(request r);

void deallocateRequest(request r);

#endif
