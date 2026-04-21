#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 #include "../include/tecnico.h"
 /* Definition of the data structure for the Technician */

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
    int disponibilita;        /* 1 = available, 0 = busy */
    int numeroInterventi;
}; 

tecnico creaTecnico(const char* nome, const char* specializzazione){
    tecnico nuovotecnico = (tecnico *)malloc(sizeof(tecnico)); // Dynamic memory allocation for the new technician

    if(nuovotecnico == NULL){                      
        printf("errore nell'allocazione della memoria per creare il tencico \n");       // Checks that the memory allocation was successful
        return NULL;
    }

    nuovotecnico->codiceIdentificativo = (rand() % 9999) + 1;        // Assignment of values
    //  TODO: add <time.h> to main and srand(time(NULL))
    
    strncpy(nuovotecnico->nome, nome , 49);
    nuovotecnico->nome[49] = '\0';

    strncpy(nuovotecnico->specializzazione, specializzazione, 49);
    nuovotecnico->specializzazione = '\0';

    nuovotecnico->disponibilita = 1;       // we assume by default that a new technician is available
    return nuovotecnico;
}
void eliminatecnico(tecnico t){        
    if( t != NULL)
    free(t);            // deallocation of the technician's memory
}
void stampatecnico(const tecnico t){
    if(t == NULL){
        printf("nessun tecnico da stampare");
        return;
    }

    printf("--- Scheda Tecnico ---\n");
    printf("Codice ID: %d\n", t->codiceIdentificativo);
    printf("Nome: %s\n", t->nome);
    printf("Specializzazione: %s\n", t->specializzazione);

    
    if (t->disponibilita == 1) {
        printf("Stato: Disponibile\n");
    } else {                                // prints the technician's availability in a textual format
        printf("Stato: Occupato\n");
    }
    printf("----------------------\n");
}
void impostaDisponibilita(tecnico t, int stato){
    if(t != NULL){
        if(stato == 0 || stato == 1 ){
            t->disponibilita = stato;
        } else{
            printf("Errore : stato non valido. Usare 1 (Disponibile) o 0 (Occupato)");
        }
    }
}


void aggiungiIntervento(tecnico t) {
    if (t != NULL) {
        t->numeroInterventi += 1;
    }
}


int getcodiceIdentificativo(tecnico t) {
    if (t == NULL) return -1;
    return t->codiceIdentificativo;
}


int getDisponibilita(tecnico t) {
    if (t == NULL) return -1;
    return t->disponibilita;
}


int getIntervento(tecnico t) {
    if (t == NULL) return -1;
    return t->numeroInterventi;
}


char getNome(tecnico t) {
    if (t == NULL) return 'z';
    return t->nome;
}


char getSpecializzazione(tecnico t) {
    if (t == NULL) return 'z';
    return t->specializzazione;
}