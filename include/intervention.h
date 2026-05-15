#ifndef INTERVENTION_H
#define INTERVENTION_H

#include "../include/request.h"
#include "../include/technician.h"

// Pointer to the intervention structure
typedef struct c_intervention *intervention;

/*
 * Function: newIntervention
 * ----------------------
 * Creates a new intervention by linking a request and a technician
 *
 * Parameters:
 *   r: The request associated with the intervention
 *   t: The technician assigned to the intervention
 *
 * Pre-conditions:
 *   r != NULL
 *   t != NULL
 *
 * Post-conditions:
 *   Returns an intervention structure created via user input.
 *   Returns NULL if the allocation fails.
 *
 * Returns:
 *   The created intervention or NULL if allocation fails
 */
intervention newIntervention(request r, technician t);

// GETTERS

/*
 * Function: getRequestIntervention
 * ----------------------
 * Returns the request structure associated with the intervention
 *
 * Parameters:
 *   inter: The intervention from which to get the request
 *
 * Pre-conditions:
 *   inter != NULL
 *
 * Post-conditions:
 *   Returns the request structure linked to the specified intervention
 *
 * Returns:
 *   The request associated with the intervention
 */
request getRequestIntervention(intervention inter);

/*
 * Function: getTechnicianIntervention
 * ----------------------
 * Returns the technician structure associated with the intervention
 *
 * Parameters:
 *   inter: The intervention from which to get the technician
 *
 * Pre-conditions:
 *   inter != NULL
 *
 * Post-conditions:
 *   Returns the technician structure linked to the specified intervention
 *
 * Returns:
 *   The technician assigned to the intervention
 */
technician getTechnicianIntervention(intervention inter);

/*
 * Function: getDateAppointment
 * ----------------------
 * Returns the pointer to the string representing the appointment date
 *
 * Parameters:
 * inter: The intervention from which to get the date
 *
 * Pre-conditions:
 *   inter != NULL
 *
 * Post-conditions:
 *   Returns the pointer to the date string (Format: "YYYY/MM/DD")
 *
 * Returns:
 *   The string representing the appointment date
 */
char* getDateAppointment(intervention inter);

/*
 * Function: getTimeAppointment
 * ----------------------
 * Returns the pointer to the string representing the appointment time
 *
 * Parameters:
 *   inter: The intervention from which to get the time
 *
 * Pre-conditions:
 *   inter != NULL
 *
 * Post-conditions:
 *   Returns the pointer to the time string (Format: "HH:MM")
 *
 * Returns:
 *   The string representing the appointment time
 */
char* getTimeAppointment(intervention inter);

/*
 * Function: printIntervention
 * ----------------------
 * Displays the complete details of an intervention, including the
 * associated request and technician
 *
 * Parameters:
 *   inter: The intervention to be printed
 *
 * Pre-conditions:
 *   inter != NULL
 *
 * Post-conditions:
 *   None (void)
 *
 * Side-effect:
 * Prints the full summary of the intervention to the output.
 *
 * Returns:
 *   void
 */
void printIntervention(intervention inter);

/*
 * Function: deallocateIntervention
 * ----------------------
 * Deallocates the memory occupied by the intervention structure
 *
 * Parameters:
 *   inter: The intervention to be deallocated
 *
 * Pre-conditions:
 *   inter != NULL
 *
 * Post-conditions:
 *   None (void)
 *
 * Side-effect:
 *   Frees the memory pointed to by inter. Only the intervention
 *   is deallocated; the associated request and technician
 *   structures remain intact.
 *
 * Returns:
 * void
 */
void deallocateIntervention(intervention inter);

// BUILDER (for testing and --dev mode)

// Creates an intevention directly from parameters (bypasses user input)
intervention buildIntervention(request r, technician t, const char* date, const char* time);

#endif
