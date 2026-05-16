#ifndef TECHNICIAN_H
#define TECHNICIAN_H

// Pointer to the technician structure
typedef struct c_technician *technician;

/*
 * Function: createTechnician
 * ----------------------
 * Dynamically allocates a new technician in memory and asks the user for their details via input.
 *
 * Parameters:
 * Id: The unique identifier to be assigned to the new technician
 *
 * Pre-conditions:
 * None [cite: 113]
 *
 * Post-conditions:
 * Returns a pointer to a technician initialized via input, or NULL in case of failure[cite: 114].
 *
 * Complexity:
 * O(n), where n is the maximum length of the input buffer[cite: 115].
 *
 * Returns:
 * The created technician or NULL if allocation fails
 */
technician createTechnician(int Id);

/*
 * Function: printTechnician
 * ----------------------
 * Prints the details of a single technician to the screen.
 *
 * Parameters:
 * tech: The technician to be printed
 *
 * Pre-conditions:
 * tech != NULL [cite: 122]
 *
 * Post-conditions:
 * None (void) [cite: 123]
 *
 * Side-effect:
 * Prints the technician's data to the standard output[cite: 124].
 *
 * Complexity:
 * O(n), where n is the length of the name string[cite: 125].
 *
 * Returns:
 * void
 */
void printTechnician(const technician tech);

/*
 * Function: addIntervention
 * ----------------------
 * Increases the number of interventions assigned to the technician by 1.
 *
 * Parameters:
 * tech: The technician whose intervention count will be incremented
 *
 * Pre-conditions:
 * tech != NULL [cite: 127]
 *
 * Post-conditions:
 * None (void) [cite: 128]
 *
 * Side-effect:
 * Increments the intervention counter in the record of tech by 1[cite: 129].
 *
 * Complexity:
 * O(1)[cite: 129].
 *
 * Returns:
 * void
 */
void addIntervention(technician tech);

/*
 * Function: deleteTechnician
 * ----------------------
 * Frees the memory allocated for the technician when it is no longer needed.
 *
 * Parameters:
 * tech: The technician to be deallocated
 *
 * Pre-conditions:
 * tech != NULL [cite: 117]
 *
 * Post-conditions:
 * None (void) [cite: 118]
 *
 * Side-effect:
 * Deallocates the memory pointed to by tech[cite: 119].
 *
 * Complexity:
 * O(1)[cite: 120].
 *
 * Returns:
 * void
 */
void deleteTechnician(technician tech);

// GETTERS

/*
 * Function: getIdCode
 * ----------------------
 * Returns the unique identification code of the technician.
 *
 * Parameters:
 * tech: The technician of which we need the ID
 *
 * Pre-conditions:
 * None [cite: 132]
 *
 * Post-conditions:
 * If tech != NULL returns the ID, otherwise returns -1[cite: 133].
 *
 * Complexity:
 * O(1)[cite: 133].
 *
 * Returns:
 * The ID code or -1 on error
 */
int getIdCode(technician tech);

/*
 * Function: getName
 * ----------------------
 * Returns the pointer to the string containing the technician's name.
 *
 * Parameters:
 * tech: The technician of which we need the name
 *
 * Pre-conditions:
 * None [cite: 138]
 *
 * Post-conditions:
 * If tech != NULL returns the pointer to the name, otherwise returns NULL[cite: 139].
 *
 * Complexity:
 * O(1)[cite: 139].
 *
 * Returns:
 * The pointer to the name string or NULL on error
 */
const char* getName(technician tech);

/*
 * Function: getSpecialization
 * ----------------------
 * Returns the character representing the technician's specialization.
 *
 * Parameters:
 * tech: The technician of which we need the specialization
 *
 * Pre-conditions:
 * None [cite: 141]
 *
 * Post-conditions:
 * If tech != NULL returns the specialization character, otherwise returns 'z'[cite: 142].
 *
 * Complexity:
 * O(1)[cite: 142].
 *
 * Returns:
 * The specialization character or 'z' on error
 */
char getSpecialization(technician tech);

/*
 * Function: getInterventionCount
 * ----------------------
 * Returns the total number of interventions assigned to the technician.
 *
 * Parameters:
 * tech: The technician of which we need the intervention count
 *
 * Pre-conditions:
 * None [cite: 135]
 *
 * Post-conditions:
 * If tech != NULL returns an integer n >= 0, otherwise returns -1[cite: 136].
 *
 * Complexity:
 * O(1)[cite: 136].
 *
 * Returns:
 * The number of interventions or -1 on error
 */
int getInterventionCount(technician tech);

// BUILDER (for testing and --dev mode)

/*
 * Function: buildTechnician
 * ----------------------
 * Creates a technician directly from parameters (bypasses user input). 
 * Used exclusively for testing and development environments.
 *
 * Parameters:
 * id: The unique ID to assign
 * name: The name string of the technician
 * spec: The specialization character
 *
 * Pre-conditions:
 * None
 *
 * Post-conditions:
 * Returns a pointer to the initialized technician, or NULL on failure.
 *
 * Returns:
 * The created technician or NULL
 */
technician buildTechnician(int id, const char* name, char spec);

#endif