/* Definition of the data structure for the Technician */
typedef struct {
    int codiceIdentificativo;   // code that identifies the technician
    char nome[50];
    char specializzazione[50];
    int disponibilita;        /* 1 = available, 0 = busy */
    int numeroInterventi;
} Tecnico;

/* Function prototypes (Syntactic Specification) */

/* Dynamically allocates a new technician in memory and initializes their data */
Tecnico* creaTecnico(int codice, const char* nome, const char* specializzazione);

/* Prints the details of a single technician to the screen */
void stampaTecnico(const Tecnico* t);

/* Modifies the availability status of the technician (e.g. after assigning an intervention) */
void impostaDisponibilita(Tecnico* t, int stato);
/* Increase the number of interventions assigned to the technician by 1 */
void aggiungiIntervento(Tecnico* t);

/* Frees the memory allocated for the technician when it is no longer needed */
void eliminaTecnico(Tecnico* t);