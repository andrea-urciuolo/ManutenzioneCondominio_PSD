typedef struct c_tecnico *tecnico;

/* Function prototypes (Syntactic Specification) */

/* Dynamically allocates a new technician in memory and initializes their data */
tecnico creaTecnico(const char* nome, char specializzazione);

/* Prints the details of a single technician to the screen */
void stampaTecnico(const tecnico t);

/* Modifies the availability status of the technician (e.g. after assigning an intervention) */
void impostaDisponibilita(tecnico t, int stato);

/* Increase the number of interventions assigned to the technician by 1 */
void aggiungiIntervento(tecnico t);

/* Frees the memory allocated for the technician when it is no longer needed */
void eliminaTecnico(tecnico t);

/* Getters */
int getCodiceIdentificativo(tecnico t);
const char* getNome(tecnico t);
char getSpecializzazione(tecnico t);
int getDisponibilita(tecnico t);
int getIntervento(tecnico t);


