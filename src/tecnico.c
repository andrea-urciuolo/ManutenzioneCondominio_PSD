#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 #include "../include/tecnico.h"
Tecnico* creaTecnico(int codice, const char* nome, const char* specializzazione){
    Tecnico *nuovoTecnico = (Tecnico *)malloc(sizeof(Tecnico)); //Allocazione dinamica della memoria per il nuovo tecnico

    if(nuovoTecnico == NULL){                      
        printf("errore nell'allocazione della memoria per creare il tencico \n");       //Verifica che l'allocazione della memoria sia andata a buon fine
        return NULL;
    }
    nuovoTecnico -> codiceIdentificativo = codice;        //Assegnazione dei valori
    
    strncpy(nuovoTecnico->nome, nome , 49);
    nuovoTecnico->nome[49] = '\0';

    strncpy(nuovoTecnico->specializzazione, specializzazione, 49);
    nuovoTecnico->specializzazione[49] = '\0';

    nuovoTecnico->disponibilita = 1;       //supponiamo di default che un nuovo tencico sia disponibile
    return nuovoTecnico;
}
void eliminaTecnico(Tecnico *t){        
    if( t != NULL)
    free(t);            //deallocazione della memoria del tecnico
}