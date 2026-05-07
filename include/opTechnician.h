#ifndef OPTECHNICIAN_H
#define OPTECHNICIAN_H

#include "list.h"
#include "technician.h"


/* Iterates through the linked list and prints the details of all registered technicians */
void printAllTechnicians(list l);

/* Searches the list for a technician matching the provided unique ID and prints their information */
void printTechnicianById(list l, int idCode);

/* Filters and prints all technicians that have the specified specialization character (e.g., 'a' for plumber) */
void printTechniciansBySpecialization(list l, char spec);

/* Sorts the technicians in descending order based on their completed interventions and prints the ordered list */
void printTechniciansByWorkload(list l);

/* Scans the list to find and print the single technician who has completed the highest number of interventions */
void printMostActiveTechnician(list l);

/* Retrieves a specific technician object by their unique ID without printing. Returns NULL if the ID is not present in the list */
technician getTechnicianById(list l, int idCode);

#endif