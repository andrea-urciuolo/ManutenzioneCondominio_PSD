typedef struct c_request *request;

request newRequest(char type, int urgency, int apartment, int idAssignedTechnician, char submissionDate[], char* description);

int getIdCode(request r);

char getType(request r);

int getUrgency(request r);

int getApartment(request r);

int getIdAssignedTechnician(request r);

char* getSubmissionDate(request r);

char* getDescription(request r);

int getIsCompleted(request r);