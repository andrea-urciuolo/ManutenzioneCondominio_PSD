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

struct c_technician {
    int idCode;                 // Code that identifies the technician
    char name[50];              // Technician's name
    char specialization;        // Character representing the specialization
    int availability;           // 1 = available, 0 = busy
    int interventionCount;      // Total number of interventions
}; 


/* Allocates memory and initializes a new technician asking the user for their details */
technician createTechnician() { 
    
    technician newTechnician = (technician)malloc(sizeof(struct c_technician)); 

    if(newTechnician == NULL){                      
        printf("Error allocating memory to create the technician\n");       
        return NULL;
    }

    newTechnician->idCode = (rand() % 9999) + 1;        
    
    /* Asks the user for the technician's name directly from the terminal */
    printf("Enter the technician's name: ");
    readString(newTechnician->name, sizeof(newTechnician->name));
    
    /* Asks for the specialization */
    printf("Enter the specialization (a=PLUMBER, b=ELECTRICIAN, c=CONSTRUCTOR, d=TERMOHYDRAULIC, e=ELEVETOR, f=BLACKSMITH): ");
    
    
    /* Reads a single character directly from the standard input */
    newTechnician->specialization = getchar();
    
    /* Clears the buffer to remove the trailing newline (\n) left by the user pressing Enter */
    clearBuffer();
       
    newTechnician->availability = 1; // Default to available
    newTechnician->interventionCount = 0; 
    
    return newTechnician;
}

/* Frees the memory previously allocated for the given technician. */
void deleteTechnician(technician tech) {        
    if(tech != NULL)
        free(tech);            
}

/* Prints all the details and current status of the technician to the standard output. */
void printTechnician(const technician tech) {
    if(tech == NULL){
        printf("No technician to print\n");
        return;
    }

    printf("--- Technician Details ---\n");
    printf("ID Code: %d\n", tech->idCode);
    printf("Name: %s\n", tech->name);
    printf("Specialization: %c\n", tech->specialization); 
    
    if (tech->availability == 1) {
        printf("Status: Available\n");
    } else {
        printf("Status: Busy\n");
    }
    
    printf("Interventions completed: %d\n", tech->interventionCount);
    printf("----------------------\n");
}

/* Updates the availability status of the technician (1 for available, 0 for busy). */
void setAvailability(technician tech, int status) {
    if(tech != NULL){
        if(status == 0 || status == 1 ){
            tech->availability = status;
        } else{
            printf("Error: invalid status. Use 1 (Available) or 0 (Busy)\n");
        }
    }
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

/* Returns the current availability status of the technician. */
int getAvailability(technician tech) {
    if (tech == NULL) return -1;
    return tech->availability;
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
    if (tech == NULL) return 'z';
    return tech->specialization;
}