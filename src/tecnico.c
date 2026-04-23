#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tecnico.h"
#include "../include/utils.h" 

#define PLUMBER 'a'
#define ELECTRICIAN 'b'
#define CONSTRUCTOR 'c'
#define TERMOHYDRAULIC 'd'
#define ELEVETOR 'e'
#define BLACKSMITH 'f'

struct c_tecnico {
    int idCode;                 // Code that identifies the technician
    char name[50];              // Technician's name
    char specialization;        // Character representing the specialization
    int interventionCount;      // Total number of interventions
}; 


/* Allocates memory and initializes a new technician asking the user for their details */
tecnico creaTecnico() { 
    
    tecnico newTechnician = (tecnico)malloc(sizeof(struct c_tecnico)); 

    if(newTechnician == NULL){                      
        printf("Errore nell'allocazione della memoria per creare il tecnico \n");       
        return NULL;
    }

    newTechnician->idCode = (rand() % 9999) + 1;        
    
    /* Asks the user for the technician's name directly from the terminal */
    printf("Inserisci il nome del tecnico: ");
    readString(newTechnician->name, sizeof(newTechnician->name));
    
    /* Asks for the specialization */
    printf("Inserisci la specializzazione (a=PLUMBER, b=ELECTRICIAN, c=CONSTRUCTOR, d=TERMOHYDRAULIC, e=ELEVETOR, f=BLACKSMITH): ");
    
    /* The space before %c is essential to ignore any leftover 'Enter' in the buffer */
    scanf(" %c", &newTechnician->specialization);
    
    /* Clears the buffer to remove the trailing newline left by scanf */
    clearBuffer();
       
    newTechnician->interventionCount = 0; 
    
    return newTechnician;
}

/* Frees the memory previously allocated for the given technician. */
void eliminaTecnico(tecnico tech) {        
    if(tech != NULL)
        free(tech);            
}

/* Prints all the details and current status of the technician to the standard output. */
void stampaTecnico(const tecnico tech) {
    if(tech == NULL){
        printf("Nessun tecnico da stampare\n");
        return;
    }

    printf("--- Scheda Tecnico ---\n");
    printf("Codice ID: %d\n", tech->idCode);
    printf("Nome: %s\n", tech->name);
    printf("Specializzazione: %c\n", tech->specialization); 
    
    printf("Interventi effettuati: %d\n", tech->interventionCount);
    printf("----------------------\n");
}

/* Increments the total number of interventions assigned to the technician by one. */
void aggiungiIntervento(tecnico tech) {
    if (tech != NULL) {
        tech->interventionCount += 1;
    }
}

/* Returns the unique identification code of the technician. */
int getCodiceIdentificativo(tecnico tech) {
    if (tech == NULL) return -1;
    return tech->idCode;
}

/* Returns the total number of interventions currently assigned to or completed by the technician. */
int getIntervento(tecnico tech) {
    if (tech == NULL) return -1;
    return tech->interventionCount;
}

/* Returns a pointer to the string containing the technician's name. */
const char* getNome(tecnico tech) {
    if (tech == NULL) return NULL;
    return tech->name;
}

/* Returns the character representing the technician's specific area of expertise. */
char getSpecializzazione(tecnico tech) {
    if (tech == NULL) return 'z';
    return tech->specialization;
}