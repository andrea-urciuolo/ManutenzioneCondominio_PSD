typedef struct c_request *request;

request newRequest(int idCode, char type, int urgency, int apartment, char submissionDate[], char* description);

int getIdCode(request r);

char getType(request r);

int getUrgency(request r);

int getApartment(request r);

char* getSubmissionDate(request r);

char* getDescription(request r);

void printRequest(request r);

void deallocateRequest(request r);