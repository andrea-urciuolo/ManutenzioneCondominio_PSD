
#include "list.h"

/* Prints all the technicians currently in the list */
void printAllTechnicians(list l);

/* Searches for a technician by their ID code and prints their details */
void printTechnicianById(list l, int idCode);

/* Prints all technicians that match a specific specialization character */
void printTechniciansBySpecialization(list l, char spec);

/* Prints all technicians sorted descending by their number of interventions (workload) */
void printTechniciansByWorkload(list l);

/* Finds and prints the technician with the highest number of interventions */
void printMostActiveTechnician(list l);



