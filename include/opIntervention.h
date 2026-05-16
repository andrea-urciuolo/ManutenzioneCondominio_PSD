#ifndef OPINTERVENTION_H
#define OPINTERVENTION_H

#include "list.h"
#include "intervention.h"

/*
 * Function: printAllInterventions
 * ----------------------
 * Prints the details of all the interventions currently stored in the list.
 *
 * Parameters:
 * l: The list containing the interventions to be printed
 *
 * Pre-conditions:
 * None
 *
 * Post-conditions:
 * None (void)
 *
 * Side-effect:
 * Iterates through the entire list and prints each intervention. 
 * If the list is empty, prints a warning message.
 *
 * Complexity:
 * O(n), where n is the number of interventions in the list
 *
 * Returns:
 * void
 */
void printAllInterventions(list l);

/*
 * Function: printInterventionById
 * ----------------------
 * Searches for an intervention based on the unique ID of its associated request 
 * and prints its details.
 *
 * Parameters:
 * l: The list of interventions
 * requestId: The ID of the request to search for
 *
 * Pre-conditions:
 * requestId > 0
 *
 * Post-conditions:
 * None (void)
 *
 * Side-effect:
 * Prints the first intervention found with the matching request ID. 
 * If not found, prints an error message.
 *
 * Complexity:
 * O(n), where n is the number of elements in the list
 *
 * Returns:
 * void
 */
void printInterventionById(list l, int requestId);

/*
 * Function: printInterventionsByDate
 * ----------------------
 * Searches for and prints all interventions scheduled for a specific date.
 *
 * Parameters:
 * l: The list of interventions
 * date: A pointer to the string containing the target date
 *
 * Pre-conditions:
 * date must be formatted as "YYYY/MM/DD"
 *
 * Post-conditions:
 * None (void)
 *
 * Side-effect:
 * Prints all interventions whose date matches the input string.
 *
 * Complexity:
 * O(n), where n is the number of elements in the list
 *
 * Returns:
 * void
 */
void printInterventionsByDate(list l, const char* date);

/*
 * Function: printInterventionsByTech
 * ----------------------
 * Searches for and prints all interventions assigned to a specific technician.
 *
 * Parameters:
 * l: The list of interventions
 * techId: The unique identifier of the technician
 *
 * Pre-conditions:
 * techId > 0
 *
 * Post-conditions:
 * None (void)
 *
 * Side-effect:
 * Prints all the interventions assigned to the specified technician.
 *
 * Complexity:
 * O(n), where n is the number of elements in the list
 *
 * Returns:
 * void
 */
void printInterventionsByTech(list l, int techId);

/*
 * Function: printInterventionsByType
 * ----------------------
 * Searches for and prints all interventions corresponding to a specific problem type.
 *
 * Parameters:
 * l: The list of interventions
 * problemType: The character representing the category of the intervention
 *
 * Pre-conditions:
 * None
 *
 * Post-conditions:
 * None (void)
 *
 * Side-effect:
 * Prints all interventions matching the requested type.
 *
 * Complexity:
 * O(n), where n is the number of elements in the list
 *
 * Returns:
 * void
 */
void printInterventionsByType(list l, char problemType);

/*
 * Function: checkConflict
 * ----------------------
 * Checks if a specific technician is already busy on a given date and time slot.
 *
 * Parameters:
 * l: The list of scheduled interventions
 * techId: The ID of the technician to check
 * date: A pointer to the string containing the target date
 * time: A pointer to the string containing the target time
 *
 * Pre-conditions:
 * techId > 0, date and time must be correctly formatted strings
 *
 * Post-conditions:
 * Returns 1 (true) if an intervention already exists for that technician 
 * at that specific date and time, 0 (false) otherwise.
 *
 * Complexity:
 * O(n), where n is the number of elements in the list
 *
 * Returns:
 * 1 if a conflict exists, 0 otherwise
 */
int checkConflict(list l, int techId, const char* date, const char* time);

#endif // OPINTERVENTION_H