#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 #include "../include/tecnico.h"
Tecnico* creaTecnico(int codice, const char* nome, const char* specializzazione){
    Tecnico *nuovoTecnico = (Tecnico *)malloc(sizeof(Tecnico)); // Dynamic memory allocation for the new technician

    if(nuovoTecnico == NULL){                      
        printf("errore nell'allocazione della memoria per creare il tencico \n");       // Checks that the memory allocation was successful
        return NULL;
    }
    nuovoTecnico -> codiceIdentificativo = codice;        // Assignment of values
    
    strncpy(nuovoTecnico->nome, nome , 49);
    nuovoTecnico->nome[49] = '\0';

    strncpy(nuovoTecnico->specializzazione, specializzazione, 49);
    nuovoTecnico->specializzazione[49] = '\0';

    nuovoTecnico->disponibilita = 1;       // we assume by default that a new technician is available
    return nuovoTecnico;
}
void eliminaTecnico(Tecnico *t){        
    if( t != NULL)
    free(t);            // deallocation of the technician's memory
}
void stampaTecnico(const Tecnico *t){
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
void impostaDisponibilita(Tecnico *t, int stato){
    if(t != NULL){
        if(stato == 0 || stato == 1 ){
            t->disponibilita = stato;
        } else{
            printf("Errore : stato non valido. Usare 1 (Disponibile) o 0 (Occupato)");
        }
    }
}
void aggiungiIntervento(Tecnico *t) {
    if (t != NULL) {
        t->numeroInterventi += 1;
    }
}