#ifndef OPBTREETECHNICIAN_H
#define OPBTREETECHNICIAN_H

#include "Btree.h"

/* Iterates through the Btree and prints the details of all registered technicians */
void printAllTechnicians(Btree T);

/* Filters and prints all technicians that have the specified specialization character (e.g., 'a' for plumber) */
void printTechniciansBySpecialization(Btree T, char spec);

/* Sorts the technicians in descending order based on their completed interventions and prints the ordered list */
void printTechniciansByWorkload(Btree T);

/* Scans the Btree to find and print the single technician who has completed the highest number of interventions */
void printMostActiveTechnician(Btree T);

#endif