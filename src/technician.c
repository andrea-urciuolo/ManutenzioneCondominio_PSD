#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/technician.h"
#include "../include/utils.h" 

#define PLUMBER 'a'
#define ELECTRICIAN 'b'
#define CONSTRUCTOR 'c'
#define TERMOHYDRAULIC 'd'
#define ELEVETOR 'e'
#define BLACKSMITH 'f'

// Definition of the concrete data structure for the technician ADT
struct c_technician {
    int idCode;                 // Code that identifies the technician
    char name[50];              // Technician's name
    char specialization;        // Character representing the specialization
    int interventionCount;      // Total number of interventions
}; 

/* Allocates memory and initializes a new technician asking the user for their details */
technician createTechnician(int Id) { 
    
    // Allocate memory for the new technician struct
    technician newTechnician = (technician)malloc(sizeof(struct c_technician)); 

    // Check if the memory allocation was successful
    if(newTechnician == NULL){                      
        printf("Errore nell'allocazione della memoria per la creazione del tecnico\n");       
        return NULL;
    }

    // Assign the unique ID passed as a parameter
    newTechnician->idCode = Id;     
    
    /* Asks the user for the technician's name directly from the terminal */
    printf("Inserisci il nome del tecnico: ");
    readString(newTechnician->name, sizeof(newTechnician->name));
    
    /* Asks for the specialization */
    printf("Inserisci la specializzazione (a=IDRAULICO, b=ELETTRICISTA, c=MURATORE, d=TERMOIDRAULICO, e=ASCENSORISTA, f=FABBRO): ");
    
    /* Reads a single character directly from the standard input */
    newTechnician->specialization = getchar();
    
    /* Clears the buffer to remove the trailing newline (\n) left by the user pressing Enter */
    clearBuffer();
       
    // Initialize the workload counter to zero for a newly created technician
    newTechnician->interventionCount = 0; 
    
    return newTechnician;
}

/* Frees the memory previously allocated for the given technician. */
void deleteTechnician(technician tech) {        
    // Ensure the pointer is valid to prevent segmentation faults during deallocation
    if(tech != NULL)
        free(tech);            
}

/* Prints all the details and current status of the technician to the standard output. */
void printTechnician(const technician tech) {
    // Safety check for uninitialized or null pointers
    if(tech == NULL){
        printf("Nessun tecnico da stampare\n");
        return;
    }

    printf("--- Dettagli Tecnico ---\n");
    printf("Codice ID: %d\n", tech->idCode);
    printf("Nome: %s\n", tech->name);
    printf("Specializzazione: %c\n", tech->specialization); 
    
    printf("Interventi completati: %d\n", tech->interventionCount);
    printf("----------------------\n");
}


/* Increments the total number of interventions assigned to the technician by one. */
void addIntervention(technician tech) {
    if (tech != NULL) {
        tech->interventionCount += 1;
    }
}

/* Returns the unique identification code of the technician. */
int getIdCode(technician tech) {
    if (tech == NULL) return -1;
    return tech->idCode;
}

/* Returns the total number of interventions currently assigned to or completed by the technician. */
int getInterventionCount(technician tech) {
    if (tech == NULL) return -1;
    return tech->interventionCount;
}

/* Returns a pointer to the string containing the technician's name. */
const char* getName(technician tech) {
    if (tech == NULL) return NULL;
    return tech->name;
}

/* Returns the character representing the technician's specific area of expertise. */
char getSpecialization(technician tech) {
    // Return 'z' as an error code if the technician does not exist
    if (tech == NULL) return 'z';
    return tech->specialization;
}

/*Test builder to create a technician*/
technician buildTechnician(int id,const char* name, char spec) {
    // Memory allocation for test environments (bypasses standard user input)
    technician newTechnician = (technician)malloc(sizeof(struct c_technician));

    if (newTechnician == NULL) return NULL;

    newTechnician->idCode = id;

    // Safely copy the string preventing buffer overflow issues
    strncpy(newTechnician->name, name, sizeof(newTechnician->name) - 1);
    newTechnician->name[sizeof(newTechnician->name) - 1] = '\0';

    newTechnician->specialization = spec;
    newTechnician->interventionCount = 0;

    return newTechnician;
}