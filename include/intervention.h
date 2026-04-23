typedef struct c_intervention *intervention;

intervention newIntervention();

request getRequestIntervention(intervention inter);

tecnico getTecnicoIntervention(intervention inter);

char* getDateAppointment(intervention inter);

char* getTimeAppointment(intervention inter);

int getEstimatedTime(intervention inter);