#ifndef OPINTERVENTION_H
#define OPINTERVENTION_H

#include "list.h"
#include "intervention.h"

/* Prints all the interventions currently in the list */
void printAllInterventions(list l);

/* Searches for an intervention by the ID of its associated request and prints it */
void printInterventionById(list l, int requestId);

/* Prints all interventions scheduled for a specific date (format YYYY/MM/DD) */
void printInterventionsByDate(list l, const char* date);

/* Prints all interventions assigned to a specific technician (by technician ID) */
void printInterventionsByTechnician(list l, int techId);

/* Prints all interventions based on the type of the problem (extracted from the request) */
void printInterventionsByType(list l, char problemType);

/* 
 * Checks if a specific technician is already busy on a given date and time.
 * Returns 1 if a conflict exists, 0 if the slot is free.
 * (Solves the TODO in intervention.c)
 */
int checkConflict(list l, int techId, const char* date, const char* time);

#endif // OPINTERVENTION_H