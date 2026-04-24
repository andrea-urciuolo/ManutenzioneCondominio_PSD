typedef struct c_technician *technician;

/* Function prototypes (Syntactic Specification) */

/* Dynamically allocates a new technician in memory and asks the user for their details */
technician createTechnician();

/* Prints the details of a single technician to the screen */
void printTechnician(const technician tech);



/* Increases the number of interventions assigned to the technician by 1 */
void addIntervention(technician tech);

/* Frees the memory allocated for the technician when it is no longer needed */
void deleteTechnician(technician tech);

/* Getters */
int getIdCode(technician tech);
const char* getName(technician tech);
char getSpecialization(technician tech);
int getInterventionCount(technician tech);


