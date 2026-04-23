#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tecnico.h"

#define PLUMBER 'a'
#define ELECTRICIAN 'b'
#define CONSTRUCTOR 'c'
#define TERMOHYDRAULIC 'd'
#define ELEVETOR 'e'
#define BLACKSMITH 'f'

struct c_tecnico {
    int codiceIdentificativo;   // code that identifies the technician
    char nome[50];
    char specializzazione;
    int disponibilita;          /* 1 = available, 0 = busy */
    int numeroInterventi;
}; 

/* Allocates memory and initializes a new technician with a random ID, given name, specialization, and default values. */
tecnico creaTecnico(const char* nome, char specializzazione){
    
    tecnico nuovotecnico = (tecnico)malloc(sizeof(struct c_tecnico)); 

    if(nuovotecnico == NULL){                      
        printf("Errore nell'allocazione della memoria per creare il tecnico \n");       
        return NULL;
    }

    nuovotecnico->codiceIdentificativo = (rand() % 9999) + 1;        
    // TODO: add <time.h> to main and srand(time(NULL))
    
    strncpy(nuovotecnico->nome, nome, 49);
    nuovotecnico->nome[49] = '\0';

   
    nuovotecnico->specializzazione = specializzazione;

    nuovotecnico->disponibilita = 1;       
    nuovotecnico->numeroInterventi = 0; 
    
    return nuovotecnico;
}

/* Frees the memory previously allocated for the given technician. */
void eliminaTecnico(tecnico t){        
    if( t != NULL)
        free(t);            
}

/* Prints all the details and current status of the technician to the standard output. */
void stampaTecnico(const tecnico t){
    if(t == NULL){
        printf("Nessun tecnico da stampare\n");
        return;
    }

    printf("--- Scheda Tecnico ---\n");
    printf("Codice ID: %d\n", t->codiceIdentificativo);
    printf("Nome: %s\n", t->nome);
    printf("Specializzazione: %c\n", t->specializzazione); // Usato %c per il singolo char
    
    if (t->disponibilita == 1) {
        printf("Stato: Disponibile\n");
    } else {                                
        printf("Stato: Occupato\n");
    }
    printf("Interventi effettuati: %d\n", t->numeroInterventi);
    printf("----------------------\n");
}

/* Updates the availability status of the technician (1 for available, 0 for busy). */
void impostaDisponibilita(tecnico t, int stato){
    if(t != NULL){
        if(stato == 0 || stato == 1 ){
            t->disponibilita = stato;
        } else{
            printf("Errore: stato non valido. Usare 1 (Disponibile) o 0 (Occupato)\n");
        }
    }
}

/* Increments the total number of interventions assigned to the technician by one. */
void aggiungiIntervento(tecnico t) {
    if (t != NULL) {
        t->numeroInterventi += 1;
    }
}

/* Returns the unique identification code of the technician. */
int getCodiceIdentificativo(tecnico t) {
    if (t == NULL) return -1;
    return t->codiceIdentificativo;
}

/* Returns the current availability status of the technician. */
int getDisponibilita(tecnico t) {
    if (t == NULL) return -1;
    return t->disponibilita;
}

/* Returns the total number of interventions currently assigned to or completed by the technician. */
int getIntervento(tecnico t) {
    if (t == NULL) return -1;
    return t->numeroInterventi;
}

/* Returns a pointer to the string containing the technician's name. */
const char* getNome(tecnico t) {
    if (t == NULL) return NULL;
    return t->nome;
}

/* Returns the character representing the technician's specific area of expertise. */
char getSpecializzazione(tecnico t) {
    if (t == NULL) return 'z';
    return t->specializzazione;
}