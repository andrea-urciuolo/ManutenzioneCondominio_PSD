#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/technician.h"
#include "../include/utils.h" 

// Specialization macros mapping internal logic to characters
#define PLUMBER 'a'
#define ELECTRICIAN 'b'
#define CONSTRUCTOR 'c'
#define TERMOHYDRAULIC 'd'
#define ELEVETOR 'e'
#define BLACKSMITH 'f'

// Definition of the concrete data structure for the technician ADT
// Hidden from the user (Information Hiding) via the typedef in the header file
struct c_technician {
    int idCode;                 // Unique identifier for the technician
    char name[50];              // Statically allocated array for the technician's name
    char specialization;        // Character mapping to a specific trade (e.g., 'a' for plumber)
    int interventionCount;      // Tracks the total number of interventions completed
}; 

/* Allocates memory and initializes a new technician asking the user for their details */
technician createTechnician(int Id) { 
    
    // Dynamically allocate memory in the heap for the new technician struct
    technician newTechnician = (technician)malloc(sizeof(struct c_technician)); 

    // Safety check: verify if the OS successfully allocated the requested memory
    if(newTechnician == NULL){                      
        printf("Errore nell'allocazione della memoria per la creazione del tecnico\n");       
        return NULL;
    }

    // Assign the dynamically generated or provided unique ID
    newTechnician->idCode = Id;     
    
    /* Prompts the user and safely reads a string including spaces, preventing buffer overflow */
    printf("Inserisci il nome del tecnico: ");
    readString(newTechnician->name, sizeof(newTechnician->name));
    
    /* Prompts the user for the specialization character */
    printf("Inserisci la specializzazione (a=IDRAULICO, b=ELETTRICISTA, c=MURATORE, d=TERMOIDRAULICO, e=ASCENSORISTA, f=FABBRO): ");
    
    /* Captures the exact first character typed by the user */
    newTechnician->specialization = getchar();
    
    /* Flushes the standard input buffer to discard the '\n' and any extra characters */
    clearBuffer();
       
    // Initialize the workload counter strictly to zero for data consistency
    newTechnician->interventionCount = 0; 
    
    return newTechnician;
}

/* Frees the memory previously allocated for the given technician. */
void deleteTechnician(technician tech) {        
    // Guard clause: ensure the pointer is actually pointing to a valid memory address before freeing
    if(tech != NULL)
        free(tech);            
}

/* Prints all the details and current status of the technician to the standard output. */
void printTechnician(const technician tech) {
    // Guard clause: prevents dereferencing a NULL pointer which would cause a Segmentation Fault
    if(tech == NULL){
        printf("Nessun tecnico da stampare\n");
        return;
    }

    // Formatted output of the internal structure's fields
    printf("--- Dettagli Tecnico ---\n");
    printf("Codice ID: %d\n", tech->idCode);
    printf("Nome: %s\n", tech->name);
    printf("Specializzazione: %c\n", tech->specialization); 
    printf("Interventi completati: %d\n", tech->interventionCount);
    printf("----------------------\n");
}

/* Increments the total number of interventions assigned to the technician by one. */
void addIntervention(technician tech) {
    // Safety check to ensure we are modifying an existing instance
    if (tech != NULL) {
        tech->interventionCount += 1;
    }
}

/* Returns the unique identification code of the technician. */
int getIdCode(technician tech) {
    // Return a sentinel value (-1) to indicate an error state if the pointer is invalid
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
    // Return NULL if the record does not exist
    if (tech == NULL) return NULL;
    return tech->name;
}

/* Returns the character representing the technician's specific area of expertise. */
char getSpecialization(technician tech) {
    // Return 'z' as an established error/sentinel character if the pointer is invalid
    if (tech == NULL) return 'z';
    return tech->specialization;
}

/* Test builder to create a technician programmatically, bypassing standard user input */
technician buildTechnician(int id, const char* name, char spec) {
    
    // Allocate memory just like the standard constructor
    technician newTechnician = (technician)malloc(sizeof(struct c_technician));

    // Abort and return NULL if allocation fails
    if (newTechnician == NULL) return NULL;

    newTechnician->idCode = id;

    // Use strncpy instead of strcpy to guarantee we do not exceed the 50-character limit of the buffer
    strncpy(newTechnician->name, name, sizeof(newTechnician->name) - 1);
    // Explicitly set the null terminator to ensure the string is properly closed even if truncated
    newTechnician->name[sizeof(newTechnician->name) - 1] = '\0';

    newTechnician->specialization = spec;
    newTechnician->interventionCount = 0;

    return newTechnician;
}