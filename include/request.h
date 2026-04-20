typedef struct c_request *request;

request newRequest(char type, int urgency, int apartment, int idAssignedTechnician, char submissionDate[], char* description);