#ifndef INTERVENTION_H
#define INTERVENTION_H

#include "../include/request.h"
#include "../include/technician.h"

typedef struct c_intervention *intervention;

intervention newIntervention(request r, technician t);

request getRequestIntervention(intervention inter);

technician getTecnicoIntervention(intervention inter);

char* getDateAppointment(intervention inter);

char* getTimeAppointment(intervention inter);

int getEstimatedTime(intervention inter);

#endif // INTERVENTION_H
