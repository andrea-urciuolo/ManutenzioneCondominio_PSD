#ifndef INTERVENTION_H
#define INTERVENTION_H

#include "../include/request.h"
#include "../include/technician.h"

typedef struct c_intervention *intervention;

intervention newIntervention(request r, technician t);

request getRequestIntervention(intervention inter);

technician getTechnicianIntervention(intervention inter);

char* getDateAppointment(intervention inter);

char* getTimeAppointment(intervention inter);

void printIntervention(intervention inter);

void deallocateIntervention(intervention inter);

intervention buildIntervention(request r, technician t, const char* date, const char* time);

#endif
