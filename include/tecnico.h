
typedef struct c_tecnico *tecnico;

/* Function prototypes (Syntactic Specification) */

/* Dynamically allocates a new technician in memory and initializes their data */
tecnico createcnico(int codice, const char* nome, const char* specializzazione);

/* Prints the details of a single technician to the screen */
void stampatecnico(const tecnico t);

/* Modifies the availability status of the technician (e.g. after assigning an intervention) */
void impostaDisponibilita(tecnico t, int stato);
/* Increase the number of interventions assigned to the technician by 1 */
void aggiungiIntervento(tecnico t);

/* Frees the memory allocated for the technician when it is no longer needed */
void eliminatecnico(tecnico t);

int getcodiceIdentificativo(tecnico t);
char getNome(tecnico t);
char getSpecializzazione(tecnico t);
int getDisponibilita(tecnico t);
int getIntervento(tecnico t);
